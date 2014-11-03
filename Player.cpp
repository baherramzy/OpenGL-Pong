#include "Player.h"

// Note: Explicit use of the 'this' pointer is normally not required 
// to access base class methods, however in this case, not using 
// the 'this' pointer results in both players being drawn in the same place
// despite being separate objects constructed correctly with separate address spaces. 
// Possibly a compiler optimization side effect?

Player::Player(float x, float y) : x(x), y(y) {
	this->Quad::Quad(x, y);
}

void Player::draw() {
	this->Quad::draw();
}

void Player::moveUp(float s) {
	this->Quad::AddY(s);
	y = this->Quad::getBottom();
}

void Player::moveDown(float s) {
	this->Quad::AddY(-s);
	y = this->Quad::getBottom();
}

Player::~Player() {}