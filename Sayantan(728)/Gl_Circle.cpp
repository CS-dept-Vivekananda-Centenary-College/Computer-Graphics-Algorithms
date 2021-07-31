#include<windows.h>
#include <GL/glut.h>
#include<math.h>

void display (int cx,int cy, int r, int num_segments ){
    glClearColor(0.0f,0.0f,0.0f,0.1f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<= num_segments ;i++){
        float theta = 2.0f * 3.14 *float(i)/float(num_segments);
        float x= r+cos(theta);
        float y=r+sin(theta);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(x+cx,y+cy);      


    }
    glEnd();
    glFlush();

      
}
void main_loop_function (){
    display(0,0,0.7,100);

}
int main(int argc, char ** argv){
    glutInit(&argc,argv);
    glutCreateWindow("Circle");
    glutInitWindowSize(120,120);
    glutInitWindowPosition(100,100);
    glutDisplayFunc(main_loop_function);
    glutMainLoop();
    return 0;
}