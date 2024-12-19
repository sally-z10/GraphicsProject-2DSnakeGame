#ifndef DEF_H
#define DEF_H

#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <deque>
#include <utility>
#include <assert.h>
#include <cmath>
#include <ctime>

// colors for the program in rgb format
#define mapBgColor   0.10, 0.10, 0.20
#define snakeColor   0.00, 0.00, 0.00
#define foodColor    0.00, 0.00, 0.00
#define wallColor    0.0,  1.0,  1.0
#define splFoodColor 1.00, 0.00, 0.00

extern int map_size;
extern int luck;
extern int initialLives;
extern int maxDifficulty;

#define UP     1
#define DOWN   2
#define LEFT   3
#define RIGHT  4

#define delay(n) for(int i = 0; i < 100000;i++)for(int j = 0; j < n*1000;j++);

extern std::deque<std::pair<int, int>> snake_body;
extern int food_pos[2];

extern int foodAvailable;
extern int score;
extern int special;
extern int paused;
extern int finished;
extern int direction;
extern int Difficulty;
extern int currentLives;
extern int gameSpeed;

void showFinalScore();
void guide();
void draw_body_part(int x, int y);
void food_texture(int x, int y);
void drawBrick(int x, int y);
void drawWalls();
void drawFood();
void drawSnake();
void moveSnake(int newDirection);
void TimerFunc(int val);
void display();
void reshape(GLsizei w, GLsizei h);
void initializeGame();
void keyboard(unsigned char key, int x, int y);

#endif // DEF_H
