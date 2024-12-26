#include "def.h"

void drawText(float x, float y, const std::string& text, void* font = GLUT_BITMAP_HELVETICA_18, float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(font, c);
    }
}

void drawHUD() {
    // Background rectangle at the top
    glColor3f(mapBgColor);
    glBegin(GL_QUADS);
    glVertex2f(0, map_size);
    glVertex2f(map_size, map_size);
    glVertex2f(map_size, map_size + HUD_HEIGHT);
    glVertex2f(0, map_size + HUD_HEIGHT);
    glEnd();

    // We'll place text starting near the top of that rectangle.
    float topY = map_size + HUD_HEIGHT - 1.0f;
    float lineGap = 1.3f;
    float hudLeftX = 1.0f;           // far left
    float hudCenterX = map_size * 0.20f; // approximate center
    float hudRightX = map_size - 12.0f; // far right margin

    // -------- Line 1: Lives, Score, HighScore -------------
    {
        // Lives on the left
        std::string livesStr = "Lives:" + std::to_string(currentLives);
        drawText(hudLeftX, topY, livesStr);

        // Score in the center
        std::string scoreStr = "Score:" + std::to_string(score);
        drawText(hudCenterX, topY, scoreStr);

        // HighScore on the right
        std::string highScoreStr = "HighScore:" + std::to_string(highScore);
        drawText(hudRightX, topY, highScoreStr);
    }

    // -------- Line 2: M/R/P instructions -------------
    float lineY = topY - lineGap;
    drawText(hudLeftX, lineY, "M: Change Difficulty   R: Restart   P:Pause/Resume");

    // -------- Line 3: Zoom/Quit instructions -------------
    lineY -= lineGap;
    drawText(hudLeftX, lineY, "+: Zoom In  -: Zoom Out  Q: Quit");

    // -------- Line 4: statusMessage (below the instructions) -------------
    lineY -= lineGap;
    drawText(hudLeftX, lineY, statusMessage);
}
