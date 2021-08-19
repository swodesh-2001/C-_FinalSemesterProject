#include "func.hpp"
#include "components.hpp"

int width =1000 , height = 700;
float rr[6]={0.0,0.0,0.0,0.0,0.0},gr[6]={0.9,0.9,0.9,0.9,0.9},br[6]={0.0,0.0,0.0,0.0,0.0};

const int menu_size = 6;
const int rectangle_size = 500;
const int square_size = 500;
const int triangle_size = 500;
const int circle_size = 500;
const int pen_size = 500;
const int nepal_size = 5;




float red=1;
float green=1;
float blue=1;

int rectangle_temp =  0;
int square_temp =  0;
int triangle_temp =  0;
int circle_temp =  0;
int pen_temp =  0;

bool x{false};

int x_po=0;
int y_po=0;

menu menu_points[menu_size] = {menu("square"),menu("rectangle"),menu("triangle"),menu("circle"),menu("pen"),menu("nepal")};
rectangle rectangle_points[rectangle_size]{};
square square_points[square_size]{};
triangle triangle_points[triangle_size]{};
circle circle_points[circle_size]{};
pen pen_points[pen_size][500]{};
int nepal_points[nepal_size][2] = {{2000,2000},{2000,2000},{2000,2000},{2000,2000},{2000,2000}} ;


void nepal_reset(){
for(int i=0 ; i < nepal_size ; i++){nepal_points[i][0]=2000;nepal_points[i][1]=2000; nepal_counter = 0;}
}


void mouse_func(int button , int state ,  int x , int y){

    int temp1;
    for(int i = 0 ; i < menu_size ; i++){
        if(menu_points[i].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               temp1 = menu_points[i].get_id();
                menu_points[i].change_flag(true);
                clicked=false;
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

    for(int i = 0 ; i < triangle_size ; i++){
        if(triangle_points[i].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               triangle_points[i].change_flag(true);
        }
        }
        }

    for(int i = 0 ; i < circle_size ; i++){
        if(circle_points[i].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               circle_points[i].change_flag(true);
        }
        }
        }

    for(int i = 0 ; i < pen_size ; i++){
        if(pen_points[i][0].hovering_status(a,b)){
              if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
               pen_points[i][0].change_flag(true);
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

                    if(menu_points[i].get_name() == "triangle"){
                        triangle_points[triangle_temp] = triangle(x,y);
                        triangle_points[triangle_temp].change_create_flag();
                        triangle_temp++;
                        }

                    if(menu_points[i].get_name() == "circle"){
                        circle_points[circle_temp] = circle(x,y);
                        circle_points[circle_temp].change_create_flag();
                        circle_temp++;
                        }

                    if(menu_points[i].get_name() == "pen"){

                        pen_points[pen_temp][0] = pen(x,y);
                        pen_points[pen_temp][0].change_create_flag();
                        pen_points[pen_temp][0].draw_line=true;
                        x_po=0;
                        y_po=0;
                        clicked=true;
                        pen_temp++;
                        taken_pen=pen_temp-1;

                    }

                    if(menu_points[i].get_name() == "nepal"){
                        nepal_points[nepal_counter][0] = x;
                        nepal_points[nepal_counter][1] = y;
                        nepal_counter++;
                        if(nepal_counter == 6){nepal_reset();}
                        }

                         menu_points[i].change_flag(false);


                }
        }


        for(int i = 0 ; i < rectangle_size ; i++){rectangle_points[i].change_flag(false);}
        for(int i = 0 ; i < triangle_size ; i++){triangle_points[i].change_flag(false);}
        for(int i = 0 ; i < square_size ; i++){square_points[i].change_flag(false);}
        for(int i = 0 ; i < circle_size ; i++){circle_points[i].change_flag(false);}
        for(int i = 0 ; i < pen_size ; i++){pen_points[i][0].change_flag(false);}
        }


    for (int i=0;i<5;i++)
    {
        if (x>=750+50*i && x<=800+50*i && y>=0 && y<=50 && button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {

        if (i==0){glClearColor(0.8,0,0,1);}
        if (i==1){glClearColor(0.9,0.9,0,1);}
        if (i==2){glClearColor(0.98,0.05,0.90,1);}
        if (i==3){glClearColor(0,0,0,1);red=1;green=1;blue=1;}
        if (i==4){glClearColor(1,1,1,1);red=0,green=0,blue=0;}
        }
    }


}
}

