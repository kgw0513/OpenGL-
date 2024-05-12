티 주전자를 가지고 기초 공부 코드
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
void MyDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.7f, 0.2f, 1.f);
   glutWireTeapot(0.5f);
   glFlush();
}

int main(int argc, char* argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(250, 200);

   glutCreateWindow("Hello");
   glutSetWindowTitle("Is Teapot");

   glutDisplayFunc(MyDisplay);

   glutMainLoop();
}
