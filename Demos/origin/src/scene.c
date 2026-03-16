#include "scene.h"

#include <GL/gl.h>
#include <math.h>

void init_scene(Scene* scene)
{
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    draw_origin();
    draw_triangle();
    draw_tessellated_ball(0.5f,36,36);
    draw_tessellated_cylinder(0.5f, 1, 20);
glBegin(GL_QUADS);

glColor3f(1, 0, 0);
glVertex3f(0, 0, 0);
glVertex3f(0, 0, 1);
glVertex3f(1, 0, 1);
glVertex3f(1, 0, 0);

glColor3f(0, 1, 0);
glVertex3f(0, 0, 0);
glVertex3f(0, 0, 1);
glVertex3f(1, 0, 1);
glVertex3f(1, 0, 0);

glEnd();

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_triangle()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0, 1, 1);
    glVertex3f(0, 1, 0);
    glColor3f(1, 0, 1);
    glVertex3f(1, 0, 1);
    glColor3f(1, 1, 0);
    glVertex3f(0, 1, 1);

    glEnd();
}

void draw_tessellated_ball(float radius, int slices, int stacks)
{
    for (int i = 0; i < stacks; ++i) {
        float theta1 = (float)i / stacks * M_PI;          // Latitude angle 1
        float theta2 = (float)(i + 1) / stacks * M_PI;    // Latitude angle 2

        for (int j = 0; j < slices; ++j) {
            float phi1 = (float)j / slices * 2.0f * M_PI;          // Longitude angle 1
            float phi2 = (float)(j + 1) / slices * 2.0f * M_PI;    // Longitude angle 2

            // Vertices of the two triangles forming a quad
            float x1 = 1.5 + radius * sinf(theta1) * cosf(phi1);
            float y1 = 0.5 + radius * cosf(theta1);
            float z1 = 0.5 + radius * sinf(theta1) * sinf(phi1);

            float x2 = 1.5 + radius * sinf(theta2) * cosf(phi1);
            float y2 = 0.5 + radius * cosf(theta2);
            float z2 = 0.5 + radius * sinf(theta2) * sinf(phi1);

            float x3 = 1.5 + radius * sinf(theta2) * cosf(phi2);
            float y3 = 0.5 + radius * cosf(theta2);
            float z3 = 0.5 + radius * sinf(theta2) * sinf(phi2);

            float x4 = 1.5 + radius * sinf(theta1) * cosf(phi2);
            float y4 = 0.5 + radius * cosf(theta1);
            float z4 = 0.5 + radius * sinf(theta1) * sinf(phi2);

            // Draw the two triangles
            glBegin(GL_TRIANGLES);

            glColor3f(0.5f, 0.5f, 0.5f); 
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);

            glColor3f(0.9f, 0.9f, 0.9f); 
            glVertex3f(x1, y1, z1);
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);

            glEnd();
        }
    }
}
void draw_tessellated_cylinder(float radius, float height, int slices)
{
    for (int i = 0; i < slices; ++i) {
        float theta1 = (float)i / slices * 2.0f * M_PI;          // Latitude angle 1
        float theta2 = (float)(i + 1) / slices  * 2.0f * M_PI;    // Latitude angle 2
        // Vertices of the two triangles forming a quad
            float x1 = 2.5 + radius * sinf(theta1);
            float y1 = 0.5 + radius * cosf(theta1);
            float z1 = 0;

            float x2 = 2.5 + radius * sinf(theta2);
            float y2 = 0.5 + radius * cosf(theta2);
            float z2 = 0;

            float x3 = 2.5 + radius * sinf(theta2);
            float y3 = 0.5 + radius * cosf(theta2);
            float z3 = height;

            float x4 = 2.5 + radius * sinf(theta1);
            float y4 = 0.5 + radius * cosf(theta1);
            float z4 = height;

            // Draw the two triangles
            glBegin(GL_TRIANGLES);

            glColor3f(0.5f, 0.5f, 0.5f); 
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);

            glColor3f(0.9f, 0.9f, 0.9f); 
            glVertex3f(x1, y1, z1);
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);

            glEnd();
    }

}