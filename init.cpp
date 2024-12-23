#include "def.h"

void initMenuWindow() {
    glutDisplayFunc(displayMenu);
    glutKeyboardFunc(menuKeyboard);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void initGameWindow() {
    glutDisplayFunc(displayGame);
    glClearColor(mapBgColor, 1.0);
	glutKeyboardFunc(keyboard);
    glutTimerFunc(gameSpeed, TimerFunc, 0);
}

void initializeGame() {
    srand(time(0));
    snake_body.clear();
    snake_body.push_back({ map_size / 2, map_size / 2 });
    snake_body.push_back({ map_size / 2 - 1, map_size / 2 });
    snake_body.push_back({ map_size / 2 - 2, map_size / 2 });
    direction = RIGHT;
    score = 0;
    foodAvailable = 0;
    paused = 1;
}