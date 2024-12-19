#include "def.h"

void draw_body_part(int x, int y)
{
    glColor3f(0.8, 0.2, 0.4); // Dark red
    float radius = 0.45;
    int num_segments = 20;

    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + 0.5f + dx, y + 0.5f + dy);
    }
    glEnd();
}

void food_texture(int x, int y)
{
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.5f, y + 1.0f);
    glVertex2f(x + 0.0f, y + 0.5f);
    glVertex2f(x + 0.5f, y + 0.0f);
    glVertex2f(x + 1.0f, y + 0.5f);
    glEnd();
}

void drawBrick(int x, int y)
{
    glColor3f(wallColor);
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.95f, y + 0.95f);
    glVertex2f(x + 0.05f, y + 0.95f);
    glVertex2f(x + 0.05f, y + 0.05f);
    glVertex2f(x + 0.95f, y + 0.05f);
    glEnd();
}

void drawWalls()
{
    for (int i = 0; i <= map_size; i++)
    {
        drawBrick(i, 0);
        drawBrick(i, map_size - 1);
        drawBrick(0, i);
        drawBrick(map_size - 1, i);
    }
}

void drawFood()
{
    if (!foodAvailable)
    {
        int fx = rand() % (map_size - 2) + 1;
        int fy = rand() % (map_size - 2) + 1;
        int lottery = 1 + rand() % 100;
        if (lottery <= luck && score != 0)
            special = 1;

        int overlap = 1;
        while (overlap)
        {
            overlap = 0;
            for (auto part : snake_body)
            {
                if (part.first == fx && part.second == fy)
                {
                    fx = rand() % map_size + 1;
                    fy = rand() % map_size + 1;
                    overlap = 1;
                    break;
                }
            }
        }
        food_pos[0] = fx;
        food_pos[1] = fy;
    }

    foodAvailable = 1;

    if (special == 1)
        glColor3f(splFoodColor);
    else
        glColor3f(foodColor);

    food_texture(food_pos[0], food_pos[1]);
}

void drawSnake()
{
    glColor3f(snakeColor);

    int hx = snake_body[0].first;
    int hy = snake_body[0].second;

    // Head
    glBegin(GL_POLYGON);
    glVertex2i(hx + 1, hy + 1);
    glVertex2i(hx + 1, hy + 0);
    glVertex2i(hx + 0, hy + 0);
    glVertex2i(hx + 0, hy + 1);
    glEnd();

    glColor3f(mapBgColor);
    glBegin(GL_POLYGON);
    glVertex2f(hx + 0.85f, hy + 0.9f);
    glVertex2f(hx + 0.85f, hy + 0.65f);
    glVertex2f(hx + 0.65f, hy + 0.65f);
    glVertex2f(hx + 0.65f, hy + 0.9f);
    glEnd();

    // Body
    glColor3f(snakeColor);
    int len = (int)snake_body.size();
    for (int i = 1; i < len; i++)
    {
        draw_body_part(snake_body[i].first, snake_body[i].second);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, map_size, 0, map_size);
    glMatrixMode(GL_MODELVIEW);

    drawSnake();
    drawFood();
    drawWalls();

    glutSwapBuffers();
}

void reshape(GLsizei, GLsizei)
{
    glutReshapeWindow(map_size * 20, map_size * 20);
}
