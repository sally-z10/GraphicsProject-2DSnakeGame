#include "def.h"

int map_size = 25;
int luck = 5;
int initialLives = 5;
int maxDifficulty = 7;

std::deque<std::pair<int, int>> snake_body;
int food_pos[2];

int foodAvailable = 0;
int score = 0;
int special = 0;
int paused = 1;
int finished = 0;
int direction = RIGHT;
int Difficulty = maxDifficulty;
int currentLives = initialLives;
int gameSpeed = Difficulty * 20;
int highScore = 0;
int gameWindow = 0; 
int menuWindow = 0;
string statusMessage = "Welcome !!";