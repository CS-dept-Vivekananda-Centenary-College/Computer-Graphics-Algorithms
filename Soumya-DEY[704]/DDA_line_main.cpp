/*
Name: SOUMYA DEY
Roll No.: 704
Subject:- CMSA CC-14, Computer Graphics Lab
*/

#include<GL/glut.h>
#include<iostream>
using namespace std;
float x1, x2, y1, y2;
 
void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void display(void)
{
    float dy,dx,step,x,y,k,Xin,Yin;
    dx=x2-x1;
    dy=y2-y1;
    
    if(abs(dx)> abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    
    Xin = dx/step;
    Yin = dy/step;
    
    x = x1;
    y = y1;

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
    cin>>x1>>y1;
    cout<<"Enter the value of (x2,y2) : ";
    cin>>x2>>y2;
 
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}