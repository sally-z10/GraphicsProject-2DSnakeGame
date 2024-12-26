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
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


// ================== Constants =================== //
#define mapBgColor   0.10, 0.10, 0.20
#define snakeColor   1.00, 1.00, 1.00
#define foodColor    0.7, 0.7, 0.7
#define wallColor    0.0,  1.0,  1.0
#define splFoodColor 1.00, 0.00, 0.00

#define UP     1
#define DOWN   2
#define LEFT   3
#define RIGHT  4

#define delay(n) for(int i = 0; i < 100000;i++)for(int j = 0; j < n*1000;j++);

// ============== Global Variables ================ //

// Map & Window
extern int map_size;
extern int gameWindow;
extern int menuWindow;
static const int HUD_HEIGHT = 5;

// Game Variables
extern int direction;
extern int paused;
extern int gameSpeed;
extern int luck;
extern int initialLives;
extern int maxDifficulty;
extern int finished;
extern int Difficulty;
extern int currentLives;
extern string statusMessage;

// Snake & Food
extern std::deque<std::pair<int, int>> snake_body;
extern int food_pos[2];
extern int foodAvailable;
extern int special;
extern int score;
extern int highScore;


// ============== Function Prototypes ============== //

// draw.cpp
void draw_body_part(int x, int y);
void food_texture(int x, int y);
void drawBrick(int x, int y);
void drawWalls();
void drawFood();
void drawSnake();
void displayGame();

// gamelogic.cpp
void moveSnake(int newDirection);
void TimerFunc(int value);

// hud.cpp
void drawText(float x, float y, const std::string & text, void* font, float r, float g, float b);
void drawHUD();

// init.cpp
void initMenuWindow();
void initGameWindow();
void initializeGame();
void reshape(GLsizei w, GLsizei h);

// keyboard.cpp
void keyboard(unsigned char key, int x, int y);

// menu.cpp
int loadHighScore();
void saveHighScore();
void showFinalScore();
void guide();
void displayMenu();
void menuKeyboard(unsigned char key, int, int);

#endif // DEF_H