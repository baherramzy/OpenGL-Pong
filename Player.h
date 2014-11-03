#ifndef PLAYER_T
#define PLAYER_T

#include "Quad.cpp"

// Player class represents the racket, responsible for its movement

class Player : public Quad
{
public:
	float x, y;
	const int width = 10, height = 80;
	
	Player(float, float);
	void draw();
	void moveUp(float);
	void moveDown(float);
	~Player();
};

#endif