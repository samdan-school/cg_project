#if !defined(CAR_H)
#define CAR_H

#include "w_constant.h"
#include "residence.h"

void draw_red() {
	glPushMatrix();
	// glTranslatef(-300, 0, 50);
	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(scale_factor, scale_factor, scale_factor);
	glDisable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);

	draw_face(red_faces, red_colorInfo, red_colors, red_num);

    glDisable(GL_COLOR_MATERIAL);

	glPopMatrix();
}

void draw_black() {
	glPushMatrix();
	glTranslatef(30, 0, -50);
	glRotatef(-90, 1, 0, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(scale_factor, scale_factor, scale_factor);
	glDisable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);

	draw_face(black_faces, black_colorInfo, black_colors, black_num);

    glDisable(GL_COLOR_MATERIAL);

	glPopMatrix();
}

void move_red_car(float speed, int direction) {
	glPushMatrix();
    red_car_position += direction * speed;
	glTranslatef(red_car_position, 0, 50);
	// glTranslatef(red_car_position, 0, 0);

    draw_red();

	glPopMatrix();            
}

void move_black_car(float speed, int direction) {
	glPushMatrix();
    black_car_position += direction * speed;
	glTranslatef(black_car_position, 0, 0);

    draw_black();

	glPopMatrix();            
}

#endif // CAR_H
