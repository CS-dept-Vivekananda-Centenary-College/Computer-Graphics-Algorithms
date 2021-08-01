#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>

int n=3;

float *x = NULL;
float *y = NULL;

float *xr = NULL;
float *yr = NULL;

float xR,yR;

float theta=0;

void fill(float xt,float yt, int i){
	x[i] = xt;
	y[i] = yt;
}

void displayRot(void){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
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
		glBegin(GL_TRIANGLES);
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
    glutInitWindowPosition (100, 100);
    
    x = (float *)calloc(n, sizeof(float));
    y = (float *)calloc(n, sizeof(float));
    
    for (int i=0;i<n;i++){
		printf("Enter the co-ordinate values(x,y) of the %dth vertex: ",i);
		float tempx,tempy;
		scanf("%f%f",&tempx,&tempy);
		fill(tempx,tempy,i);
	}
	printf("\n\nCLICK THE LEFT BUTTON TO TRANSLATE\n\n");
	
	printf("Enter the rotational angle(theta): ");
	scanf("%f",&theta);
	
	printf("Enter the rotational point: ");
	scanf("%f%f",&xR,&yR);
	
	
     
    glutCreateWindow ("Rotation"); 
    init(); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutMouseFunc(mouse);
    glutMainLoop();
    free(x);
    free(y);
    return 0;
}
