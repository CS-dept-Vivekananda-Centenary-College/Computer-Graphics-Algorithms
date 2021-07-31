#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>

float x1,x2,y1,y2;
 
void display(void) {
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    float dx,dy,x,y;
    dx = x2 - x1;
    dy = y2 - y1;

    float step;

    if(abs(dx)>abs(dy)) step = abs(dx);
    else step = abs(dy);

    float x_inc = dx/step;
    float y_inc = dy/step;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
        glVertex2i(int(x),int(y));
    glEnd();

    
    for (int k=1 ;k<=step;k++) {
        x += x_inc;
        y += y_inc;
        
        glBegin(GL_POINTS);
        glVertex2i(int(x),int(y));
        glEnd();
    }   
    

    glFlush ();
    glutSwapBuffers();
}
 
void init (void){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);

}
 
int main(int argc, char** argv) {
    printf("Enter the value of x1 : ");
    scanf("%f",&x1);
    printf("Enter the value of y1 : ");
    scanf("%f",&y1);
    printf("Enter the value of x2 : ");
    scanf("%f",&x2);
    printf("Enter the value of y2 : ");
    scanf("%f",&y2);
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

/*
Compile: g++ main.cpp -o main -lglut -lGLU -lGL
*/
