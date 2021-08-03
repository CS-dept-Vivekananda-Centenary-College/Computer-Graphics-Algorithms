/*
Name: Supravat Das
Roll No.: 729
Subject:- CMSA CC-14, Computer Graphics.
*/
#include<windows.h>
#include<GL/glut.h>


void display(int points,int slope){
glClearColor(0.0,0.0,0.0,0.1);
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_LINES);
for(int i=0;i<=points; i++){
    int x=i;
    int y=slope*x +2;
    glColor3f(0.0,1.0,0.0);
    glVertex2f(x,i);
    glVertex2f(y,y);
    
      
}
glEnd();
glFlush();

}

void recall(){
    display(100,1);
}
int main(int argc, char ** argv){
    glutInit(&argc,argv);
    glutCreateWindow("It's for straight line");
    glutInitWindowPosition(100,100);
    glutInitWindowSize(200,200);
    glutDisplayFunc(recall);
    glutMainLoop();
    return 0;

}