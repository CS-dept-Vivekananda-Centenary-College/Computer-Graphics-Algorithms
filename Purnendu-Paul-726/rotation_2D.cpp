/* Name - Purnendu Paul 
   Roll No. - 726
   CC-14 Computer Graphics
 */

#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;
int n=3;

float *x = NULL;
float *y = NULL;

float xR,yR;

float theta=0;

void fill(float xt,float yt, int i){
	x[i] = xt;
	y[i] = yt;
}

void displayRot(void){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glBegin(GL_POLYGON);
		for(int i=0;i<n;i++){
			glColor3f(rand()%10, rand()%10, rand()%10);
			float trX = xR  + ((x[i]-xR)*cos(theta*3.14159/180)) - ((y[i]-yR)*sin(theta*3.14159/180));
			float trY = yR + ((x[i]-xR)*sin(theta*3.14159/180)) + ((y[i]-yR)*cos(theta*3.14159/180));
			glVertex2f(trX,trY);
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
			glVertex2f(x[i], y[i]);
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
         displayRot();
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
    
    for (int i=0;i<n;i++){
		cout<<"Enter the co-ordinate values(x,y) of the vertex"<<i+1<<": ";
		float tempx,tempy;
		cin>>tempx>>tempy;
		fill(tempx,tempy,i);
	}
	cout<<"\n\nCLICK THE LEFT BUTTON TO ROTATE\n\n";
	
	cout<<"Enter the rotational angle(theta): ";
	cin>>theta;
	
	cout<<"Enter the rotational point: ";
	cin>>xR>>yR;
	 
    glutCreateWindow ("2D Rotation"); 
    init(); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutMouseFunc(mouse);
    glutMainLoop();
    delete x;
	delete y;
    return 0;
}