#include "Window.hpp"

void resize(GLFWwindow* window, int width, int height);

//bool Window::_keys[MAX_KEYS];
//bool Window::_mouseButtons[MAX_MOUSE_BUTTONS];
//double Window::mouseX, Window::mouseY;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Window* currentWIndow = (Window *) glfwGetWindowUserPointer(window);
	if (key >= 0 && key < MAX_KEYS)
		currentWIndow->_keys[key] = (action != GLFW_RELEASE);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	Window* currentWIndow = (Window*)glfwGetWindowUserPointer(window);
	if (button >= 0 && button < MAX_MOUSE_BUTTONS) {
		currentWIndow->_mouseButtons[button] = (action != GLFW_RELEASE);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* currentWIndow = (Window*)glfwGetWindowUserPointer(window);
	currentWIndow->mouseX = xpos;
	currentWIndow->mouseY = ypos;
}


Window::Window(char* title, int width, int height) {
	_title = title;
	_height = height;
	_width = width;

	init();

	for (int i = 0; i < MAX_KEYS; i++) {
		_keys[i] = false;
	}
	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
		_mouseButtons[i] = false;
	}

}

Window::~Window() {
	glfwDestroyWindow(_window);
	glfwTerminate();
}

bool Window::init() {

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW !" << std::endl;
		return false;
	}else {
		std::cout << "Success initializing GLFW" << std::endl;
	}



	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if (!_window) {
		glfwTerminate();
		std::cout << "Failed to create a window" << std::endl;
		return false;
	}
	glfwWindowHint( GLFW_SAMPLES, 8 );

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, resize);
	glfwSetKeyCallback(_window, key_callback);
	glfwSetMouseButtonCallback(_window, mouse_button_callback);
	glfwSetCursorPosCallback(_window, cursor_position_callback);

	if (!gladLoadGL()) {
		std::cerr << "Failed to initialize GLAD!" << std::endl;
		return false;
	}

	glfwSetWindowUserPointer(_window, this);

	return true;
}

bool Window::closed() const{
	return glfwWindowShouldClose(_window);
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void resize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::update() {
	glfwPollEvents();
	glfwGetFramebufferSize(_window, &_width, &_height);
	glfwSwapBuffers(_window);
}



bool Window::isKeyPressed(unsigned int keycode) {
	if (keycode > MAX_KEYS) return false;
	else return _keys[keycode];
}

bool Window::isMousePressed(unsigned int button) {
	if (button >= MAX_MOUSE_BUTTONS) return false;
	return _mouseButtons[button];
}

void Window::resetInput() {
	for (int i = 0; i < MAX_KEYS; i++) {
		_keys[i] = false;
	}
	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
		_mouseButtons[i] = false;
	}
}

Vec2<float> Window::getMousePos() {
	return Vec2<float>(mouseX, mouseY);
}