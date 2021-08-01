# include <windows.h>
# include<GL/glut.h>

void display(){

    glClearColor(0.0f,0.0f,0.0f,0.0f); //it helps to set the backgroud color
    glClear(GL_COLOR_BUFFER_BIT);//it clars the buffer that contents color of the window

    glBegin(GL_QUADS); // each set of 4 vertices from a quad 
    glColor3f(1.0f,0.0f,0.0f); // red 
    glVertex2f(-0.5f,-0.5f);// (x,y)
    glVertex2f(0.5f,-0.5f);
    glVertex2f(0.5f,0.5f);
    glVertex2f(-0.5f,0.5f);
    glEnd();  // For ending  glBegin()
    glFlush(); // render now
}
 /* Main function: GLUT runs as a console application starting at main()  */
int main(int argc ,char **argv){

    glutInit(&argc,argv); // initialize Glut 
    glutCreateWindow("opengl First program");  //creating name of window 
    glutInitWindowPosition(50,50); //  screen postion  where it will show 
    glutInitWindowSize(120,120); // the window size 
    glutDisplayFunc(display);  //register the diplay fuction to re-paint window 
    glutMainLoop(); // Enter event-processing loop
    return 0;
}
