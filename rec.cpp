#include <GL/glut.h>


void myDisplay1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glFlush();
}

void myDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f,-1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
  glEnd();
  glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Draw a rectangle");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
