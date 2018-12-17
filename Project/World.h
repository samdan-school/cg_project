#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>
int suuri_undur=-10;
void zam_suur(){
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
    glVertex3f(-500,0,100);
    glVertex3f(-500,0,150);
    glVertex3f(500,0,150);
    glVertex3f(500,0,100);
    glEnd();
	glBegin(GL_QUADS);
    glVertex3f(-500,0,100);
    glVertex3f(-500,0,150);
    glVertex3f(-500,suuri_undur,150);
    glVertex3f(-500,suuri_undur,100);
    glEnd();
	glBegin(GL_QUADS);
    glVertex3f(-500,suuri_undur,150);
    glVertex3f(-500,0,150);
    glVertex3f(500,0,150);
    glVertex3f(500,suuri_undur,150);
    glEnd();
	glBegin(GL_QUADS);
    glVertex3f(500,0,150);
    glVertex3f(500,0,100);
	glVertex3f(500,suuri_undur,100);
    glVertex3f(500,suuri_undur,150);
    glEnd();
	glBegin(GL_QUADS);
    glVertex3f(-500,0,100);
    glVertex3f(500,0,100);
	glVertex3f(500,suuri_undur,100);
    glVertex3f(-500,suuri_undur,100);
    glEnd();
	glBegin(GL_QUADS);
    glVertex3f(-500,suuri_undur,100);
    glVertex3f(-500,suuri_undur,150);
    glVertex3f(500,suuri_undur,150);
    glVertex3f(500,suuri_undur,100);
    glEnd();
}

void zam1_suuri(){
	glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0,-100);
    glVertex3f(-500,0,100);
    glVertex3f(500,0,100);
    glVertex3f(500,0,-100);

    glEnd();

	glBegin(GL_QUADS);

    glVertex3f(-500,suuri_undur,-100);
    glVertex3f(-500,suuri_undur,100);
    glVertex3f(500,suuri_undur,100);
    glVertex3f(500,suuri_undur,-100);

    glEnd();

	glBegin(GL_QUADS);

    glVertex3f(-500,0,-100);
    glVertex3f(-500,0,100);
    glVertex3f(-500,suuri_undur,100);
    glVertex3f(-500,suuri_undur,-100);

    glEnd();
	
	glBegin(GL_QUADS);

    glVertex3f(-500,suuri_undur,100);
    glVertex3f(-500,0,100);
    glVertex3f(500,0,100);
    glVertex3f(500,suuri_undur,100);

    glEnd();

	glBegin(GL_QUADS);

    glVertex3f(500,suuri_undur,-100);
    glVertex3f(500,suuri_undur,100);
    glVertex3f(500,0,100);
    glVertex3f(500,0,-100);

    glEnd();

	glBegin(GL_QUADS);

    glVertex3f(-500,0,-100);
    glVertex3f(-500,suuri_undur,-100);
    glVertex3f(500,suuri_undur,-100);
    glVertex3f(500,0,-100);

    glEnd();
}


void baishin_suuri(){
glColor3f(0.0f, 0.5f, 0.4f);
	glBegin(GL_QUADS);
    glVertex3f(-500,0,150);
    glVertex3f(-500,0,500);
    glVertex3f(500,0,500);
    glVertex3f(500,0,150);
    glEnd();

	glBegin(GL_QUADS);
    glVertex3f(-500,suuri_undur,150);
    glVertex3f(-500,suuri_undur,500);
    glVertex3f(500,suuri_undur,500);
    glVertex3f(500,suuri_undur,150);
    glEnd();

	glBegin(GL_QUADS);
    glVertex3f(-500,0,150);
    glVertex3f(-500,0,500);
    glVertex3f(-500,suuri_undur,500);
    glVertex3f(-500,suuri_undur,150);
    glEnd();

	glBegin(GL_QUADS);
    glVertex3f(-500,suuri_undur,500);
    glVertex3f(-500,0,500);
    glVertex3f(500,0,500);
    glVertex3f(500,suuri_undur,500);
    glEnd();

	glBegin(GL_QUADS);
    glVertex3f(500,suuri_undur,150);
    glVertex3f(500,suuri_undur,500);
    glVertex3f(500,0,500);
    glVertex3f(500,0,150);
    glEnd();

	glBegin(GL_QUADS);
    glVertex3f(-500,0,150);
    glVertex3f(-500,suuri_undur,150);
    glVertex3f(500,suuri_undur,150);
    glVertex3f(500,0,150);
    glEnd();
}

void zam2_suuri(){
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex3f(-500,0,-200);
    glVertex3f(-500,0,-100);
    glVertex3f(500,0,-100);
    glVertex3f(500,0,-200);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(-500,suuri_undur,-200);
    glVertex3f(-500,suuri_undur,-100);
    glVertex3f(500,suuri_undur,-100);
    glVertex3f(500,suuri_undur,-200);

    glEnd();
	glBegin(GL_QUADS);

    glVertex3f(-500,0,-200);
    glVertex3f(-500,0,-100);
    glVertex3f(-500,suuri_undur,-100);
    glVertex3f(-500,suuri_undur,-200);

    glEnd();
	glBegin(GL_QUADS);

    glVertex3f(-500,suuri_undur,-100);
    glVertex3f(-500,0,-100);
    glVertex3f(500,0,-100);
    glVertex3f(500,suuri_undur,-100);

    glEnd();

	glBegin(GL_QUADS);

    glVertex3f(500,suuri_undur,-200);
    glVertex3f(500,suuri_undur,-100);
    glVertex3f(500,0,-100);
    glVertex3f(500,0,-200);

    glEnd();
	glBegin(GL_QUADS);

    glVertex3f(-500,0,-200);
    glVertex3f(-500,suuri_undur,-200);
    glVertex3f(500,suuri_undur,-200);
    glVertex3f(500,0,-200);

    glEnd();
	
}
void zam3_suuri(){
	glColor3f(0.0f, 0.5f, 0.4f);
	glBegin(GL_QUADS);

    glVertex3f(-500,0,-260);
    glVertex3f(-500,0,-200);
    glVertex3f(500,0,-200);
    glVertex3f(500,0,-260);

    glEnd();
	glBegin(GL_QUADS);

    glVertex3f(-500,suuri_undur,-260);
    glVertex3f(-500,suuri_undur,-200);
    glVertex3f(500,suuri_undur,-200);
    glVertex3f(500,suuri_undur,-260);

    glEnd();
		glBegin(GL_QUADS);

    glVertex3f(-500,0,-260);
    glVertex3f(-500,0,-200);
    glVertex3f(-500,suuri_undur,-200);
    glVertex3f(-500,suuri_undur,-260);

    glEnd();
	glBegin(GL_QUADS);

    glVertex3f(-500,suuri_undur,-200);
    glVertex3f(-500,0,-200);
    glVertex3f(500,0,-200);
    glVertex3f(500,suuri_undur,-200);

    glEnd();
	
	glBegin(GL_QUADS);

    glVertex3f(500,suuri_undur,-260);
    glVertex3f(500,suuri_undur,-200);
    glVertex3f(500,0,-200);
    glVertex3f(500,0,-260);

    glEnd();
	glBegin(GL_QUADS);

    glVertex3f(-500,0,-260);
    glVertex3f(-500,suuri_undur,-260);
    glVertex3f(500,suuri_undur,-260);
    glVertex3f(500,0,-260);

    glEnd();
}
void world_init() {
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


	zam_suur();
	zam1_suuri();
	baishin_suuri();
	zam2_suuri();
	zam3_suuri();
}


