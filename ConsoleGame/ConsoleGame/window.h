#ifndef WINDOW_H
# define WINDOW_H

class Window
{
private:
	Window():w(800), h(500) {};
	int w;
	int h;

public:
	static Window *getInstance() {
		static Window instance;
		return &instance;
	}
	int getWidth() {
		return w;
	}
	int getHeight() {
		return h;
	}
	void setWidth(int w) {
		this->w = w;
	}
};

#endif