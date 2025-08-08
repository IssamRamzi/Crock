#include "Window.hpp"

void resize(GLFWwindow* window, int width, int height);

//bool Window::m_keys[MAX_KEYS];
//bool Window::m_mouseButtons[MAX_MOUSE_BUTTONS];
//double Window::m_mouseX, Window::m_mouseY;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Window* currentWIndow = (Window *) glfwGetWindowUserPointer(window);
	if (key >= 0 && key < MAX_KEYS)
		currentWIndow->m_keys[key] = (action != GLFW_RELEASE);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	Window* currentWIndow = (Window*)glfwGetWindowUserPointer(window);
	if (button >= 0 && button < MAX_MOUSE_BUTTONS) {
		currentWIndow->m_mouseButtons[button] = (action != GLFW_RELEASE);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* currentWIndow = (Window*)glfwGetWindowUserPointer(window);
	currentWIndow->m_mouseX = xpos;
	currentWIndow->m_mouseY = ypos;
}

void mouse_scroll_callback(GLFWwindow *window, double xoffset, double yoffset){
	Window *currentWindow = (Window*)glfwGetWindowUserPointer(window);
	currentWindow->m_mouseScroll +=yoffset;
	if(currentWindow->m_mouseScroll < 0) currentWindow->m_mouseScroll = 0;
	std::cout << "Scrolling : " << currentWindow->m_mouseScroll << std::endl;
	
}

Window::Window(std::string title, int width, int height) {
	m_title = title;
	m_height = height;
	m_width = width;


	for (int i = 0; i < MAX_KEYS; i++) {
		m_keys[i] = false;
	}
	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
		m_mouseButtons[i] = false;
	}
}

Window::~Window() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

bool Window::Init() {

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW !" << std::endl;
		return false;
	}else {
		std::cout << "Success initializing GLFW" << std::endl;
	}
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	if (!m_window) {
		glfwTerminate();
		std::cout << "Failed to create a window" << std::endl;
		return false;
	}
	glfwWindowHint( GLFW_SAMPLES, 8 );
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, resize);
	glfwSetKeyCallback(m_window, key_callback);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	glfwSetScrollCallback(m_window, mouse_scroll_callback);

	if (!gladLoadGL()) {
		std::cerr << "Failed to initialize GLAD!" << std::endl;
		return false;
	}

	glfwSetWindowUserPointer(m_window, this);
	int max_height = 1080;
	int max_width = 1920;
	glfwSetWindowMonitor(m_window, NULL, (max_width/2)-(m_width/2), (max_height/2) - (m_height/2), m_width, m_height, GLFW_DONT_CARE);

	return true;
}

bool Window::Closed() const{
	return glfwWindowShouldClose(m_window);
}

void Window::ClearColor(int r, int g, int b, int a) {
    glClearColor((float)r / 255,(float)g / 255,(float)b / 255,(float)a / 255);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void resize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::Update() {
	glfwPollEvents();
	glfwGetFramebufferSize(m_window, &m_width, &m_height);
	glfwSwapBuffers(m_window);
}



bool Window::IsKeyPressed(unsigned int keycode) {
	if (keycode > MAX_KEYS) return false;
	else return m_keys[keycode];
}

bool Window::IsMousePressed(unsigned int button) {
	if (button >= MAX_MOUSE_BUTTONS) return false;
	return m_mouseButtons[button];
}

void Window::resetInput() {
	for (int i = 0; i < MAX_KEYS; i++) {
		m_keys[i] = false;
	}
	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
		m_mouseButtons[i] = false;
	}
}

Vec2<float> Window::GetMousePos() {
	return Vec2<float>(m_mouseX, m_mouseY);
}

double Window::GetMouseScroll(){
	return m_mouseScroll;
}