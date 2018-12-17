#if !defined(RESIDENCE_H)
#define RESIDENCE_H

#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "ReadFile.h"
#include "w_constant.h"

using namespace std;

void draw_residence() {
	glPushMatrix();

	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);

	glTranslatef(-200, -200, 0);

	for(int i = 0; i < residence_faces.size(); ++i) {
	glColor3f(0, 0,0);
	glBegin(GL_TRIANGLES);
	for (int j = 0; j < 3; ++j){
		glVertex3f(residence_faces[i].v[j].x, residence_faces[i].v[j].y, residence_faces[i].v[j].z);
	}
		glEnd();
	}

	glPopMatrix();
}
#endif // RESIDENCE_H

