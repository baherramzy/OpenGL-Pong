#include "Player.h"

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