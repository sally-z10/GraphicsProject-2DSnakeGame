#include "def.h"

/*void moveSnake(int newDirection)
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
            statusMessage = "You lost a life! Be Careful! You got bit.";
		
            if (currentLives <= 0)
            {
				delay(2);
                std::cout << "Game Over.\n";
                statusMessage = "Game Over!";
                showFinalScore();
				saveHighScore();
                statusMessage = "Game Over! Press R to Restart or Q to Quit.";

                paused = 1;           // Mark the game as finished
                return;                 // Return so we don’t do more snake logic
				
			}
		}
	}

    if (snake_body[0].first <= 0 || snake_body[0].first >= map_size - 1 ||
        snake_body[0].second <= 0 || snake_body[0].second >= map_size - 1)
    {
        std::cout << "Oh NO! You ran into wall. Game Over.\n";
		statusMessage = "Oh NO! You ran into wall. Game Over.";
        showFinalScore();
		saveHighScore();
		initializeGame();
    }

    int grow = 0;
    if (snake_body[0].first + delX == food_pos[0] && snake_body[0].second + delY == food_pos[1])
    {
        grow = 1;
        if (special)
        {
            grow = 10;
            special = 0;
            std::cout << "Legendary Food!!! +100 score.\n";
			statusMessage = "Legendary Food!!! +10 score.";
        }
        score += grow;
        foodAvailable = 0;
    }

	// compare the score with high score then update the high score
    highScore = loadHighScore();
	if (score > highScore)
	{
		highScore = score;
	}

    snake_body.push_front({ snake_body[0].first + delX, snake_body[0].second + delY });
    if (!grow)
    {
        snake_body.pop_back();
    }

    glutPostRedisplay();
}*/
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

    // Check if snake collides with itself
    for (auto part : snake_body)
    {
        if ((part.first == (snake_body[0].first + delX)) && (part.second == (snake_body[0].second + delY)))
        {
            currentLives--;  // Decrease lives
            std::cout << "Be Careful! You got bit.\n";
            statusMessage = "You lost a life! Be Careful! You got bit.";

            // Check if no lives are left
            if (currentLives <= 0)
            {
                delay(2);  // Add a small delay for dramatic effect
                std::cout << "Game Over.\n";
                statusMessage = "Game Over!";
                showFinalScore();
                saveHighScore();
                statusMessage = "Game Over! Press R to Restart or Q to Quit.";

                paused = 1;  // Mark the game as finished
                return;  // Immediate return to stop further game logic
            }
        }
    }

    // Check if snake collides with wall
    if (snake_body[0].first <= 0 || snake_body[0].first >= map_size - 1 ||
        snake_body[0].second <= 0 || snake_body[0].second >= map_size - 1)
    {
        std::cout << "Oh NO! You ran into wall. Game Over.\n";
        statusMessage = "Oh NO! You ran into wall. Game Over.";
        showFinalScore();
        saveHighScore();
        initializeGame();  // Restart the game after collision with the wall
        return;  // Early return to stop further game logic
    }

    int grow = 0;  // Determine if the snake should grow
    if (snake_body[0].first + delX == food_pos[0] && snake_body[0].second + delY == food_pos[1])
    {
        grow = 1;  // Grow by one unit if normal food is eaten
        if (special)
        {
            grow = 10;  // Special food grants more growth
            special = 0;
            std::cout << "Legendary Food!!! +100 score.\n";
            statusMessage = "Legendary Food!!! +10 score.";
        }
        score += grow;  // Update the score
        foodAvailable = 0;  // Food is no longer available
    }

    // Update the high score if the current score exceeds it
    highScore = loadHighScore();
    if (score > highScore)
    {
        highScore = score;
    }

    // Add the new head to the front of the deque (move the snake)
    snake_body.push_front({ snake_body[0].first + delX, snake_body[0].second + delY });

    // If the snake didn’t eat food, remove the tail
    if (!grow)
    {
        snake_body.pop_back();
    }

    // Redisplay the game after updating the snake
    glutPostRedisplay();
}


void TimerFunc(int val) {
    if (!paused)
        moveSnake(direction);
    glutTimerFunc(gameSpeed, TimerFunc, 0);
}
