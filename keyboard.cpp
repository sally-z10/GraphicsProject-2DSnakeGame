#include "def.h"

void keyboard(unsigned char key, int, int) {
    switch (key)
    {
    case 'W':
    case 'w':
        if (!paused && (direction == LEFT || direction == RIGHT)) {
            moveSnake(UP);
        }
        break;
    case 'S':
    case 's':
        if (!paused && (direction == LEFT || direction == RIGHT)) {
            moveSnake(DOWN);
        }
        break;
    case 'A':
    case 'a':
        if (!paused && (direction == UP || direction == DOWN)) {
            moveSnake(LEFT);
        }
        break;
    case 'D':
    case 'd':
        if (!paused && (direction == UP || direction == DOWN)) {
            moveSnake(RIGHT);
        }
        break;
    case 'M':
    case 'm':
        Difficulty = (Difficulty - 1) % (maxDifficulty + 1);
        if (Difficulty <= 0)
            Difficulty = maxDifficulty;
        gameSpeed = Difficulty * 20;
        std::cout << "New Difficulty is " << (maxDifficulty + 1) - Difficulty << std::endl;
        break;
    case 'P':
    case 'p':
        if (paused == 0)
            std::cout << "You Stopped\nPaused the game\n";
        else
            std::cout << "You Resumed/Started Game\n";
        paused = !paused;
        break;
    case 'H':
    case 'h':
        guide();
        break;
    case 'R':
    case 'r':
        showFinalScore();
        std::cout << "You restarted the Game.\nRestarting...\n.All the best!!!.\n";
        initializeGame();
        break;
    case '=':
    case '+':
        if (map_size < 50)
            map_size = map_size + 1;
        glViewport(0, 0, 20 * map_size, 20 * map_size);
        showFinalScore();
        initializeGame();
        break;
    case '_':
    case '-':
        if (map_size > 15)
            map_size = map_size - 1;
        glViewport(0, 0, 20 * map_size, 20 * map_size);
        showFinalScore();
        initializeGame();
        break;
    case 27:
    case 'q':
        std::cout << "You pressed exit.\n";
        showFinalScore();
        exit(0);
    }
}
