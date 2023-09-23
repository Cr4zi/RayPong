#include "player.h"
#include <iostream>

// Constructor
Player::Player(Vector2 pos) {
	this->position = pos;
}

// Getter
Vector2 Player::getPosition() {
	return this->position;
}

int Player::getHeight() {
	return this->height;
}

int Player::getWidth() {
	return this->width;
}

// Setter
void Player::setPosition(Vector2 pos) {
	this->position = pos;
}

void Player::move() {
	if (IsKeyDown(KEY_DOWN)) this->position.y += 10;
	if (IsKeyDown(KEY_UP)) this->position.y -= 10;
}

void Player::drawPlayer() {
	if (this->position.y < 0) this->position.y = 1;
	if (this->position.y > (700 - this->height)) this->position.y = 699 - this->height;

	DrawRectangle(static_cast<int>(this->position.x), static_cast<int>(this->position.y), this->width, this->height, RAYWHITE);
}