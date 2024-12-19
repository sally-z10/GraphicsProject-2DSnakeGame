#include "def.h"

void showFinalScore()
{
    std::cout << "*********\n";
    std::cout << "Your Final Score is: " << score << std::endl;
}

void guide()
{
    printf("\n*********************");
    printf("\nUse WASD as movement keys.");
    printf("\nPress W for Up, A for left, S for Down and D for Right");
    printf("\nM to change difficulty.");
    printf("\nR to Restart Game.");
    printf("\n+ to Increase map size. The game will restart though.");
    printf("\n- to Decrease map size. The game will restart though.");
    printf("\nP to pause/resume the game.");
    printf("\nPress Esc or Q to  Quit.");
    printf("\nPress H for help.");
    printf("\n\nPress P to Start.");
    printf("\n*********************\n");
}

void moveSnake(int newDirection)
{
    direction = newDirection;
    int delX = 0;
    int delY = 0;

    switch (direction)
    {
    case UP:
        delY = 1;
        break;
    case DOWN:
        delY = -1;
        break;
    case LEFT:
        delX = -1;
        break;
    case RIGHT:
        delX = 1;
        break;
    }

    for (auto part : snake_body)
    {
        if ((part.first == (snake_body[0].first + delX)) && (part.second == (snake_body[0].second + delY)))
        {
            currentLives--;
            std::cout << "Be Careful! You got bit.\n";
            if (currentLives <= 0)
            {
                std::cout << "Game Over.\n";
                showFinalScore();
                delay(2);
                exit(0);
            }
        }
    }

    if (snake_body[0].first <= 0 || snake_body[0].first >= map_size - 1 ||
        snake_body[0].second <= 0 || snake_body[0].second >= map_size - 1)
    {
        std::cout << "Oh NO! You ran into wall. Game Over.\n";
        showFinalScore();
        delay(2);
        exit(0);
    }

    int grow = 0;
    if (snake_body[0].first + delX == food_pos[0] && snake_body[0].second + delY == food_pos[1])
    {
        grow = 1;
        if (special)
        {
            grow = 100;
            special = 0;
            std::cout << "Legendary Food!!! +100 score.\n";
        }
        score += grow;
        foodAvailable = 0;
    }

    snake_body.push_front({ snake_body[0].first + delX, snake_body[0].second + delY });
    if (!grow)
    {
        snake_body.pop_back();
    }

    glutPostRedisplay();
}

void TimerFunc(int val)
{
    if (!paused)
        moveSnake(direction);
    glutTimerFunc(gameSpeed, TimerFunc, 0);
}
