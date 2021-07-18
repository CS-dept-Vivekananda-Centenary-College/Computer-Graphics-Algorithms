/*
Name: Soumya Das
Roll No.: 707
Subject: CC-14 Computer Graphics
Program: Write a program to implement Midpoint Ellipse Drawing Algorithm
*/
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

#define ROUND(a) ((int)(a+0.5))

int xCenter, yCenter, rx,ry;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
void ellipsePlotPoints(int xCenter, int yCenter, int x, int y){
    plot(xCenter + x, yCenter + y);
    plot(xCenter - x, yCenter + y);
    plot(xCenter - x, yCenter - y);
    plot(xCenter + x, yCenter - y);
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry){
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;

    ellipsePlotPoints(xCenter, yCenter, x, y);

    p = ROUND(Ry2 - (Rx2 * Ry)+ (0.25 * Rx2));
    while(px < py){
        x++;
        px += twoRy2;
        if(p < 0){
            p+= Ry2 + px;
        }
        else{
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints(xCenter,yCenter,x,y);
    }

    p = ROUND(Ry2 * (x + 0.5)* (x + 0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
    while(y > 0){
        y--;
        py -= twoRx2;
        if(p  > 0){
            p += Rx2 - py;
        }
        else{
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        ellipsePlotPoints(xCenter,yCenter,x,y);
    }
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glPointSize(1.0);

	ellipseMidpoint(xCenter, yCenter, rx,ry);

	glFlush ();
}

int main(int argc, char** argv)
{	
	
    cout << "Enter the coordinates of the center(xCenter, yCenter): " << endl;
    cin>>xCenter>>yCenter;

    cout<<"Enter the length of axis along x-axis: ";
    cin>>rx;

    cout<<"Enter the length of axis along y-axis: ";
    cin>>ry;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Midpoint Circle Drawing Algorithms");
	myInit ();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

}