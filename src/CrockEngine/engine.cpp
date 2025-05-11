#include "graphics/Window.hpp"
#include <iostream>
#include "graphics/Shader.h"

int main(void) {
	Window window("Crock", 960, 540);
	glClearColor(0.2, 0.2, 0.8, 1.0);
	std::cout << "Open GL Version" << glGetString(GL_VERSION) << std::endl;


	Shader shader("../src/CrockEngine/shaders/b.vert", "../src/CrockEngine/shaders/b.frag");
	while (!window.closed()) {
		double curr_s = glfwGetTime(); // Get the current time.


		window.clear();
		int time_loc = glGetUniformLocation( shader.getShader(), "time" );
		// assert( time_loc > -1 ); // NB. include assert.h for assert().

		shader.enableShader();
		glUniform1f( time_loc, (float)curr_s );

		glBegin(GL_TRIANGLES);
		glVertex2d(0.5, -0.5);
		glVertex2d(0, 0.5);
		glVertex2d(-0.5, -0.5);
		glEnd();


		window.update();
	}

	return 0;
}
