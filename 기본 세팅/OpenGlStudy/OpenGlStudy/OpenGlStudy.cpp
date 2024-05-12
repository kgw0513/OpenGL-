#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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

	glColor3f(1, 0, 0);
	glutWireTeapot(0.3);

	glPushMatrix();
	{
		glTranslatef(2.0, 2.0, 0);
		glutWireTeapot(0.3);

		glPushMatrix();
		{
			glTranslatef(3, -1, 0);
			glScalef(2, 2, 2);
			glRotatef(45, 0, 0, 1);
			glutWireTeapot(0.3);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glTranslatef(0, -2, 0);
	glutWireTeapot(0.3);

	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("OpenGL Example");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-6, 6, -6, 6, -1, 1);

	glutDisplayFunc(MyDisplay);

	glutMainLoop();
}