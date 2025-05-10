#include <glad/glad.h>	
#include <GLFW/glfw3.h>

#include <iostream>


#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 10

class Window
{


private:
	int _height, _width;
	char* _title;

	GLFWwindow* _window;
	bool _isclosed;


	bool _keys[MAX_KEYS];
	bool _mouseButtons[MAX_MOUSE_BUTTONS];
	double mouseX, mouseY;

public:
	Window(char* title, int height, int width);
	~Window();
	

	
	void clear();
	bool closed() const;
	void update();
	bool isKeyPressed(unsigned int keycode);
	bool isMousePressed(unsigned int button);
	void printMousePos();



	friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


private:
	bool init();

	void resetInput();

};
