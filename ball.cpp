#include "ball.h"
#include <iostream>


Ball::Ball(Vector2 pos) {
	this->position = pos;
}

Vector2 Ball::getPosition() {
	return this->position;
}

Vector2 Ball::getDirection() {
	return this->direction;
}

void Ball::move(Vector2 playerPosition, Vector2 cpuPosition,float dt, int playerH, int playerW, Score& score) {
	// Collision with the player
	if ((playerPosition.x + playerW >= this->position.x && playerPosition.x <= this->position.x) && (playerPosition.y <= this->position.y && playerPosition.y + playerH >= this->position.y)) {
		this->direction.x *= -1;
		// this->acceleration += 0.1;
	}
		

	// Collision with the cpu
	if ((cpuPosition.x + playerW >= this->position.x - playerW && cpuPosition.x <= this->position.x) && (cpuPosition.y <= this->position.y && cpuPosition.y + playerH >= this->position.y)) {
		this->direction.x *= -1;
		// this->acceleration += 0.1;
	}
		
	// Collision with top and bottom
	if (this->position.y <= 0 || this->position.y + this->height >= 700) this->direction.y *= -1;

	// Collision with left side
	if (this->position.x <= 0) {
		int s = score.getCpuScore();
		score.setCpuScore(s + 1);

		// Centering the ball
		this->position.x = 1000 / 2;
		this->position.y = 700 / 2;

		// switching direction
		this->direction.x *= -1;
		this->direction.y *= -1;

	}

	// Collision with right side
	if (this->position.x >= 1000) {
		int s = score.getPlayerScore();
		score.setPlayerScore(s + 1);

		// Centering the ball
		this->position.x = 1000 / 2;
		this->position.y = 700 / 2;

		// switching direction
		this->direction.x *= -1;

	}

	this->position.x += this->acceleration * dt * this->direction.x;
	this->position.y += this->acceleration *  dt * this->direction.y;
}

void Ball::drawBall() {
	// DrawCircle(this->position.x, this->position.y, this->radius, RAYWHITE);
	DrawRectangle(static_cast<int>(this->position.x), static_cast<int>(this->position.y), this->width, this->height, RAYWHITE);
}