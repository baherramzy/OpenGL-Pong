#ifndef PONG_T
#define PONG_T

#include "Player.cpp"
#include <string>

class Pong
{
private:
	Player P1, P2;
	int score_l = 0, score_r = 0;
	Quad *ball;
	int GameWidth, GameHeight;
	float racket_speed = 3.0f;
	float ball_x, ball_y;
	float ball_dir_x, ball_dir_y;
	float ball_temp_x, ball_temp_y; // for dx, dy calculations
	int ballSize = 8;
	float ballSpeed = 3.0f;

public:
	Pong(int, int);
	void draw();
	void updateBall();
	void play();
	~Pong();
};

#endif