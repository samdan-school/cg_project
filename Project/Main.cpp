#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>
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
    
	glPopMatrix();
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
    gluPerspective(35.0f, fAspect, 1.0, 20000.0);
  //  glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void setup()
{
	GLfloat  ambientLight[] = {0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat  diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat  lightPos[] = { 0.0f, 40.0f, 0.0f, 1.0f };
    GLfloat  specref[] =  { 0.6f, 0.6f, 0.6f, 1.0f };
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
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
    glMateriali(GL_FRONT,GL_SHININESS,64);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("World");
	glutReshapeFunc(resize);
	glutDisplayFunc(displayMe);
	glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(normalKeys);
	setup();
	glutMainLoop();
	return 0;
}