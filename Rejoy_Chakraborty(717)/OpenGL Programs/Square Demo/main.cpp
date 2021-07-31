#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>
#include <GL/freeglut.h>

void display(void){
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(10.0f, 20.0f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(20.0f, 20.0f, 0.0f);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(20.0f, 10.0f, 0.0f);
        glColor3f(1.0f, 3.0f, 1.0f);
        glVertex3f(10.0f, 10.0f, 0.0f);
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
    x=0; y=0; //Position of pointer
    state =0; //Status of Scroll of mouse

    if(button==GLUT_LEFT_BUTTON) //If click left button then window will close
    {
        exit(0);
    }
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv); //It initiates the OpenGL Engine
    glutInitDisplayMode ( GLUT_DOUBLE|GLUT_DEPTH | GLUT_RGBA); 

    /* GLUT_DOUBLE: It creates two separate buffer for foreground and background pixel
        GLUT_DEPTH: It measures the depth of the image as GLUT_DOUBLE needs the depth
        GLUT_RGBA: It defines the colour model i.e here RGB color model with Alpha Channel
    */

    glutInitWindowSize (500, 400); //Window Size
    glutInitWindowPosition (100, 100); //Window Position on my screen
    glutCreateWindow ("Square"); //Window Name
    init(); //Calling init() method
    glutDisplayFunc(display); //Display in Window
    glutReshapeFunc(reshape); //Reshaping function calling
    glutMouseFunc(mouse); //Mouse Opertion Call

    glutMainLoop();
    return 0;
}

/*
Compile: g++ main.cpp -o main -lglut -lGLU -lGL
*/
