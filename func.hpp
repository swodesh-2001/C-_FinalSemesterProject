#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14159
#include <stdlib.h>
#include <string>
using namespace std;

bool draw[100][100];
void display();
void reshape(int,int);
void timer(int);

float x_co[100][10000];
float y_co[100][10000];
int size_of_pen[100][10000]={5};
float pen_red[100][10000]={1};
float pen_green[100][10000]={1};
float pen_blue[100][10000]={1};
int taken_pen;


bool clicked=false;
bool draweraser[100][100];

void init(){
glClearColor(0,0,0,1.0);
}

float bgr=0,bgg=0,bgb=0;

int a,b;

float red=1;
float green=1;
float blue=1;

float exitr=0.8;
float exitg=0.8;
float exitb=0.8;

void create_square(float x,float y ,int w = 20, int h = 20 , float r=1 ,float g = 1 ,float b = 1 ){
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
void create_pen(float x , float y, float width=5,float r=1 , float g=1, float b=1)
{
    glPointSize(width);
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();

}

void create_real_pen(float x , float y,float r=1 , float g=1, float b=1)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+8,y-24);
    glVertex2f(x+32,y-40);
    glVertex2f(x+43,y-26);
    glVertex2f(x+23,y-4);
    glVertex2f(x,y);

    glEnd();

}

void create_eraser(float x , float y,float r=1 , float g=1, float b=1)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y);
    glVertex2f(x+40,y);
    glVertex2f(x+40,y+30);
    glVertex2f(x,y+30);
    glVertex2f(x,y);

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

void cross(int x, int y, float scale=1, float r=1, float g=0,float b=0)
{
 glColor3f(r,g,b);
 glBegin(GL_LINES);
 glVertex2f(x,y);
 glVertex2f(x+30*scale,y+15*scale);
 glVertex2f(x+30*scale,y);
 glVertex2f(x,y+15*scale);
 glEnd();
}

void create_circle(int x,int y ,float radius, float r=1, float g=1,float b=1, int line_width=5){
glColor3f(r,g,b);
float x1,y1;
glBegin(GL_POLYGON);
for (int i=0;i<360;i++)
{
    x1=x+radius*cos(PI*i/180);
    y1=y+radius*sin(PI*i/180);
    glVertex2f(x1,y1);
}

glEnd();
}

void create_nepal(int x=100 , int y=100 , int scale = 10 ){
 //outer_strip
 if (scale < 2){

     glBegin(GL_POLYGON);

 glColor3f(red,green,blue);
 glVertex2d(x,y);
 glVertex2d(x,scale*45+y);
 glVertex2d(x+scale*1,scale*45+y);
 glVertex2d(x+scale*1,scale*30+y);
 glVertex2d(x+scale*25,scale*30+y);
 glVertex2d(x+scale*7,scale*15+y);
 glVertex2d(x+scale*17,scale*15+y);
 glEnd();
 }
 else{ glBegin(GL_POLYGON);

 glColor3f(0,0,1);
 glVertex2d(x,y);
 glVertex2d(x,scale*45+y);
 glVertex2d(x+scale*1,scale*45+y);
 glVertex2d(x+scale*1,scale*30+y);
 glVertex2d(x+scale*25,scale*30+y);
 glVertex2d(x+scale*7,scale*15+y);
 glVertex2d(x+scale*17,scale*15+y);
 glEnd();

 //outer_strip
 glBegin(GL_POLYGON);
 glColor3f(1,0,0);
 glVertex2d(x+5,y+15);
 glVertex2d(5+x,scale*30+y - 5);
 glVertex2d(x+scale*25 - 15,scale*30+y - 5);
 glVertex2d(x+scale*7 - 10 ,scale*15+y - 5 );
 glVertex2d(x+scale*17 - 10,scale*15+y - 5);
 glEnd();


 create_square(x+45,y+230,29,29,1,1,1);
 glBegin(GL_POLYGON);
 glColor3f(1,1,1);
 glVertex2d(x+60,y+225);
 glVertex2d(x+40,y+245);
 glVertex2d(x+60,y+265);
 glVertex2d(x+80,y+245);
 glEnd();

 y=y-120;
 create_square(x+46,y+231,22,22,1,1,1);
 glBegin(GL_POLYGON);
 glColor3f(1,1,1);
 glVertex2d(x+58,y+227);
 glVertex2d(x+42,y+243);
 glVertex2d(x+58,y+258);
 glVertex2d(x+73,y+243);
 glEnd();



float x1,y1;
glBegin(GL_POLYGON);
glColor3f(1,1,1);
for (int i=0;i<180;i++)
{
    x1=x+58+25*cos(PI*i/180);
    y1=y+245+15*sin(PI*i/180);
    glVertex2f(x1,y1);
}
glEnd();
}


}


