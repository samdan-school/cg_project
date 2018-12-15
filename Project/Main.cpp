#include <GL/glut.h>

#include <iostream>

#include <math.h> /* sin cos */

#include "ReadFile.h"

int main(int argc, char **argv)
{
	/*
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circle");
	glutDisplayFunc(displayMe);

	// Keyborad func
	glutKeyboardFunc(keyPressed);
	glutSpecialFunc(SpecialInput);
	glutMainLoop();
	*/
	ReadFromFile(".\\Baishin\\residence.obj", ".\\Baishin\\residence.txt");

	system("pause");

	return 0;
}