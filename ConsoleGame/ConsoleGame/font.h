#ifndef FONT_H
# define FONT_H

class Font
{
private:
	float x;
	float y;
	float z;
	float size;
	float bold;

public:
	Font(float x_, float y_, float z_, float size_, float bold_) : x(x_), y(y_), z(z_), size(size_), bold(bold_)
	{}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getZ() {
		return z;
	}
	float getSize() {
		return size;
	}
	float getBold() {
		return bold;
	}
};

#endif