void instructions(int i ){
system("CLS");
switch(i){
    case 0 :
        cout <<  "******************RECTANLGE*************" << endl;
        cout << "AFTER SELECTING OBJECT, PRESS : " << endl;
        cout << "\na to reduce size" << endl;
        cout << "\ns to increase size" << endl;
        cout << "\nu to make it unfilled object" << endl;
        cout << "\np and o to change unfilled line thickness" << endl;
        cout << "\nf to make it filled object" << endl;
        cout << "\nr to make it RED" << endl;
        cout << "\ng to make it green" << endl;
        cout << "\ny to make it yellow" << endl;
        cout << "\nb to make it blue" << endl;
        cout << "\n1 and 2 to change length" << endl;
        cout << "\n3 and 4 to change breadth" << endl;
        cout << "*******************************************" << flush;
        break;


     case 1 :
        cout <<  "******************SQUARE*************" << endl;
        cout << "AFTER SELECTING OBJECT, PRESS : " << endl;
        cout << "\na to reduce size" << endl;
        cout << "\ns to increase size" << endl;
        cout << "\nu to make it unfilled object" << endl;
        cout << "\np and o to change unfilled line thickness" << endl;
        cout << "\nf to make it filled object" << endl;
        cout << "\nr to make it RED" << endl;
        cout << "\ng to make it green" << endl;
        cout << "\ny to make it yellow" << endl;
        cout << "\nb to make it blue" << endl;
        cout << "*******************************************" << flush;
        break;


     case 2 :
        cout <<  "******************TRIANGLE*************" << endl;
        cout << "AFTER SELECTING OBJECT, PRESS : " << endl;
        cout << "\na to reduce size" << endl;
        cout << "\ns to increase size" << endl;
        cout << "\nu to make it unfilled object" << endl;
        cout << "\np and o to change unfilled line thickness" << endl;
        cout << "\nf to make it filled object" << endl;
        cout << "\nr to make it RED" << endl;
        cout << "\ng to make it green" << endl;
        cout << "\ny to make it yellow" << endl;
        cout << "\nb to make it blue" << endl;
        cout << "\n1 and 2 to change length" << endl;
        cout << "\n3 and 4 to change height" << endl;
        cout << "*******************************************" << flush;
        break;


     case 3 :
        cout <<  "******************CIRCLE*************" << endl;
        cout << "AFTER SELECTING OBJECT, PRESS : " << endl;
        cout << "\na to reduce size" << endl;
        cout << "\ns to increase size" << endl;
        cout << "\nu to make it unfilled object" << endl;
        cout << "\np and o to change unfilled line thickness" << endl;
        cout << "\nf to make it filled object" << endl;
        cout << "\nr to make it RED" << endl;
        cout << "\ng to make it green" << endl;
        cout << "\ny to make it yellow" << endl;
        cout << "\nb to make it blue" << endl;

        cout << "*******************************************" << flush;
        break;


     case 4 :
        cout <<  "******************PEN*************" << endl;
        cout << "\n USE right mouse button to start drawing" << endl;
        cout << "\n Now use middle mouse button to either pause or continue drawing " << endl;
        cout << "\nYou can use capital T to do the same function as middle mouse button" << endl;
        cout << "\n a to reduce size" << endl;
        cout << "\n s to increase size" << endl;


        cout << "\nr to make it RED" << endl;
        cout << "\ng to make it green" << endl;

        cout << "\nb to make it black" << endl;


        cout << "*******************************************" << flush;
        break;

        case 5 :
        cout <<  "******************NEPAL FLAG*************" << endl;
        cout << "\nYOU CAN STAMP 5 NEPAL FLAGS CLICK RIGHT BUTTON TO PLACE FLAG" << endl;
        cout << "*******************************************" << flush;
        break;

     case 6 :
        cout <<  "******************ERASER*************" << endl;
        cout << "Click right button to start erasing" << endl;
        cout << "\nUse capital T or middle mouse button to erase " << endl;
        cout << "*******************************************" << flush;
        break;

}
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
