#ifndef WINDOW_H
# define WINDOW_H

class Window
{
private:
	Window():w(800), h(500), mode(1) {};
	int w;
	int h;
	int mode;

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
	int getMode() {
		return mode;
	}
	void setWidth(int w) {
		this->w = w;
	}
};

#endif