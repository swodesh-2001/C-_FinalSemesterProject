#include "func.hpp"
#include "components.hpp"

vector<menu> menu_points{menu("rectangle"),menu("square"),menu("pen")};
vector<rectangle> rectangle_points;
vector<square> square_points;
vector<pen> pen_points;


void mouse_func(int button , int state ,  int x , int y){

         for(auto &i : rectangle_points){
        if(i.hovering_status(a,b)){
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               i.change_flag(true);
        }
        }
        }


    for(auto &i : square_points){
        if(i.hovering_status(a,b)){
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               i.change_flag(true);
        }
        }
        }

    int temp;
    for (auto &i : menu_points){
        if(i.hovering_status(a,b)){
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
                 temp = i.get_id();
                 i.change_flag(true);
                 for (auto &i : menu_points){if(i.get_id() != temp){i.change_flag(false);}}
            }

        }
        }


    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ){
        for(auto &i : pen_points){i.change_flag(false);}
        for(auto &i : menu_points){
                if(i.get_flag()){
                    if(i.get_name() == "rectangle"){rectangle_points.push_back(rectangle(x,y));}
                    if(i.get_name() == "square"){square_points.push_back(square(x,y));}
                    if(i.get_name() == "pen"){pen_points.push_back(pen());}
                    i.change_flag(false);
                }
        }

        for(auto &i : rectangle_points){i.change_flag(false);}
        for(auto &i : square_points){i.change_flag(false);}
        }


}


void motion_mouse_func( int x , int y){

    for(auto &i : rectangle_points){if(i.get_flag()){i.change_pos(a,b);}}
    for(auto &i : square_points){if(i.get_flag()){i.change_pos(a,b);}}
    for(auto &i : pen_points){ if(i.get_flag()){i.x_points.push_back(a);i.y_points.push_back(b);}}

    glutMouseFunc(mouse_func);
    a = x;
    b = y;
}





int main(int argc , char**argv){

glutInit(&argc , argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
glutInitWindowPosition(500,250);
glutInitWindowSize(500,500);
glutCreateWindow("First window");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
init();
glutMainLoop();
}




void display()
{


glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glTranslatef(-250,250,0);
glRotatef(180,1,0,0);


for(auto &i : menu_points){i.create();i.if_hovering(a,b);i.draw(a,b);}
for(auto &i : rectangle_points){i.create();i.if_hovering(a,b);}
for(auto &i : square_points){i.create();i.if_hovering(a,b);}
for(auto &i : pen_points){i.create();}


glutPassiveMotionFunc(motion_mouse_func);
glutSwapBuffers();



}

