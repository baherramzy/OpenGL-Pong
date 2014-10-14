#ifndef QUAD_T
#define QUAD_T

#include "Vertex2.h"
#include <algorithm>

class Quad {
private:
	Vertex2 vertices[4];
public:
	Quad() {
		for (Vertex2 v : vertices) {
			v = Vertex2(0.0, 0.0);
		}
	}

	void draw() {
		glBegin(GL_QUADS);
		for (int i = 0; i < 4; ++i) {
			glVertex2f(vertices[i].x, vertices[i].y);
		}
		glEnd();
	}

	void createQuad(GLfloat x = 0.0, GLfloat y = 0.0, int width = 10, int height = 80) {
		// Create
		vertices[0].x = x; vertices[0].y = y;
		vertices[1].x = vertices[0].x + width; vertices[1].y = vertices[0].y;
		vertices[2].x = vertices[1].x; vertices[2].y = vertices[1].y + height;
		vertices[3].x = vertices[0].x; vertices[3].y = vertices[2].y;
	}

	void AddX(GLfloat dx) {
		for (int i = 0; i < 4; ++i) {
			vertices[i].x += dx;
		}
	}

	void AddY(GLfloat dy) {
		for (int i = 0; i < 4; ++i) {
			vertices[i].y += dy;
		}
	}

	GLfloat getX() {
		return vertices[0].x;
	}

	GLfloat getY() {
		return vertices[0].y;
	}

	~Quad() {}
};

#endif