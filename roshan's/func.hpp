#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14159
#include <vector>
#include <string>
using namespace std;




void display();
void reshape(int,int);
void timer(int);


void init(){
glClearColor(0,0,0,1.0);
}


int a,b;

void create_square(float x,float y ,int w = 20, int h = 20 , float r=1 ,float g = 1 ,float b = 1){
glBegin(GL_QUADS);
float xl,xh,yl(y),yh;
yh = yl + h;
xl=x;
xh = xl + w;
glColor3f(r,g,b);
glVertex2f(xl,yl);
glVertex2f(xh,yl);
glVertex2f(xh,yh);
glVertex2f(xl,yh);
glEnd();
}


void create_triangle(float x,float y ,int w = 20, int h = 20 , float r=1 ,float g = 1 ,float b = 1){
glBegin(GL_TRIANGLES);
float xl,xh,xh1,yl(y),yh;
yh = yl + h;
xl=x;
xh = xl + w;
xh1 = xl - w;
glColor3f(r,g,b);
glVertex2f(xl,yl);
glVertex2f(xh,yh);
glVertex2f(xh1,yh);
glEnd();
}


void create_square(int x , int y,float size=1.0,float r=1,float g=1, float b=1){
create_square(x,y,size*50,size*50,r,g,b);
}

void create_rectangle(int x , int y,float size=1,float r=1,float g=1,float b=1){
    create_square(x , y , size*50 , size*20 ,r,g,b);
}

void create_triangle(int x , int y,float size=1.0,float r=1,float g=1, float b=1){
create_triangle(x,y,size*20,size*40,r,g,b);
}


void create_line(float x1,float y1 ,float x2,float y2){
glBegin(GL_QUADS);
glColor3f(1,1,1);
glVertex2f(x1+2,y1+2);
glVertex2f(x1-2,y1-2);
glVertex2f(x2+2,y2-2);
glVertex2f(x2-2,y2+2);
glEnd();
}




void reshape(int w,int h){

glViewport(0,0,w,h);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);
glMatrixMode(GL_MODELVIEW);

}


void timer(int ){

glutPostRedisplay();

glutTimerFunc(1000/60.,timer,0);
}