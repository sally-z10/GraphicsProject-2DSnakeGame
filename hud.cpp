#include "def.h"

void drawText(float x, float y, const std::string& text, void* font = GLUT_BITMAP_HELVETICA_12, float r = 1.0f, float g = 1.0f, float b = 1.0f)
{
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(font, c);
    }
}

void drawHUD()
{
    // 1) Draw a background rectangle at the top
    glColor3f(mapBgColor);
    glBegin(GL_QUADS);
    glVertex2f(0, map_size);
    glVertex2f(map_size, map_size);
    glVertex2f(map_size, map_size + HUD_HEIGHT);
    glVertex2f(0, map_size + HUD_HEIGHT);
    glEnd();

    // We'll place text starting near the top of that rectangle
    float topY = map_size + HUD_HEIGHT - 1.0f;
    float leftX = 1.0f;               // left margin
    float rightX = map_size - 10.0f;   // so it’s on the same line as 'lives'
    float lineGap = 1.0f;               // vertical spacing between lines

    // 2) First line: "Lives: X" on left, "Score: Y" on right
    {
        std::string livesStr = "Lives:" + std::to_string(currentLives);
        drawText(leftX, topY, livesStr);

        std::string scoreStr = "Score:" + std::to_string(score);
        drawText(rightX, topY, scoreStr);
    }

    // 3) Then instructions on separate lines, left-aligned
    float lineY = topY - lineGap;  // move down one line

    drawText(leftX, lineY, "M: Change Difficulty   R: Restart   P:Pause/Resume");
    lineY -= lineGap;

    drawText(leftX, lineY, "+: Zoom In  -: Zoom Out");
    lineY -= lineGap;

    drawText(leftX, lineY, statusMessage);
    lineY -= lineGap;
}
