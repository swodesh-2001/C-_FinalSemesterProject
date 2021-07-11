#include "func.hpp"
#include "components.hpp"

int width =1000 , height = 700;



const int menu_size = 5;
const int rectangle_size = 500;
const int square_size = 500;


int rectangle_temp =  0;
int square_temp =  0;



menu menu_points[menu_size] = {menu("square"),menu("square") ,menu("square") ,menu("square") ,menu("rectangle")};
rectangle rectangle_points[rectangle_size]{};

square square_points[square_size]{};



void mouse_func(int button , int state ,  int x , int y){

    int temp1;
    for(int i = 0 ; i < menu_size ; i++){
        if(menu_points[i].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               temp1 = menu_points[i].get_id();
                menu_points[i].change_flag(true);
                for(int i = 0 ; i < menu_size ; i++){
                    if(menu_points[i].get_id() != temp1){menu_points[i].change_flag(false);
                }
        }
        }
        }



    for(int i = 0 ; i < rectangle_size ; i++){
        if(rectangle_points[i].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               rectangle_points[i].change_flag(true);
        }
        }
        }

    for(int i = 0 ; i < square_size ; i++){
        if(square_points[i].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               square_points[i].change_flag(true);
        }
        }
        }


   if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ){
        for(int i = 0 ; i < menu_size ; i++){
                if(menu_points[i].get_flag()){

                    if(menu_points[i].get_name() == "rectangle"){
                    rectangle_points[rectangle_temp] = rectangle(x,y);
                    rectangle_points[rectangle_temp].change_create_flag();
                    rectangle_temp++;}

                    if(menu_points[i].get_name() == "square"){
                        square_points[square_temp] = square(x,y);
                        square_points[square_temp].change_create_flag();
                        square_temp++;
                        }

                   menu_points[i].change_flag(false);
                }
        }


        for(int i = 0 ; i < rectangle_size ; i++){rectangle_points[i].change_flag(false);}
        for(int i = 0 ; i < square_size ; i++){square_points[i].change_flag(false);}
        }





}}


void motion_mouse_func( int x , int y){


        for(int i = 0 ; i < rectangle_size ; i++){if(rectangle_points[i].get_flag()){rectangle_points[i].change_pos(a,b);}}
        for(int i = 0 ; i < square_size ; i++){if(square_points[i].get_flag()){square_points[i].change_pos(a,b);}}


    glutMouseFunc(mouse_func);
    a = x;
    b = y;
}





int main(int argc , char**argv){
glutInit(&argc , argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
glutInitWindowPosition(50,50);
glutInitWindowSize(width,height);
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
glTranslatef(-width/2,height/2,0);
glRotatef(180,1,0,0);

for (int i = 0 ; i < menu_size ; i++){menu_points[i].create(); menu_points[i].if_hovering(a,b); menu_points[i].draw(a,b);}
for (int i = 0 ; i < rectangle_size ; i++){rectangle_points[i].create();rectangle_points[i].if_hovering(a,b);}
for (int i = 0 ; i < square_size ; i++){square_points[i].create();square_points[i].if_hovering(a,b);}


glutPassiveMotionFunc(motion_mouse_func);
glutSwapBuffers();



}
