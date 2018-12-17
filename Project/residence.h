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
void draw_face(vector<Face> &face, vector<Color> &color_info, vector<string> &colors, vector<int> &num) {
	glBegin(GL_TRIANGLES);
	int i=0;
	float normal[3];
	for(int l = 0; l < colors.size(); l++){
		for (const Color &color : color_info) {
			if(color.name == colors[l]){
				glColor3f(color.r, color.b, color.g);
				for(int s = 0; s < num[l]; s++){

					calcNormal(face[i], normal);
					glNormal3fv(normal);

					for (int j = 0; j < 3; ++j){
						glVertex3f(2*face[i].v[j].x, 2*face[i].v[j].y, 2*face[i].v[j].z);
					}
					i++;
				}
			}
		}
	}
	glEnd();
}

void draw_residence() {
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-340, 180, 0);

	draw_face(residence_faces, residence_colorInfo, residence_colors, residence_num);

	glPopMatrix();
}

void draw_home() {
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(-320, 320, 0);
	draw_face(home_faces, home_colorInfo, home_colors, home_num);

	glPopMatrix();
}
#endif // RESIDENCE_H

