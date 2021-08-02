/*
Name:- Anubrata Das
Roll No. 720
Subject:- CC-14 Computer Graphics
Write a Program to draw a Square
*/
#include <cstdlib>

#include <GL/glut.h>
#include <GL/freeglut.h>

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,30.0,0.0,35.0,-1.0,1.0);
}

void mydisplay(void){
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
        glColor3f(0.0f,1.0f,1.0f);
        glVertex3f(5.0f,5.0f,0.0f);
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f(5.0f,25.0f,0.0f);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(25.0f,25.0f,0.0f);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(25.0f,5.0f,0.0f);
        glEnd();
    glutSwapBuffers();
    glFlush();
}
void mouse(int button, int state, int x,int y){
    x =0;
    y=0; 
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(800,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("SQUARE");
    init();
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;

}
