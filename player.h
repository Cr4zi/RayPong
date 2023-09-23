#pragma once

#include "raylib.h"

class Player {
private:
	Vector2 position{};
	int width{ 10 };
	int height{ 50 };

public:
	// Constructor
	Player(Vector2 pos);

	// Getter and Setter
	Vector2 getPosition();
	void setPosition(Vector2 pos);

	int getWidth();
	int getHeight();

	void move();
	void drawPlayer();
};