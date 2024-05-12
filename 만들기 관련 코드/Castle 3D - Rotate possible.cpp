#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"

GLint xValue, yValue, zValue;

GLint RemX, RemY;
GLint EndX, EndY;
bool RemStart = false;
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//I

	xValue %= 360;
	yValue %= 360;
	zValue %= 360;
	glRotatef(xValue + EndX, 1, 0, 0);
	glRotatef(yValue + EndY, 0, 1, 0);
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
	case 32:
		xValue = 0;
		yValue = 0;
		zValue = 0;
		break;
	}

	glutPostRedisplay();
}

void MyMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			RemX = x;
			RemY = y;
			EndX = x;
			EndY = y;
			RemStart = true;
		}
		else if (state == GLUT_UP) {
			xValue += EndX;
			yValue += EndY;
			RemX = 0;
			RemY = 0;
			EndX = 0;
			EndY = 0;
			RemStart = false;
			glutPostRedisplay();
		}
	}
}

void MyMotion(int x, int y) {
	//printf("%d %d\n", x, y);
	if (RemStart) {
		EndY = x - RemX;
		EndX = y - RemY;

		glutPostRedisplay();
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("OpenGL Example");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouse);
	glutMotionFunc(MyMotion);

	glutMainLoop();
}
