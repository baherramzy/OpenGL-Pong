#ifndef QUAD_T
#define QUAD_T

#include "Vertex2.h"
#include <algorithm>

// Quad is a utility class for drawing rectangle-shaped objects

class Quad
{
private:
	int width, height;
	Vertex2 vertices[4];
	void createQuad();
public:
	Quad(float, float, int, int);
	void draw();
	void AddX(float);
	void AddY(float);
	float getLeft();
	float getRight();
	float getBottom();
	float getTop();
	~Quad();
};

#endif