#include <GL/glut.h>
#include<cmath>
#define M_PI 3.14
void Draw()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);


        glVertex2f(0,8);
        glVertex2f(3,4);    ///flag
        glVertex2f(2,3);
        glVertex2f(3 ,1);
        glVertex2f(0,1 );

        glEnd();

glColor3f(0,0,1);
        glBegin(GL_POLYGON);


        glVertex2f(0,8);
        glVertex2f(0,0);    //OUTER STRIP
        glVertex2f(-0.25,0);
        glVertex2f(-0.25,8);

        glEnd();

        glColor3f(0,0,1);
        glBegin(GL_POLYGON);


        glVertex2f(3,4);
        glVertex2f(0,8);    //OUTER STRIP
        glVertex2f(0,8.25);
        glVertex2f(3,4.3);

        glEnd();

        glColor3f(0,0,1);
        glBegin(GL_POLYGON);


        glVertex2f(3,1);
        glVertex2f(0,1);    //OUTER STRIP
        glVertex2f(0,0.75);
        glVertex2f(3.2,0.75);

        glEnd();
         glColor3f(0,0,1);
        glBegin(GL_POLYGON);


        glVertex2f(3,0.95);
        glVertex2f(2.13,3);    //OUTER STRIP
        glVertex2f(2.27,3.15);
        glVertex2f(3.15,0.9);

        glEnd();

glColor3f(0,0,1);
        glBegin(GL_POLYGON);


        glVertex2f(3,4);
        glVertex2f(2,3);    //OUTER STRIP
        glVertex2f(2.25,3);
        glVertex2f(3.25,4);

        glEnd();

glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(1,2);
        glVertex2f(1.5,2);    ///SUN
        glVertex2f(1.5,3);
        glVertex2f(1,3);

        glEnd();

glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(1.1,1.85);
        glVertex2f(1.45,1.85);    ///SUN
        glVertex2f(1.45,3.15);
        glVertex2f(1.1,3.15);

        glEnd();

        glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(0.93,2.15);
        glVertex2f(1.59,2.15);    ///SUN
        glVertex2f(1.59,2.75);
        glVertex2f(0.93,2.75);

  glEnd();

        glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(0.5,5.15);
        glVertex2f(0.95,4.7);    ///MOON
        glVertex2f(1.57,4.7);
        glVertex2f(1.9,5.15);
        glVertex2f(1.57,5.15);
        glEnd();
glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(1.15,5);
        glVertex2f(1.37,5);
        glVertex2f(1.37,5.43);
        glVertex2f(1.15,5.43);

        glEnd();
         glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(0.93,5);
        glVertex2f(1.5,5);
        glVertex2f(1.5,5.35);
        glVertex2f(0.93,5.35);

  glEnd();

glColor3f(1,1,1);
        glBegin(GL_POLYGON);


        glVertex2f(1,5);
        glVertex2f(1.35,5);
        glVertex2f(1.35,5.5);
        glVertex2f(1,5.5);

        glEnd();



        glFlush();

}


void Initialize( )
{
        glClearColor(0,0,0,0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}
int main(int Argc, char** Argv)
{
        glutInit(&Argc, Argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1000, 500);
        glutInitWindowPosition(25, 25);
        glutCreateWindow("Flag of Nepal");
        Initialize();
        glutDisplayFunc(Draw);
        glutMainLoop();
        return 0;
}
