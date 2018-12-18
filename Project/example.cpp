#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "World.h"
#include "ReadFile.h"
#include "w_constant.h"
#include "residence.h"
#include "texture.cpp"

#define PI 3.14159265

using namespace std;

float posx=0.0f,posz=0.0f,posy=2000.0f;
float normalx=0, normaly=0, normalz=1;

void normalKeys(unsigned char key, int x00, int y00){
    switch(key){
        case 'p':
        posx = cos(PI/90) * posx - sin(PI/90) * posz;
        posz = cos(PI/90) * posz + sin(PI/90) * posx;
        normalx=cos(PI/90) * normalx - sin(PI/90) * normalz;
        normalz=cos(PI/90) * normalz + sin(PI/90) * normalx;  
        glutPostRedisplay();
        break;
        case 'o':
        posx = cos(PI/90) * posx + sin(PI/90) * posz;
        posz = cos(PI/90) * posz - sin(PI/90) * posx;
        normalx=cos(PI/90) * normalx + sin(PI/90) * normalz;
        normalz=cos(PI/90) * normalz - sin(PI/90) * normalx;  
        glutPostRedisplay();
        break;
    }
}
void SpecialKeys(int key, int x0, int y0)
    {
    if(key == GLUT_KEY_UP){
        posy = cos(PI/90) * posy - sin(PI/90) * posz;
        posz = cos(PI/90) * posz + sin(PI/90) * posy;
        normaly=cos(PI/90) * normaly - sin(PI/90) * normalz;
        normalz=cos(PI/90) * normalz + sin(PI/90) * normaly;  
        glutPostRedisplay();
    }
    else {if(key == GLUT_KEY_DOWN){
        posy = cos(PI/90) * posy + sin(PI/90) * posz;
        posz = cos(PI/90) * posz - sin(PI/90) * posy;
        normaly=cos(PI/90) * normaly + sin(PI/90) * normalz;
        normalz=cos(PI/90) * normalz - sin(PI/90) * normaly;  
        glutPostRedisplay();
    }
        else{
            if(key==GLUT_KEY_RIGHT){
            posx = cos(PI/90) * posx - sin(PI/90) * posy;
            posy = cos(PI/90) * posy + sin(PI/90) * posx;
            normaly=cos(PI/90) * normaly + sin(PI/90) * normalx;
            normalx=cos(PI/90) * normalx - sin(PI/90) * normaly; 
            glutPostRedisplay();
            }
            else{ if(key == GLUT_KEY_LEFT){
            posx = cos(PI/90) * posx + sin(PI/90) * posy;
            posy = cos(PI/90) * posy - sin(PI/90) * posx;
            normaly=cos(PI/90) * normaly - sin(PI/90) * normalx;
            normalx=cos(PI/90) * normalx + sin(PI/90) * normaly; 
            glutPostRedisplay();
            }
            else{
                if(key == GLUT_KEY_PAGE_UP){
                    float R = sqrt(posx*posx+posy*posy+posz*posz);
                    float Rotz = posz/R;
                    posz = (R - 50)*Rotz;
                    float Roty = posy/R;
                    posy = (R - 50)*Roty;
                    float Rotx = posx/R;
                    posx = (R - 50)*Rotx;
                    glutPostRedisplay();
                    }
                    else{
                        if(key == GLUT_KEY_PAGE_DOWN){
                            float R = sqrt(posx*posx+posy*posy+posz*posz);
                            float Rotz = posz/R;
                            posz = (R + 50)*Rotz;
                            float Roty = posy/R;
                            posy = (R + 50)*Roty;
                            float Rotx = posx/R;
                            posx = (R + 50)*Rotx;
                            glutPostRedisplay();
                        }
                    }
            }
            }
        }
    }

    }
void displayMe(void)
{   
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
    gluLookAt(	posx, posy, posz,
			0, 0, 0,
			normalx, normaly,  normalz);
    glEnable(GL_TEXTURE_2D);
    world_init();
    glDisable(GL_TEXTURE_2D);
      
    draw_residence();
    draw_home();
    draw_red();
    draw_black();

    draw_water(t); 
    
	glPopMatrix();
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;


	glMatrixMode(GL_PROJECTION);
    // glOrtho(-500,500,0,1000,-500,500);
    gluPerspective(35.0f, fAspect, 1.0, 20000.0);
  //  glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}

void setup()
{   
    
    texture_zam = LoadBitmap("./texture/zam.bmp");
    texture_els = LoadBitmap("./texture/els.bmp");
    texture_us = LoadBitmap("./texture/2.bmp");
    texture_grass = LoadBitmap("./texture/grass.bmp");
    texture_walker = LoadBitmap("./texture/walker.bmp");

    read_verticies("./Baishin/residence.obj", residence_vertices, residence_faces, residence_colors, residence_num);
    read_colors("./Baishin/residence.txt", residence_colorInfo);

    // for (int i = 0; i < residence_colorInfo.size(); i++) {
    //     cout << residence_colorInfo[i].name << endl;
    // }

    read_verticies("./home/home.obj", home_vertices, home_faces, home_colors, home_num);
    read_colors("./home/home.txt", home_colorInfo);

    read_verticies("./car/red.obj", red_vertices, red_faces, red_colors, red_num);
    read_colors("./car/red.txt", red_colorInfo);

    read_verticies("./car/black.obj", black_vertices, black_faces, black_colors, black_num);
    read_colors("./car/black.txt", black_colorInfo);

    read_verticies("./water/water.obj", water_vertices, water_faces, water_colors, water_num);
    read_colors("./water/water.txt", water_colorInfo);

	GLfloat  ambientLight[] = {0.1f, 0.1f, 0.1f, 1.0f };
    GLfloat  diffuseLight[] = {1, 1, 1, 1.0f };
    GLfloat  specular[] = { 0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat  lightPos[] = { -3000.0f, 3000.0f, -1500.0f, 1.0f };
    GLfloat  specref[] =  { 0.3f, 0.3f, 0.3f, 0.3f };
        glEnable(GL_DEPTH_TEST);    // Hidden surface removal
        glEnable(GL_CULL_FACE);        // Do not calculate inside of solid object
        glFrontFace(GL_CCW);

       // Enable lighting
       glEnable(GL_LIGHTING);

    // Setup light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);

//    Position and turn on the light
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

//    Enable color tracking

    glEnable(GL_COLOR_MATERIAL);
//    Set Material properties to follow glColor values
    // glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    // glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
    // glMateriali(GL_FRONT,GL_SHININESS,64);

    // glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void timer(int value) {
    if ( t_inc )
    {
        t += 0.007;

        if (t >= 1)
        {
            t_inc = false;
        }
    }
    else
    {
        t -= 0.005;

        if (t <= 0)
        {
            t_inc = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(3, timer, 1);    
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("World");
	glutReshapeFunc(resize);
	glutDisplayFunc(displayMe);
	glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(normalKeys);
	setup();
    glutTimerFunc(33, timer, 1);

	glutMainLoop();
	return 0;
}