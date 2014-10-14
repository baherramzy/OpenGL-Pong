#ifndef VERTEX2_T
#define VERTEX2_T

#include <GL\freeglut.h>

struct Vertex2 {
	GLfloat x;
	GLfloat y;

	Vertex2(GLfloat X = 0.0, GLfloat Y = 0.0) : x(X), y(Y) {}
};

#endif