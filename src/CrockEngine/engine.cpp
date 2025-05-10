#include "graphics/Window.hpp"
#include <iostream>
#include "../CrockMath/CrockMath.h"

int main(void) {
// #if 0
	Window window("Crock", 960, 540);
	glClearColor(0.2, 0.2, 0.8, 1.0);
	std::cout << "Open GL Version" << glGetString(GL_VERSION) << std::endl;


	while (!window.closed()) {
		if (window.isKeyPressed(GLFW_KEY_Q)) {
			std::cout << "A Pressed" << std::endl;
		}
		
		if (window.isMousePressed(GLFW_MOUSE_BUTTON_LEFT)) {
			// std::cout << "Mouse1 Pressed" << std::endl;
			window.printMousePos();
		}

		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2d(0.5, -0.5);
		glVertex2d(0, 0.5);
		glVertex2d(-0.5, -0.5);
		glEnd();


		window.update();
	}
// #endif

	/*Matrix<4, 4, int> mat = Matrix<4,4,int>::identity();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << mat.data[i][j];
		}
		std::cout << '\n';
	}*/

	Matrix3<int> mat(1);
	Matrix3<int> mat2(2);
	mat = mat * mat2;
	for (int i = 0; i < 3 * 3; i++) {
		std::cout << mat.data[i] << " ";
		if ((i + 1) % 3 == 0) std::cout << '\n';
	}

	return 0;
}
