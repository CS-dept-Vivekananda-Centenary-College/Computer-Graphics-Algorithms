/* Name - Purnendu Paul 
   Roll No. - 726
   CC-14 Computer Graphics
 */

#include <gl\glut.h>
#include <iostream>
using namespace std;

int X1, X2, Y1, Y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2){
    int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

    if (dx < 0) 
        dx = -dx;
	if (dy < 0) 
        dy = -dy;
	
    incx = 1;
	if (x2 < x1) 
        incx = -1;

	incy = 1;
	if (y2 < y1) 
        incy = -1;
	
    x = x1; 
    y = y1;
    draw_pixel(x, y);
    e = 2*dx-dy;
	inc1 = 2*(dx-dy);
	inc2 = 2*dx;
	if (dx > dy) {
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else{
				e += inc2;
            }
			x += incx;
			draw_pixel(x, y);
		}
	} 
    else {
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else{
				e += inc2;
            }
			y += incy;
			draw_pixel(x, y);
		}
	}
}  

void myDisplay() {
	draw_line(X1, X2, Y1, Y2);
	glFlush();
}

int main(int argc, char **argv) {

	cout<<"Enter the value of (x1,y1) : ";
    cin>>X1>>Y1;
    cout<<"Enter the value of (x2,y2) : ";
    cin>>X2>>Y2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
    return 0;
}