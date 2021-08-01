#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int xc = 0, yc = 0;
int r;

void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void bresenham_circle()
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  plot_point(x,y);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}

void circles(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  bresenham_circle();
}

void Init()
{
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(0.0,1.0,0.5);
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  printf("Enter the origin(x,y): ");
  scanf("%d%d",&xc,&yc);
  printf("Enter the radius of the circle: ");
  scanf("%d",&r);
  glutCreateWindow("Bresenham_Circle");
  Init();
  glutDisplayFunc(circles);
  glutMainLoop();
  return 0;
}

/*
Compile: g++ main.cpp -o main -lglut -lGLU -lGL
*/
