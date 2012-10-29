#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

GLuint VBO;

struct Vector3f
{
  float x;
  float y;
  float z;
  Vector3f() {}
  Vector3f(float _x, float _y, float _z)
  {
    x = _x;
    y = _y;
    z = _z;
  }
};


static void RenderSceneCB()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glEnableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexPointer(3,GL_FLOAT,0,NULL);
  glDrawArrays(GL_POINTS,0,1);
  glDisableClientState(GL_VERTEX_ARRAY);
  glutSwapBuffers();
}

static void InitializeGlutCallbacks()
{
  glutDisplayFunc(&RenderSceneCB);
}

static void CreateVertexBuffer()
{
  Vector3f vertices[3];
  vertices[0] = Vector3f(-0.9f, -0.9f, 0.0f);
  vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
  vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);
  /*
  vertices[0] = Vector3f(0.6f, 0.6f, 0.0f);
  vertices[1] = Vector3f(0.2f, 0.2f, 0.0f);
  vertices[2] = Vector3f(0.3f, 0.3f, 0.0f);
  */
  glGenBuffers(1,&VBO);
  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int
main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(100,100);

  glutCreateWindow("create window");
  InitializeGlutCallbacks();

  GLenum res = glewInit();
  if(res != GLEW_OK) {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
    return 1;
  }

  glClearColor(0.0f,0.0f,0.3f,0.0f);
  CreateVertexBuffer();
  glutMainLoop();

  return 0;
}
