#pragma once
#include <glad/glad.h>	
#include <GLFW/glfw3.h>

#include <iostream>
#include "CrockMath.h"
#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 10

class Window
{
private:
	int 			m_height, m_width;
	std::string 	m_title;

	GLFWwindow* 	m_window;
	bool 			m_isClosed;


	bool 			m_keys[MAX_KEYS];
	bool 			m_mouseButtons[MAX_MOUSE_BUTTONS];
	double 			m_mouseX, m_mouseY, m_mouseScroll = 0;

public:
	Window(std::string title, int width, int height);
	~Window();
	


	bool 			Init();
	void 			ClearColor(int r, int g, int b, int a);
	bool 			Closed() const;
	void 			Update();
	bool 			IsKeyPressed(unsigned int keycode);
	bool 			IsMousePressed(unsigned int button);
	Vec2<float> 	GetMousePos();
	double			GetMouseScroll();

	inline int		GetWindowHeight(){return m_height;}
	inline int		GetWindowWidth(){return m_width;}



	friend void 	cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	friend void 	mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void 	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void 	mouse_scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

private:

	void resetInput();
};
