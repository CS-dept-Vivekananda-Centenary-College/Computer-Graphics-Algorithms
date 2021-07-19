/*
Name:- Arpan Singha
Roll No. 727
Subject:- CC-14 Computer Graphics

Program: Write a program to implement 3D Translation on 3D object
*/
#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int n=3;

float *x = NULL;
float *y = NULL;
float *z = NULL;

float tx=0,ty=0,tz=0;

void fill(float xt,float yt, float zt,int i){
	x[i] = xt;
	y[i] = yt;
	z[i] = zt;
}

void displayTranslated(void){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glBegin(GL_POLYGON);
		for(int i=0;i<n;i++){
			glColor3f(rand()%10, rand()%10, rand()%10);
			glVertex3f(x[i]+tx, y[i]+ty,z[i]+tz);
		}
		glEnd();
		glFlush ();
		glutSwapBuffers(); 
}

void display(void){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glBegin(GL_POLYGON);
		for(int i=0;i<n;i++){
			glColor3f(rand()%10, rand()%10, rand()%10);
			glVertex3f(x[i], y[i],z[i]);
		}
		glEnd();
		glFlush ();
		glutSwapBuffers();
}

void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void reshape(int x, int w){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 30.0, 0.0, 35.0, -1.0, 1.0);
}

void mouse(int button, int state, int x, int y){
    x=0; y=0;
    state =0;

    if(button==GLUT_LEFT_BUTTON)
    {	
         displayTranslated();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode ( GLUT_DOUBLE|GLUT_DEPTH | GLUT_RGBA); 

    glutInitWindowSize (500, 400); 
    glutInitWindowPosition (0, 0);
    
    cout<<"Enter the number of vertices of the polygon: ";
	cin>>n;
    x = new float[n];
    y = new float[n];
    z = new float[n];
    
    for (int i=0;i<n;i++){
		cout<<"Enter the co-ordinate values(x,y,z) of the vertex "<<i+1<<": ";
		float tempx,tempy,tempz;
		cin>>tempx>>tempy>>tempz;
		fill(tempx,tempy,tempz,i);
	}
	
	printf("\n\nCLICK THE LEFT BUTTON TO TRANSLATE\n\n");
	
	cout<<"Enter the translation vector values(tx,ty,tz): ";
	cin>>tx>>ty>>tz;
     
    glutCreateWindow ("3D Translation"); 
    init(); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutMouseFunc(mouse);
    glutMainLoop();
    delete x;
	delete y;
	delete z;
    return 0;
}
