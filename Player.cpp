#ifndef PLAYER_T
#define PLAYER_T

#include "Quad.cpp"

class Player
{
private:
	Quad p;

public:
	GLfloat x, y;
	int width = 10, height = 80;
	Player() {
		p.createQuad(10.0, 10.0);
	}

	Player(GLfloat x, GLfloat y) : x(x), y(y) {
		p.createQuad(x, y);
	}

	void draw() {
		p.draw();
	}

	void moveUp(GLfloat s) {
		p.AddY(s);
		y = p.getY();
	}

	void moveDown(GLfloat s) {
		p.AddY(-s);
		y = p.getY();
	}

	~Player() {
		
	}
};

#endif