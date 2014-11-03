#ifndef VERTEX2_T
#define VERTEX2_T

#include <GL\freeglut.h>

// Simple vertex structure to represent vertices.
// Preferred over OpenGL defined vertex types for simplicity.

struct Vertex2 {
	float x;
	float y;

	Vertex2(float X = 0.0, float Y = 0.0) : x(X), y(Y) {}
};

#endif