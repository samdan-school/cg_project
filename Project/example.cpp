#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "w_constant.h"

#include "texture.cpp"
#include "Tree.h"
#include "ReadFile.h"

#include "World.h"
#include "residence.h"
#include "Car.h"
#include "Snow.cpp"

#include "Ocean.h"

#define PI 3.14159265

using namespace std;


vector <Snowflack> snow;

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
    draw_tree();

    draw_water(t); 
    move_red_car(red_car_speed, 1);
    move_black_car(black_car_speed, -1);
    draw_shark(t);
    draw_boat();

    GLUquadricObj *pObj;
    pObj = gluNewQuadric();

    // Snow
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f, 1.0f, 1.0f);

    for (const Snowflack &a: snow) {
        glPushMatrix();
        
        glTranslatef(a.x, a.y, a.z);
        // gluQuadricNormals(pObj, GLU_SMOOTH);
        gluSphere(pObj, 2, 50, 50);
        
        glPopMatrix();
    }

    // snow.init();
    glDisable(GL_COLOR_MATERIAL);

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
    // Snow
    snow.reserve(250);
    for (int i = 0; i < 250; i++) {
        float s_x = rand() % 1000 - 500;
        float s_y = rand() % 400 + 600;
        float s_z = rand() % 1300 - 650;
        // cout << s_x << " " << s_y << " " << s_z << endl;
        Snowflack temp(s_x, s_y, s_z);
        snow.push_back(temp);
    }

    
    texture_zam = LoadBitmap("./texture/zam.bmp");
    texture_els = LoadBitmap("./texture/els.bmp");
    texture_us = LoadBitmap("./texture/2.bmp");
    texture_grass = LoadBitmap("./texture/grass.bmp");
    texture_walker = LoadBitmap("./texture/walker.bmp");
    texture_black = LoadBitmap("./texture/black.bmp");

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA);
    read_verticies("./Baishin/residence.obj", residence_vertices, residence_faces, residence_colors, residence_num);
    read_colors("./Baishin/residence.txt", residence_colorInfo);

    // for (int i = 0; i < residence_colorInfo.size(); i++) {
    //     cout << residence_colorInfo[i].name << endl;
    // }

    read_verticies("./home/home.obj", home_vertices, home_faces, home_colors, home_num);
    read_colors("./home/home.txt", home_colorInfo);

    read_verticies("./boat/boat1.obj", boat_vertices, boat_faces, boat_colors, boat_num);
    read_colors("./boat/boat1.txt", boat_colorInfo);

    read_verticies("./car/red.obj", red_vertices, red_faces, red_colors, red_num);
    read_colors("./car/red.txt", red_colorInfo);

    read_verticies("./car/black.obj", black_vertices, black_faces, black_colors, black_num);
    read_colors("./car/black.txt", black_colorInfo);

    read_verticies("./water/water.obj", water_vertices, water_faces, water_colors, water_num);
    read_colors("./water/water.txt", water_colorInfo);

    read_verticies("./tree/tree1.obj", tree1_vertices, tree1_faces, tree1_colors, tree1_num);
    read_colors("./tree/tree1.txt", tree1_colorInfo);

    read_verticies("./shark/shark.obj", shark_vertices, shark_faces, shark_colors, shark_num);
    read_colors("./shark/shark.txt", shark_colorInfo);

	GLfloat  ambientLight[] = {0.3f, 0.3f, 0.3f, 0.3f };
    GLfloat  diffuseLight[] = {0.15f, 0.15f, 0.15f, 1.0f };
    GLfloat  specular[] = { 0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat  lightPos[] = { -3000.0f, 1500.0f, -3000.0f, 1.0f };

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
    glEnable(GL_LIGHT0);
    // glEnable(GL_LIGHT1);

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

    if (red_car_position <= road_start || red_car_position >= road_end) {
        red_car_position = -800;
    }

    if (black_car_position <= road_start || black_car_position >= road_end) {
        black_car_position = 900;
    }

    for (Snowflack &a: snow) {
        a.update();
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