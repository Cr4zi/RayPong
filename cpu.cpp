#include "cpu.h"

Cpu::Cpu(Vector2 pos) {
	this->position = pos;
}

Vector2 Cpu::getPosition() {
	return this->position;
}

void Cpu::move(Vector2 ballPosition, Vector2 ballDirection) {
	if (ballDirection.x < 0) return;
	this->position.y = ballPosition.y - (this->height/2);
}

void Cpu::drawCpu() {
	DrawRectangle(static_cast<int>(this->position.x), static_cast<int>(this->position.y), this->width, this->height, RAYWHITE);
}