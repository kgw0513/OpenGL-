#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "bunnymodel.h"

GLint timer = 10;

GLfloat X=0,Y=0,R=0,Z=1;
void MyDisplay() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0, 0.6, 0.8);
   //glLoadIdentity();
   glRotatef(R, X, Y, Z);
   glBegin(GL_LINES);
   {
      for (int i = 0; i < sizeof(face_indicies) / sizeof(face_indicies[0]); i++) {
         int vi = face_indicies[i][0]; glVertex3fv(vertices[vi]);
         vi = face_indicies[i][1]; glVertex3fv(vertices[vi]);
         vi = face_indicies[i][1]; glVertex3fv(vertices[vi]);
         vi = face_indicies[i][2]; glVertex3fv(vertices[vi]);
         vi = face_indicies[i][2]; glVertex3fv(vertices[vi]);
         vi = face_indicies[i][0]; glVertex3fv(vertices[vi]);
      }
   }
   glEnd();
   glFlush();
}

void MyTimer(int value) {
   R = 5;
   X = int(X + 1) % 360;
   Y = Y + 0.5;
   if (Y >= 360)Y -= 360;
   /*
   R += 5;
   R =int(R)% 360;
   printf("%f\n", R);
   */
   glutPostRedisplay();
   glutTimerFunc(100, MyTimer, 1);
}
int main(int argc, char* argv[])
{
   glutInit(&argc, argv);
   glutCreateWindow("Hello");

   glutDisplayFunc(MyDisplay);
   glutTimerFunc(100,MyTimer,1);

   glutMainLoop();
}
