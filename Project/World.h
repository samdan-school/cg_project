#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>
void world_init() {
	glColor3f(0.0f, 0.5f, 0.4f);

    glBegin(GL_QUADS);

    glVertex3f(-500,0,-500);
    glVertex3f(-500,0,500);
    glVertex3f(500,0,500);
    glVertex3f(500,0,-500);

    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0.5,-500);
    glVertex3f(-500,0.5,-420);
    glVertex3f(500,0.5,-420);
    glVertex3f(500,0.5,-500);

    glEnd();
    glColor3f(0.86f, 0.82f, 0.71f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0.5,-420);
    glVertex3f(-500,0.5,-260);
    glVertex3f(500,0.5,-260);
    glVertex3f(500,0.5,-420);

    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0.5,-200);
    glVertex3f(-500,0.5,-100);
    glVertex3f(500,0.5,-100);
    glVertex3f(500,0.5,-200);

    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0.5,-100);
    glVertex3f(-500,0.5,100);
    glVertex3f(500,0.5,100);
    glVertex3f(500,0.5,-100);

    glEnd();
     glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0.5,100);
    glVertex3f(-500,0.5,150);
    glVertex3f(500,0.5,150);
    glVertex3f(500,0.5,100);

    glEnd();
}


