#include "def.h"

const char* highScoreFile = "high_score.txt";

int loadHighScore() {
    ifstream file(highScoreFile);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    else {
        highScore = 0;
    }
	return highScore;
}

void saveHighScore() {
    ofstream file(highScoreFile);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}


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

void displayMenu() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.5f, 0.7f);
    string title = "Snake Game Menu";
    for (char c : title) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    glRasterPos2f(-0.5f, 0.3f);
    string start = "Press '1' to Start the Game";
    for (char c : start) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    glRasterPos2f(-0.5f, -0.1f);
    string highScoreText = "High Score: " + to_string(highScore);
    for (char c : highScoreText) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    glRasterPos2f(-0.5f, -0.5f);
    string quit = "Press '2' to Quit";
    for (char c : quit) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

    glutSwapBuffers();
}

void menuKeyboard(unsigned char key, int, int) {
    if (key == '1') {
        glutSetWindow(gameWindow);
        glutShowWindow();
        glutSetWindow(menuWindow);
        glutHideWindow();
    }
    else if (key == '2') {
        saveHighScore();
        exit(0);
    }
}

