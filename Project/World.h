#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "w_constant.h"

int suuri_undur=-10;
void zam_suur(){
    glBindTexture(GL_TEXTURE_2D,texture_walker);

	glBegin(GL_QUADS);

    for(int i=-500;i<=400;i+=200){

    glTexCoord2d(0,0.5);
    glVertex3f(i,0.5,100);

    glTexCoord2d(0,1);
    glVertex3f(i,0.5,150);

    glTexCoord2d(1,1);
    glVertex3f(i+200,0.5,150);

    glTexCoord2d(1,0.5);
    glVertex3f(i+200,0.5,100);
    }
    glEnd();


	// glColor3f(1.0f, 1.0f, 1.0f);
	// glBegin(GL_QUADS);
    // glTexCoord2d(0,0.8);
    // glVertex3f(-500,0,100);
    // glTexCoord2d(0,1);
    // glVertex3f(-500,0,150);
    // glTexCoord2d(1,1);
    // glVertex3f(500,0,150);
    // glTexCoord2d(1,0.8);
    // glVertex3f(500,0,100);
    // glEnd();


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


//zam undsen
void zam1_suuri(){
	// glColor3f(0.5f, 0.5f, 0.5f);

    glBindTexture(GL_TEXTURE_2D,texture_zam);

	glBegin(GL_QUADS);

    for(int i=-500;i<=400;i+=200){

    glTexCoord2d(0,0);
    glVertex3f(i,0.5,-100);

    glTexCoord2d(0,1);
    glVertex3f(i,0.5,100);

    glTexCoord2d(1,1);
    glVertex3f(i+200,0.5,100);

    glTexCoord2d(1,0);
    glVertex3f(i+200,0.5,-100);
    }
    glEnd();

    // glBegin(GL_QUADS);
    // glTexCoord2d(0,0);
    // glVertex3f(-500,0,-100);
    // glTexCoord2d(0,1);
    // glVertex3f(-500,0,100);
    // glTexCoord2d(1,1);
    // glVertex3f(500,0,100);
    // glTexCoord2d(1,0);
    // glVertex3f(500,0,-100);

    // glEnd();

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
glBindTexture(GL_TEXTURE_2D,texture_grass);

	glBegin(GL_QUADS);
    glTexCoord2d(0, 0.5);
    glVertex3f(-500,0,150);
      glTexCoord2d(0, 1);
    glVertex3f(-500,0,500);
      glTexCoord2d(1, 1);
    glVertex3f(500,0,500);
      glTexCoord2d(1, 0.5);
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

//yavgan zam
void zam2_suuri(){
    glBindTexture(GL_TEXTURE_2D,texture_walker);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);


    // glTexCoord2d(0,0.5);
    // glVertex3f(-500,0,-200);
    // glTexCoord2d(0,1);
    // glVertex3f(-500,0,-100);
    // glTexCoord2d(1,1);
    // glVertex3f(500,0,-100);
    // glTexCoord2d(1,0.5);
    // glVertex3f(500,0,-200);


	glBegin(GL_QUADS);

    for(int i=-500;i<=400;i+=200){

    glTexCoord2d(0,0.5);
    glVertex3f(i,0.5,-200);

    glTexCoord2d(0,1);
    glVertex3f(i,0.5,-100);

    glTexCoord2d(1,1);
    glVertex3f(i+200,0.5,-100);

    glTexCoord2d(1,0.5);
    glVertex3f(i+200,0.5,-200);
    }
    glEnd();

    // glTexCoord2d(0,0.5);
    // glVertex3f(-500,0,-200);
    // glTexCoord2d(1,0);
    // glVertex3f(-500,0,-100);
    // glTexCoord2d(1,1);
    // glVertex3f(500,0,-100);
    // glTexCoord2d(0.5,1);
    // glVertex3f(500,0,-200);

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

//grass
void zam3_suuri(){

    glBindTexture(GL_TEXTURE_2D,texture_grass);

	glColor3f(0.0f, 0.5f, 0.4f);
	
    
    
    // glBegin(GL_QUADS);
    //     glTexCoord2d(0,0.8);
    //     glVertex3f(-500,0,-260);
    //     glTexCoord2d(0,1);
    //     glVertex3f(-500,0,-200);
    //     glTexCoord2d(1,1);
    //     glVertex3f(500,0,-200);
    //     glTexCoord2d(1,0.8);
    //     glVertex3f(500,0,-260);
    // glEnd();


	glBegin(GL_QUADS);

    for(int i=-500;i<=400;i+=500){

    glTexCoord2d(0,0.8);
    glVertex3f(i,0.5,-260);

    glTexCoord2d(0,1);
    glVertex3f(i,0.5,-200);

    glTexCoord2d(1,1);
    glVertex3f(i+500,0.5,-200);

    glTexCoord2d(1,0.8);
    glVertex3f(i+500,0.5,-260);
    }
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
    // glColor3f(0.0f, 0.0f, 1.0f);

    glBindTexture(GL_TEXTURE_2D,texture_us);
    glBegin(GL_QUADS);
    glTexCoord2d(0,0);
    glVertex3f(-500,0.5,-500);
    glTexCoord2d(0,1);
    glVertex3f(-500,0.5,-420);
    glTexCoord2d(1,0);
    glVertex3f(500,0.5,-420);
    glTexCoord2d(1,1);
    glVertex3f(500,0.5,-500);

    glEnd();

//els
    glBindTexture(GL_TEXTURE_2D,texture_els);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    
    for(int i=-500;i<=400;i+=500){

    glTexCoord2d(0,0.5);
    glVertex3f(i,0.5,-420);

    glTexCoord2d(0,1);
    glVertex3f(i,0.5,-260);

    glTexCoord2d(1,1);
    glVertex3f(i+500,0.5,-260);

    glTexCoord2d(1,0.5);
    glVertex3f(i+500,0.5,-420);
    }

    glEnd();


	zam_suur();
	zam1_suuri();
	baishin_suuri();
	zam2_suuri();
	zam3_suuri();
}


