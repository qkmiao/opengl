#include <GL/glut.h>
#include <math.h>


void myDisplay1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    glFlush();
}

void myDisplay2()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f,-1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
  glEnd();
  glFlush();
}

void circle()
{
  int i;
  const int n = 200;
  const GLfloat R = 0.5f;
  const GLfloat Pi = 3.1415926536f;
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    for(i=0; i<n; i++)
      glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
  glEnd();
  glFlush();
}

void solidLine()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(5.0f);
  glLineWidth(5.0f);
  glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
  glEnd();
  glFlush();
}

void square()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式
    glPolygonMode(GL_BACK, GL_LINE);  // 设置反面为线形模式
    glFrontFace(GL_CW);              // 设置逆时针方向为正面
    glBegin(GL_POLYGON);              // 按逆时针绘制一个正方形，在左下方
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, -0.5f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);              // 按顺时针绘制一个正方形，在右上方
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, 0.0f);
    glEnd();
    glFlush();
}

void myDisplay()
{
  //solidLine();
  //circle();
  square();
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
