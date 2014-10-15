#ifndef VERTEX2_T
#define VERTEX2_T

#include <GL\freeglut.h>

struct Vertex2 {
	float x;
	float y;

	Vertex2(float X = 0.0, float Y = 0.0) : x(X), y(Y) {}
};

#endif