#ifndef PLAYER_T
#define PLAYER_T

#include "Quad.cpp"

class Player 
{
private:
	Quad p;

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