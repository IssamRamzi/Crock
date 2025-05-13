#include "graphics/Window.hpp"
#include <iostream>

#include "../CrockMath/CrockMath.h"
#include "graphics/Shader.h"

int main() {
	Window window("Crock", 960, 540);
	glClearColor(0.2, 0.2, 0.8, 1.0);
	std::cout << "Open GL Version" << glGetString(GL_VERSION) << std::endl;

	float vertices[] = {
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0,
		12, 3, 0,

	};

	GLuint vbo, vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	Matrix4<float> ortho = Matrix4<float>::orthographic(0, 16, 0, 9, -1, 1);

	Shader shader("../src/CrockEngine/shaders/b.vert", "../src/CrockEngine/shaders/b.frag");
	shader.enableShader();
	// glUniformMatrix4fv(glGetUniformLocation(shader.getShaderID(), "pr_matrix"), 1, false, ortho.data);
	shader.setUniformMat4("pr_matrix", ortho);
	// shader.setUniformMat4("ml_matrix", Matrix4<float>::rotation(45.f, Vec3<float>(0.f,0.f,1.f)));
	Vec4<float> newColor(0.5f, 1.f, 0.5f, 1.f);
	shader.setUniform4f("colour",newColor);
	Vec2<float> light(8, 4.5f);
	shader.setUniform2f("light_int",light);
	shader.setUniform1f("int_l", 0.1);

	while (!window.closed()) {
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}
