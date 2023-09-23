#include <iostream>
#include "raylib.h"
#include "player.h"
#include "cpu.h"
#include "ball.h"
#include "score.h"

constexpr int HEIGHT = 700;
constexpr int WIDTH = 1000;

void drawMiddle();

int main() {
    InitWindow(WIDTH, HEIGHT, "Raylib pong");

    Vector2 playerPostion{ (float)50, (float)HEIGHT / 2 };
    Player player(playerPostion);

    Vector2 cpuPostion{ (float)1000-50, (float)HEIGHT / 2 };
    Cpu cpu(cpuPostion);

    Vector2 ballPosition{ (float)WIDTH / 2, (float)HEIGHT / 2};
    Ball ball(ballPosition);

    Score score;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        // DrawText("0 | 0", WIDTH / 2 - 50, 30, 40, RAYWHITE);
        drawMiddle();

        float dt = GetFrameTime();
        // std::cout << "Delta time: " << dt << std::endl;

        player.move();
        player.drawPlayer();

        ball.move(player.getPosition(), cpu.getPosition(), dt, player.getHeight(), player.getWidth(), score);
        ball.drawBall();

        Vector2 pos = ball.getPosition();
        Vector2 direction = ball.getDirection();
        cpu.move(pos, direction);
        cpu.drawCpu();

        score.drawScore();

        // std::cout << "X: " << pos.x << " Y: " << pos.y << std::endl;

        if (IsKeyPressed(KEY_Q)) break;

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void drawMiddle() {
    constexpr int gap = 60;
    constexpr int RECT_WIDTH = 5;
    constexpr int RECT_HEIGHT = 30;
    
    // void DrawRectangle(int posX, int posY, int width, int height, Color color);
    for (int i{ 0 }; i <= 12; i++) {
        DrawRectangle(WIDTH / 2 - (RECT_WIDTH / 2), i * gap, RECT_WIDTH, RECT_HEIGHT, RAYWHITE);
    }
}