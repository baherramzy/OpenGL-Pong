#include "Pong.h"

Pong::Pong(int screenWidth, int screenHeight) : GameWidth(screenWidth), GameHeight(screenHeight) {
	// Players
	P1 = new Player(10.0f, 10.0f);
	P2 = new Player(float(screenWidth - P1->width - 10), float(10));

	// Ball
	ball_x = (float) GameWidth / 2;
	ball_y = (float) GameHeight / 2;
	ball_dir_x = -1.0f;
	ball_dir_y = 0.0f;

	ball = new Quad();
	ball->createQuad(ball_x, ball_y, ballSize, ballSize);
}

void Pong::draw() {
	// Draw rackets
	P1->draw();
	P2->draw();

	// Draw ball
	ball->draw();

	// Draw score
	std::string s = std::to_string(score_l) + ":" + std::to_string(score_r);
	glRasterPos2f(float(GameWidth / 2 - 10), float(GameHeight - 15));
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)s.c_str());
}

void Pong::updateBall() {
	ball_temp_x = ball_x;
	ball_temp_y = ball_y;

	ball_x += (int)(ball_dir_x * ballSpeed);
	ball_y += (int)(ball_dir_y * ballSpeed);

	ball->AddX(ball_x - ball_temp_x);
	ball->AddY(ball_y - ball_temp_y);

	// In case of collision, set ball direction based on where racket was hit
	// Ball y-direction: 0.5 if top half, 0 if center, -0.5 if bottom half

	// Left player collision check
	if (ball_x < P1->x + P1->width && ball_x > P1->x
		&& ball_y < P1->y + P1->height && ball_y > P1->y) {

		ball_dir_x = fabs(ball_dir_x); // Make x direction positive to send the ball flying right
		ball_dir_y = ((ball_y - P1->y) / P1->height) - 0.5f;;
	}

	// Right player collision check
	if (ball_x + ballSize > P2->x && ball_x + ballSize < P2->x + P2->width
		&& ball_y < P2->y + P2->height && ball_y > P2->y) {

		ball_dir_x = -fabs(ball_dir_x); // Make x direction negative to send the ball flying left
		ball_dir_y = ((ball_y - P2->y) / P2->height) - 0.5f;
	}

	// Left wall collision check
	if (ball_x < 0) {
		// Increment right player score and reset ball
		++score_r;
		ball_x = (float) GameWidth / 2;
		ball_y = (float) GameHeight / 2;
		ball_dir_x = 1.0f;
		ball_dir_y = 0.0f;

		delete ball;
		ball = new Quad();
		ball->createQuad(ball_x, ball_y, ballSize, ballSize);
	}

	// Right wall collision check
	if (ball_x + ballSize > GameWidth) {
		// Increment left player score and reset ball
		++score_l;
		ball_x = (float) GameWidth / 2;
		ball_y = (float) GameHeight / 2;
		ball_dir_x = -1.0f;
		ball_dir_y = 0.0f;

		delete ball;
		ball = new Quad();
		ball->createQuad(ball_x, ball_y, ballSize, ballSize);
	}

	// Top wall collision check
	if (ball_y + ballSize > GameHeight) {
		// Reverse y-direction to send ball flying downwards
		ball_dir_y = -fabs(ball_dir_y);
	}

	// Bottom wall collision check
	if (ball_y < 0) {
		// Reverse y-direction to send ball flying upwards
		ball_dir_y = fabs(ball_dir_y);
	}
}

void Pong::play() {
	updateBall();

	//Virtual keycodes: http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx
	if (GetAsyncKeyState(0x57) && P1->y + P1->height < GameHeight) // left - move up 
		P1->moveUp(racket_speed);
	else if (GetAsyncKeyState(0x53) && P1->y > 0) // left - move down
		P1->moveDown(racket_speed);

	if (GetAsyncKeyState(VK_UP) && P2->y + P2->height < GameHeight) // right - move up
		P2->moveUp(racket_speed);
	else if (GetAsyncKeyState(VK_DOWN) && P2->y > 0) // right - move down
		P2->moveDown(racket_speed);
}

Pong::~Pong() {
	delete P1, P2, ball;
}