#include "Player.h"

Player::Player(float x, float y) : x(x), y(y) {
	p.createQuad(x, y);
}

void Player::draw() {
	p.draw();
}

void Player::moveUp(float s) {
	p.AddY(s);
	y = p.getY();
}

void Player::moveDown(float s) {
	p.AddY(-s);
	y = p.getY();
}

Player::~Player() {

}