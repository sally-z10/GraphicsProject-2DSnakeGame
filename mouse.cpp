//#include "def.h"
//
//void mouse(int button, int state, int mx, int my)
//{
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        if (currentState == MENU) {
//            // Convert the window coordinates to our menu ortho coordinates:
//            // If the window size is map_size*20 by map_size*20, and our menu is in
//            // a 100x100 space, we must find the scaling factor:
//            int width = glutGet(GLUT_WINDOW_WIDTH);
//            int height = glutGet(GLUT_WINDOW_HEIGHT);
//
//            float x = (float)mx / (float)width * 100;
//            float y = (float)(height - my) / (float)height * 100;
//
//            // Check if clicked on "Start Game" (around 45,50)
//            if (isInside(x, y, 40, 49, 60, 52)) {
//                // Start game
//                currentState = GAME;
//                statusMessage = "Game Started. Press P to Pause.";
//                paused = 1; // will start paused, user presses P
//                // Reset any needed variables, or ensure everything is ready
//                glutPostRedisplay();
//            }
//
//            // Check if clicked on "High Score"
//            if (isInside(x, y, 40, 44, 60, 47)) {
//                currentState = HIGHSCORE;
//                glutPostRedisplay();
//            }
//
//            // Check if clicked on "Quit"
//            if (isInside(x, y, 40, 39, 60, 42)) {
//                exit(0);
//            }
//
//        }
//        else if (currentState == HIGHSCORE) {
//            // If on high score screen, maybe clicking anywhere returns to menu
//            currentState = MENU;
//            glutPostRedisplay();
//        }
//    }
//}
