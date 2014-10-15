#ifndef QUAD_T
#define QUAD_T

#include "Vertex2.h"
#include <algorithm>

class Quad
{
private:
	Vertex2 vertices[4];
public:
	Quad();
	void draw();
	void createQuad(float, float, int, int);
	void AddX(float);
	void AddY(float);
	float getX();
	float getY();
	~Quad();

};

#endif