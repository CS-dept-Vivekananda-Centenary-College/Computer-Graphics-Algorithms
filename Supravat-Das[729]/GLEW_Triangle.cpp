/*
Name: Supravat Das
Roll No.: 729
Subject:- CMSA CC-14, Computer Graphics.
*/

#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>
#include <GL/freeglut.h>

void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void reshape(int x, int w){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 30.0, 0.0, 35.0, -1.0, 1.0);
    //gluOrtho2D(500,500,0,0);
}


void mydisplay(void){
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glPointSize(5.0);
    glTranslated(0.5,0.6,0.0);
    glRotatef(45,0,0.0,0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(5.0f, 5.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(25.0f, 5.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(15.0f, 15.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glFlush ();
    glutSwapBuffers();

}

void mouse(int button, int state, int x, int y){
    x=0; y=0;
    state =0;

    if(button==GLUT_LEFT_BUTTON)
    {
        exit(0);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE|GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Triangle");
    init();
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}