void motion_mouse_func( int x , int y){
        for(int i = 0 ; i < rectangle_size ; i++){if(rectangle_points[i].get_flag()){rectangle_points[i].change_pos(a,b);}}
        for(int i = 0 ; i < triangle_size ; i++){if(triangle_points[i].get_flag()){triangle_points[i].change_pos(a,b);}}
        for(int i = 0 ; i < square_size ; i++){if(square_points[i].get_flag()){square_points[i].change_pos(a,b);}}
        for(int i = 0 ; i < circle_size ; i++){if(circle_points[i].get_flag()){circle_points[i].change_pos(a,b);}}
        for(int i = 0 ; i < pen_size ; i++){if(pen_points[i][0].get_flag()){pen_points[i][0].change_pos(a,b);}}
        for(int i = 0 ; i < pen_size ; i++){for (int j=0;j<200;j++){if(pen_points[i][j].get_flagie()){pen_points[i][j].changing_pos(a,b);}}}


        for (int i=0;i<5;i++)
        {
        if (x>=750+i*50 && x<=800+50*i && y>=0 && y<=50){rr[i]=0.0,gr[i]=1.0,br[i]=1.0;}
        else {rr[i]=0.0,gr[i]=1.0,br[i]=0.0;}
        }



    glutMouseFunc(mouse_func);
    a = x;
    b = y;

    if (pen_points[pen_temp-1][0].draw_line){
        if (clicked){
        pen_points[pen_temp-1][0].change_flag(true);
        x_co[pen_temp-1][x_po]=x;
        y_co[pen_temp-1][y_po]=y;
        draw[pen_temp-1][x_po]=true;
        x_po++;
        y_po++;}
    }

}

void keyboard(unsigned char c , int x , int y){
for(int i = 0 ; i < rectangle_size ; i++){if(rectangle_points[i].get_flag()){rectangle_points[i].change_variables(c);}}
for(int i = 0 ; i < square_size ; i++){if(square_points[i].get_flag()){square_points[i].change_variables(c);}}
for(int i = 0 ; i < triangle_size ; i++){if(triangle_points[i].get_flag()){triangle_points[i].change_variables(c);}}
for(int i = 0 ; i < circle_size ; i++){if(circle_points[i].get_flag()){circle_points[i].change_variables(c);}}
for(int i = 0 ; i < pen_size ; i++){if(pen_points[i][0].get_flag()){pen_points[i][0].change_variables(c);}}
switch (c)
{
//case 'T': clicked=false;break;
case 'T':if (clicked){clicked=false;pen_points[pen_temp-1][0].change_pos(2000,2000);pen_points[pen_temp-1][0].change_flag(false);}else{clicked=true;pen_points[pen_temp-1][0].change_flag(true);}break;
case 'S':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){size_of_pen[i][j]++;}}break;
case 'B':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){pen_red[i][j]=0;pen_green[i][j]=0;pen_blue[i][j]=0;}}break;
case 'R':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){pen_red[i][j]=1;pen_green[i][j]=0;pen_blue[i][j]=0;}}break;
case 'W':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){pen_red[i][j]=1;pen_green[i][j]=1;pen_blue[i][j]=1;}}break;
case 'A':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){size_of_pen[i][j]--;}}break;
case 'G':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){pen_red[i][j]=0;pen_green[i][j]=1;pen_blue[i][j]=0;}}break;
case 'P':for (int i=taken_pen;i<100;i++){for (int j=x_po;j<10000;j++){pen_red[i][j]=0.9;pen_green[i][j]=0.2;pen_blue[i][j]=0.9;}}break;

}
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




for (int i=0; i<5;i++)
{
create_rectangle(750+50*i,0,2.5,rr[i],gr[i],br[i]);
}

create_square(755,6,0.8,1.0,0.0,0.0);
create_square(805,6,0.8,1.0,1.0,0.0);
create_square(855,6,0.8,0.99,0.1,1.0);
create_square(905,6,0.8,0.0,0.0,0.0);
create_square(955,6,0.8,1.0,1.0,1.0);



for (int i = 0 ; i < menu_size ; i++){menu_points[i].create(red,green,blue); menu_points[i].if_hovering(a,b); menu_points[i].draw(a,b,red,green,blue);}

for (int i = 0 ; i < rectangle_size ; i++){rectangle_points[i].create(red,green,blue);rectangle_points[i].if_hovering(a,b);}
for (int i = 0 ; i < square_size ; i++){square_points[i].create(red,green,blue);square_points[i].if_hovering(a,b);}
for (int i = 0 ; i < triangle_size ; i++){triangle_points[i].create(red,green,blue);triangle_points[i].if_hovering(a,b);}
for (int i = 0 ; i < circle_size ; i++){circle_points[i].create(red,green,blue);circle_points[i].if_hovering(a,b);}
for (int i = 0 ; i < pen_size ; i++){pen_points[i][0].create(red,green,blue);pen_points[i][0].if_hovering(a,b);}

for (int j=0;j<pen_temp;j++){
for (int i=0;i<10000;i++){
if (draw[j][i])
{
    create_pen(x_co[j][i],y_co[j][i],size_of_pen[j][i],pen_red[j][i],pen_green[j][i],pen_blue[j][i]);
}
}
}

for(int i=0 ; i < nepal_size ; i++){
    create_nepal(nepal_points[i][0],nepal_points[i][1]);
    cout << nepal_points[i][0] << " " << nepal_points[i][1] << endl;
}

glutKeyboardFunc(keyboard);
glutPassiveMotionFunc(motion_mouse_func);
glutSwapBuffers();


}




