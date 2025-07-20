#include "graphics/Window.hpp"


class Application {
public:
	Application(int width, int height, std::string title);
	int Init();
	void Run();
	void Stop();
private:
	int m_width, m_height;
	std::string m_title;
	Window *m_window;
private:

};