
#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>
#include <GL/freeglut.h>



void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void mydisplay(void){
    for (int j=0;j<=10;j+=1){
        glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glBegin(GL_POLYGON);

            for (int i=0;i<=100;i+=0.01){

                glColor3f(1.0*i, 1.0*i, 0.0f);
                glVertex3i(1+i, 5.0+i, 0.0f);

                glColor3f(0.0f, 0.0f, 1.0*i);
                glVertex3i(2.0+i, 10.0+i, 0.0f);

                glColor3f(0.0f, 1.0*i, 0.0);
                glVertex3i(5.0+i, 10.0+i, 0.0f);

                glColor3f(0.0f, 1.0*i, 1.0*i);
                glVertex3i(6.0+i, 5.0+i, 0.0f);

                glColor3f(1.0*i, 0.0f, 0.0f);
                glVertex3i(5.0+i, 0.0, 0.0f);

                glColor3f(1.0*i, 0.0f, 1.0*i);
                glVertex3i(2.0+i, 0.0f, 0.0f);
            }
        glEnd();

        glFlush ();
    }
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
    glutInitWindowSize (800, 700);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Hexagon Slide");
    init();
    glutDisplayFunc(mydisplay);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}


/**
    g++ hexagonslide.cpp -o hexslide -lglut -lGLU -lGL
    ./hexslide
*/