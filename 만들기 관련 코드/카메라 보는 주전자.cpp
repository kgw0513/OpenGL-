#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);

	glRotatef(xValue, 1, 0, 0);
	glRotatef(yValue, 0, 1, 0);
	glRotatef(zValue, 0, 0, 1);

	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex3f(-1, 0, 0); glVertex3f(1, 0, 0);
		glColor3f(0, 1, 0);
		glVertex3f(0, -1, 0); glVertex3f(0, 1, 0);
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, -1); glVertex3f(0, 0, 1);
	}
	glEnd();

	glColor3f(1, 1, 0);
	glutWireTeapot(0.3);
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case 'X':
	case 'x':
		xValue++;
		xValue %= 360;
		break;
	case 'Y':
	case 'y':
		yValue++;
		yValue %= 360;
		break;
	case 'Z':
	case 'z':
		zValue++;
		zValue %= 360;
		break;
	case 'q':
		exit(0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	//glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("OpenGL Example");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -2, 2);

	//glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);

	glutMainLoop();
}
