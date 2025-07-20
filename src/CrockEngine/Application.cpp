#include "Application.hpp"
#include "graphics/Shader.h"
#include "graphics/buffers/Buffer.h"
#include "graphics/buffers/VertexArray.h"
#include "graphics/buffers/IndexBuffer.h"
#include "graphics/Texture2D.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <filesystem>

const std::string SHADERS_SOURCE = "";
const std::string TEXTURES_SOURCE = "";

Application::Application(int width, int height, std::string title) : m_width(width), m_height(height), m_title(title) {
	std::cout << std::filesystem::current_path() << std::endl;
}

int Application::Init() {
	m_window = new Window(m_title.c_str(), m_width, m_height);
	if (!m_window->Init()) {
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	GLfloat vertices[] = {
    	// Position            // Texture Coords
    	-0.5f, -0.5f, -0.5f,   0.0f, 0.0f,  // 0: Bottom-left back
    	 0.5f, -0.5f, -0.5f,   1.0f, 0.0f,  // 1: Bottom-right back
    	 0.5f, -0.5f,  0.5f,   1.0f, 1.0f,  // 2: Bottom-right front
    	-0.5f, -0.5f,  0.5f,   0.0f, 1.0f,  // 3: Bottom-left front
		
    	 0.0f,  0.5f,  0.0f,   0.5f, 0.5f   // 4: Top center
	};

	GLuint indices[] = {
		// Base (2 triangles)
		0, 1, 2,
		0, 2, 3,
		
		// Front 
		3, 2, 4,
		
		// Right   
		2, 1, 4,
		
		// Back 
		1, 0, 4,
		
		// Left 
		0, 3, 4
	};

	VertexArray* VAO = new VertexArray();
	Buffer* VBO = new Buffer(vertices, sizeof(vertices), 5); // 5 floats per vertex
	IndexBuffer* EBO = new IndexBuffer(indices, sizeof(indices) / sizeof(GLuint));

	VAO->AddBuffer(VBO, 0, 3, 5 * sizeof(float), 0); // position
	VAO->AddBuffer(VBO, 1, 2, 5 * sizeof(float), (void*)(3 * sizeof(float))); // tex coords

	Shader shader("../src/CrockEngine/shaders/basic.vert", "../src/CrockEngine/shaders/basic.frag");
	Texture2D wallTexture("wall.jpg");

	shader.EnableShader();
	shader.SetUniform1i("texCoord", 0);
	wallTexture.Bind();

	float Hangle = 10.0f, Vangle = 0, zoom = -5.0f;

	double prevTime = glfwGetTime();
	float rotationSpeed = 45.0f;

	glm::vec3 pyramidsPosition[] = {
		glm::vec3( 0.0f,  0.0f,  0.0f), 
		glm::vec3( 2.0f,  5.0f, -15.0f), 
		glm::vec3(-1.5f, -2.2f, -2.5f),  
		glm::vec3(-3.8f, -2.0f, -12.3f),  
		glm::vec3( 2.4f, -0.4f, -3.5f),  
		glm::vec3(-1.7f,  3.0f, -7.5f),  
		glm::vec3( 1.3f, -2.0f, -2.5f),  
		glm::vec3( 1.5f,  2.0f, -2.5f), 
		glm::vec3( 1.5f,  0.2f, -1.5f), 
		glm::vec3(-1.3f,  1.0f, -1.5f)  
	};

	glm::vec2 cam(0.0, -5.0);
	while (!m_window->Closed()) {
		double currentTime = glfwGetTime();
		double deltaTime = currentTime - prevTime;
		prevTime = currentTime;
		// std::cout << deltaTime << std::endl;

		// Camera controls
		if (m_window->IsKeyPressed(GLFW_KEY_UP))    cam.y += 3.0f * deltaTime;
		if (m_window->IsKeyPressed(GLFW_KEY_DOWN))  cam.y -= 3.0f * deltaTime;;
		if (m_window->IsKeyPressed(GLFW_KEY_RIGHT)) cam.x += 5.0f * deltaTime;
		if (m_window->IsKeyPressed(GLFW_KEY_LEFT))  cam.x -= 5.0f * deltaTime;


		Hangle += rotationSpeed * deltaTime;
		Vangle += rotationSpeed * 0.5f * deltaTime; 

		m_window->Update();
		m_window->ClearColor(0, 101, 248, 255);

		VAO->Bind();
		EBO->Bind();
		shader.EnableShader();

		// Camera and Projection
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(cam.x, 0, cam.y));
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)m_width / (float)m_height, 0.1f, 100.0f);
		shader.SetUniformMat4GLM("view", view);
		shader.SetUniformMat4GLM("proj", projection);

		for (unsigned int i = 0; i < 10; i++) {
			glm::mat4 model = glm::translate(glm::mat4(1.0f), pyramidsPosition[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle + Vangle), glm::vec3(0.0f, 1.0f, 0.5f));
			model = glm::rotate(model, glm::radians(angle + Hangle), glm::vec3(1.0f, 0.0f, 0.5f));
			shader.SetUniformMat4GLM("model", model);

			glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);
		}

		shader.DisableShader();
		EBO->Unbind();
		VAO->Unbind();
	}

	delete VAO;
	delete VBO;
	delete EBO;

	return 0;
}
