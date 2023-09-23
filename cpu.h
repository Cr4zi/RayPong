#pragma once
#include "raylib.h"

class Cpu {
private:
	Vector2 position{};
	int width{ 10 };
	int height{ 50 };
public:
	Cpu(Vector2 pos);

	Vector2 getPosition();

	void move(Vector2 ballPosition, Vector2 ballDirection);
	void drawCpu();
};