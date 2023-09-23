#pragma once
#include "raylib.h"

class Score {
private:
	int playerScore{ 0 };
	int cpuScore{ 0 };
	int fontSize{ 80 };
public:
	Score();

	void setPlayerScore(int score);
	int getPlayerScore();

	void setCpuScore(int score);
	int getCpuScore();

	void drawScore();
};