#include "score.h"
#include <string>

Score::Score() {}

void Score::setPlayerScore(int score) {
	this->playerScore = score;
}

int Score::getPlayerScore() {
	return this->playerScore;
}

void Score::setCpuScore(int score) {
	this->cpuScore = score;
}

int Score::getCpuScore() {
	return this->cpuScore;
}

void Score::drawScore() {
	DrawText(std::to_string(this->playerScore).c_str(), 1000/4 - 50, 100, this->fontSize, RAYWHITE);
	DrawText(std::to_string(this->cpuScore).c_str(), 1000 - 1000/4 - 50, 100, this->fontSize, RAYWHITE);
}