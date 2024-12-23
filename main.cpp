/*************************
 * @authors
 * Nada Ashraf Gomaa 120210358 & $all¥ Reda Zeineldeen  120210008
 * Code written for  Computer Graphics Course (on Dec 2024)
 *
**************************/

#include "def.h"

int main(int argc, char** argv) {
    loadHighScore();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // Create menu window
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    menuWindow = glutCreateWindow("Menu");
    initMenuWindow();
    
    // Create game window
    glutInitWindowSize(map_size * 20, map_size * 20);
    glutInitWindowPosition(200, 200);
    gameWindow = glutCreateWindow("Snake Game");
    initGameWindow();
    glutHideWindow();
	guide();
    glutDisplayFunc(displayGame);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(gameSpeed, TimerFunc, 0);
    initializeGame();
    glutMainLoop();
    
    return 0;
}
