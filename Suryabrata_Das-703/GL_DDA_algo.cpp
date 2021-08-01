#include<iostream>
#include<cstdlib>
using namespace std;

#include<windows.h>
#include<GL/glut.h>

int   x1,y3,x2,y2;

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    int  dx,dy,step,xin,yin,x,y;
    
    dx=x2-x1;
    dy=y2-y3;


 if (abs(dx)>=abs(dy)){
     

     step=abs(dx); 
 }
 else
     step=abs(dy); 

xin =dx/(float)step;
yin= dy/(float)step;

x=x1;
y=y3;
glBegin(GL_POINTS);

 glVertex2i(x,y);
  glEnd();

 glBegin(GL_POINTS);
for (int i=1;i<= step;i++){
    
    x=x+xin;
    y=y+yin;
    
    glColor3f(0.0,0.0,1.0);
    glVertex2f(x,y);
    
}
glEnd();
glFlush();


}
void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

int main (int argc,char ** argv){
    
    cout << " give X1:";
    cin >> x1;
    cout << " give y3:";
    cin >> y3;
    cout << " give X2:";
    cin >> x2;
    cout << " give y2:";
    cin >> y2;

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("DDA Line");
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500); 
    init() ;
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}