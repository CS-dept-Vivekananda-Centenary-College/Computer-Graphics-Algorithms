#include <GL/glut.h> 
#include<math.h>
#include<iostream>
using namespace std;

int  r;

void setcirpot(float x,float y){
	//The default circle center (0, 0)
	glBegin(GL_POINTS);
	glColor3f(1,0,0); 
	glVertex2f(x/1000,y/1000);
	glVertex2f(y/1000,x/1000);
	glVertex2f(x/1000,-y/1000);
	glVertex2f(y/1000,-x/1000);
	glVertex2f(-x/1000,-y/1000);
	glVertex2f(-y/1000,-x/1000);
	glVertex2f(-y/1000,x/1000);
	glVertex2f(-x/1000,y/1000);
	glEnd();
}
int Mid_circle(float r)
{
	glClear(GL_COLOR_BUFFER_BIT);
	float x,y,d;
	x=0;
	y=r;
	d=1-r;
	setcirpot(x,y);
	while(x<=y){
		if(d<=0){
			d=d+2*x+3;
		}
		else{
			d=d+2*(x-y)+5;
			y--;
		}
		x++;
		setcirpot(x,y);
	}
	glFlush();  
}
  

void display(void){ 
	 
	 Mid_circle(r);
}

int main(int argc, char **argv) { 
     glutInit(&argc, argv); //Initialize glut
     glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA); 
     // give input for radius 
     cout<<"Please input r"<<endl;
     cin>>r; 
	
     glutInitWindowPosition(200,200); //Set the position of the window
     glutInitWindowSize(400,400); //Set the size of the window
     glutCreateWindow("Midpoint algo"); //Create window and assign title
     glutDisplayFunc(display);//Call display to transfer the drawing to the window. The prototype of this function is glutDisplayFunc(void)
     glutMainLoop(); //Enter the loop and wait
}
