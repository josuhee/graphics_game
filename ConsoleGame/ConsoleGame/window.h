#ifndef WINDOW_H
# define WINDOW_H

class Window
{
private:
	Window() :w(800), h(500), mode(1), fixed(1.6f), aspect(1.6f) {};
	int w;
	int h;
	int mode;
	float fixed;
	float aspect;

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
	float getFixed() {
		return fixed;
	}
	float getAspect() {
		return aspect;
	}
	void setWidth(int w) {
		this->w = w;
	}
	void setHeight(int h) {
		this->h = h;
	}
	void setMode(int mode) {
		this->mode = mode;
	}
	void setAspect(float aspect) {
		this->aspect = aspect;
	}
};

#endif