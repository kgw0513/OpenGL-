#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//I

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
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("OpenGL Example");

	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glutDisplayFunc(MyDisplay);

	glutMainLoop();
}
