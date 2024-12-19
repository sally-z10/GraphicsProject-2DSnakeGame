#include "def.h"

void initializeGame()
{
    assert(map_size >= 15);
    assert(map_size <= 50);
    assert(luck <= 100);
    assert(luck >= 1);
    assert(maxDifficulty >= 5);

    srand((unsigned)time(0));

    glClearColor(mapBgColor, 0);
    score = 0;
    currentLives = initialLives;

    // create size 3 snake
    snake_body.clear();
    snake_body.push_back({ 5, map_size / 2 });
    snake_body.push_back({ 4, map_size / 2 });
    snake_body.push_back({ 3, map_size / 2 });

    moveSnake(RIGHT);

    paused = 1;
    foodAvailable = 0;
    guide(); // show game guide
}
