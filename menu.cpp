#include "def.h"

const char* highScoreFile = "high_score.txt";

void loadHighScore() {
    ifstream file(highScoreFile);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    else {
        highScore = 0;
    }
}

void saveHighScore() {
    ofstream file(highScoreFile);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
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

