/* Name - Arkadip Maitra 
   Roll No. - 725
   CC-14 Computer Graphics
 */

#include<GL/glut.h>
#include<iostream>
using namespace std;
float x_1, x_2, y_1, y_2;
 
void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void display(void)
{
    float dy,dx,step,x,y,k,Xin,Yin;
    dx=x_2-x_1;
    dy=y_2-y_1;
    
    if(abs(dx)> abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    
    Xin = dx/step;
    Yin = dy/step;
    
    x = x_1;
    y = y_1;

    draw_pixel(x,y);
    
    for (k=1 ;k<=step;k++)
    {
        x= x + Xin;
        y= y + Yin;
        
        draw_pixel(x,y);
    }
    glFlush();
}
 
void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}
 
int main(int argc, char** argv) {
    cout<<"Enter the value of (x1,y1) : ";
    cin>>x_1>>y_1;
    cout<<"Enter the value of (x2,y2) : ";
    cin>>x_2>>y_2;
 
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("Digital Differential Analyzer Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}