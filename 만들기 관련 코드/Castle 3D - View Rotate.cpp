#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"
#include <math.h>

GLint xValue;

GLint RemX, RemY;
GLint EndX, EndY;
bool RemStart = false;
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//I

	xValue %= 360;

	gluLookAt(cos(xValue * (3.14) / 180), 1, sin(xValue * (3.14) / 180), 0, 0, 0, 0, 1, 0);

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

	glPushMatrix();
	{
		glTranslatef(0.2, 0, 0);

		glColor3f(1, 0, 0);
		glutSolidCube(0.4);
		glPushMatrix();
		{
			glTranslatef(0.4, 0, 0);
			
			glColor3f(0, 0, 1);
			glutSolidCube(0.4);
			glPushMatrix();
			{
				glTranslatef(0, 0.2, 0);
				glRotatef(90, -1, 0, 0);

				glColor3f(1, 1, 0);
				glutSolidCone(0.2, 0.3, 8, 8);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-0.2, 0, 0);

		glColor3f(1, 0, 0);
		glutSolidCube(0.4);
		glPushMatrix();
		{
			glTranslatef(-0.4, 0, 0);

			glColor3f(0, 0, 1);
			glutSolidCube(0.4);
			glPushMatrix();
			{
				glTranslatef(0, 0.2, 0);
				glRotatef(90, -1, 0, 0);

				glColor3f(1, 1, 0);
				glutSolidCone(0.2, 0.3, 8, 8);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glFlush();
}

void MyKeyboard(unsigned char key,int x,int y) {
	switch (key) {
	case 'X':
		xValue++;
		xValue %= 360;
		break;

	case 'x':
		xValue--;
		xValue = xValue + 360;
		xValue %= 360;
		break;

	case 32:
		xValue = 0;
		break;
	case 'q':
		exit(0);
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("OpenGL Example");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -3, 3);

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);

	glutMainLoop();
}
