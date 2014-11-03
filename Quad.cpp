#include "Quad.h"

Quad::Quad(float x = 0.0, float y = 0.0, int width = 10, int height = 80)
	: width(width), height(height) {

	for (Vertex2 v : vertices) {
		v = Vertex2(0, 0);
	}

	vertices[0].x = x; vertices[0].y = y;
	vertices[1].x = vertices[0].x + width; vertices[1].y = vertices[0].y;
	vertices[2].x = vertices[1].x; vertices[2].y = vertices[1].y + height;
	vertices[3].x = vertices[0].x; vertices[3].y = vertices[2].y;
}

void Quad::draw() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 4; ++i) {
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();
}

void Quad::AddX(float dx) {
	for (int i = 0; i < 4; ++i) {
		vertices[i].x += dx;
	}
}

void Quad::AddY(float dy) {
	for (int i = 0; i < 4; ++i) {
		vertices[i].y += dy;
	}
}

float Quad::getLeft() {
	return vertices[0].x;
}

float Quad::getRight() {
	return vertices[1].x;
}

float Quad::getBottom() {
	return vertices[0].y;
}

float Quad::getTop() {
	return vertices[2].y;
}
Quad::~Quad() {}