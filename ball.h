#pragma once

#include "raylib.h"
#include "score.h"

class Ball {
private:
	Vector2 position{};
	int width{ 8 };
	int height{ 8 };
	Vector2 direction{ -300, 105 };
	float acceleration{ 1 };

public:
	// Constructor
	Ball(Vector2 pos);

	Vector2 getPosition();
	Vector2 getDirection();

	void move(Vector2 playerPosition, Vector2 cpuPosition, float dt, int playerH, int playerW, Score& score);
	void drawBall();
};
