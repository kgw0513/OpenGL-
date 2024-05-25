#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"
#include <math.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//I

	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

	glColor3f(1, 1, 0);
	glutWireTeapot(0.5); 
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("OpenGL Example");

	glClearColor(0, 0, 0, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1, 1, -1, 1, -1, 0.8); 평행 투상
	//glFrustum(-0.2, 0.2, -0.2, 0.2, 0.1, 0.8); //원근 투상 gl
	gluPerspective(90, 1, 0.1, 10); // 원근 투상 glu 

	glutDisplayFunc(MyDisplay);

	glutMainLoop();
}
