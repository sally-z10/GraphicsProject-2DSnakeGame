/*************************
 * @authors
 * Nada Ashraf Gomaa 120210358 & $all¥ Reda Zeineldeen  120210008
 * Code written for  Computer Graphics Course (on Dec 2024)
 *
**************************/

#include "def.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(map_size * 20, map_size * 20);
    glutInitWindowPosition(250, 100);
    glutCreateWindow("SLytherin House");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(gameSpeed, TimerFunc, 0);

    initializeGame();
    glutMainLoop();
    return 0;
}
