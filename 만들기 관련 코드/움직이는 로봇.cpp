#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"
#include <math.h>

double time = 0;

GLfloat HeadAngle = 0.0f;
GLfloat armAngleL = 0.0f;
GLfloat armAngleR = 0.0f;
GLfloat legAngleL = 0.0f;
GLfloat legAngleR = 0.0f;
GLfloat BodyRotate = 0.0f;
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//I

	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);

	glBegin(GL_LINES); //xyz
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0,0); glVertex3f(10, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
	}
	glEnd();

	glRotatef(BodyRotate, 0, 1, 0);
	glTranslatef(-2, 0, 0);

	glPushMatrix(); //상반신
	{
		glTranslatef(0, 1, 0);

		glColor3f(0, 0, 1);
		glutSolidCube(2); //몸통 (파란색)

		glPushMatrix(); //왼팔 (녹색)
		{
			glTranslatef(0, 1, 0);
			glRotatef(armAngleL, 1, 0, 0);
			glTranslatef(1.5, -1, 0);

			glPushMatrix(); //손 (검은색)
			{
				glColor3f(0, 0, 0);
				glTranslatef(0, -1.4, 0);
				glutSolidSphere(0.3, 20, 8);
			}
			glPopMatrix();

			glColor3f(0, 1, 0);

			glScalef(1, 4, 1);
			glutSolidCube(0.5);
		}
		glPopMatrix();

		glPushMatrix(); //오른팔 (노란색)
		{
			glTranslatef(0, 1, 0);
			glRotatef(armAngleR, 1, 0, 0);
			glTranslatef(-1.5, -1, 0);

			glPushMatrix(); //손 (검은색)
			{
				glColor3f(0, 0, 0);
				glTranslatef(0, -1.4, 0);
				glutSolidSphere(0.3, 20, 8);
			}
			glPopMatrix();

			glColor3f(1, 1, 0);

			glScalef(1, 4, 1);
			glutSolidCube(0.5);
		}
		glPopMatrix();

		glPushMatrix(); //머리 (주전자 빨강)
		{
			glColor3f(1, 0, 0);
			glTranslatef(0, 1.8, 0);
			glRotatef(-90, 0, 1, 0);
			glRotatef(HeadAngle, 0, 1, 0);
			glutSolidTeapot(0.8);
		}
		glPopMatrix();

		
	}
	glPopMatrix();
	
	glPushMatrix(); //하반신
	{
		glTranslatef(0, -2, 0);

		glPushMatrix();//왼다리
		{
			glTranslatef(0, 2, 0);
			glRotatef(legAngleL, 1, 0, 0);
			glTranslatef(0.5, -2, 0);
			
			glPushMatrix(); //발 (검은색)
			{
				glColor3f(0, 0, 0);
				glTranslatef(0, -2.4, 0);
				glutSolidCube(0.5);
			}
			glPopMatrix();

			glColor3f(0, 1, 1);
			glScalef(0.6, 4, 0.6);
			glutSolidCube(1);
		}
		glPopMatrix();

		glPushMatrix();//오른다리
		{
			glTranslatef(0, 2, 0);
			glRotatef(legAngleR, 1, 0, 0);
			glTranslatef(-0.5, -2, 0);

			glPushMatrix(); //발 (검은색)
			{
				glColor3f(0, 0, 0);
				glTranslatef(0, -2.4, 0);
				glutSolidCube(0.5);
			}
			glPopMatrix();

			glColor3f(0, 1, 1);
			glScalef(0.6, 4, 0.6);
			glutSolidCube(1);
		}
		glPopMatrix();
	}
	glPopMatrix();

	glFlush();
}

void MyTimer(int value) {
	time += value*2 / 10.f;

	HeadAngle += 10;
	while (HeadAngle >= 360)HeadAngle -= 360;
	BodyRotate += 2;
	while (BodyRotate >= 360)BodyRotate -= 360;

	armAngleL = sin(time) * 20;
	armAngleR = -armAngleL;

	legAngleL = cos(time*0.8) * 21;
	legAngleL *= -1;
	legAngleR = -legAngleL;
	glutPostRedisplay();
	glutTimerFunc(50, MyTimer, value);
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
	glOrtho(-10, 10, -10, 10, -20, 20);

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(MyDisplay);
	glutTimerFunc(50, MyTimer, 1);

	glutMainLoop();
}
