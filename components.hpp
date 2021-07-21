class menu{
private:
int x,y,scale = 1;
string name;
bool flag = false;
float color = 0;
int id;

public :
static int c ;
menu(string s = "none",int a = 0 , int b = 0):name(s),x(a),y(b){ id = c; counter();}

int get_id(){
return id;
}

void create(float red=1,float green=1, float blue=1){
  int a = 100*id+x;
  int b = y;
  create_square(a,b,100,50,0,1,color);
  a = 100*id+x + 40;
  b = y + 10;
  if(name == "rectangle")  { create_square(a , b , scale*50 , scale*15 ,red,green,blue); }
  if(name == "triangle")  { create_triangle(a , b-5 , scale*20 , scale*40 ,red,green,blue); }
  if(name == "square")   {create_square(a,b- 5,scale*40,scale*40,red,green,blue);}
  if(name == "circle")   {create_circle(a+10 , b+15  , scale*20 ,red,green,blue,2);}

}

static void counter(){
c++;
}

string get_name(){
return name;
}

void if_hovering(int a , int b){
    if(a <= (100*id+x + 100) && a >= 100*id+x && b <= (y + scale*50) && b >= y){
        color = 1;
        create_circle(a,b,5,0,0,1,2);

    }
    else
        color = 0;

}

void draw(int a , int b,float red=1,float green=1,float blue=1){
if (flag){
  if(name == "rectangle")  { create_square(a , b , scale*50 , scale*15 ,red,green,blue);}
  if(name == "square")   {create_square(a,b,scale*40,scale*40,red,green,blue); }
  if(name == "triangle")  { create_triangle(a , b , scale*20 , scale*40 ,red,green,blue); }
  if(name == "circle")   {create_circle(a , b , scale*50 ,red,green,blue,2);}


}
}

bool hovering_status(int a , int b){

    if(a <= (100*id+x + 100) && a >= 100*id+x && b <= (y + scale*50) && b >= y){
        return true;
    }
    else{return false;}
}


void change_flag(bool b){
flag = b;
}

bool get_flag(){
return flag;
}

};

int menu::c = 0;


class rectangle{
public:
int x,y,scale = 1,x_pos,y_pos,aa=50,bb=15,width_of_line=1;

bool flag = false;
bool filling=true;
bool create_flag = false;
string color,temp;
float value;

void change_create_flag(bool b=true){
    create_flag = b;
}

void show_color(){
cout << color << endl;
}

void change_flag(bool b){
    flag = b;
}

bool get_flag(){
return flag;
}

void change_pos(int a , int b){
    if (flag)
{
x = a;
y = b;}

}


void change_variables(char c ){

switch (c) {
     case 's' :  scale ++; break;
     case 'a' :  scale --; break;
     case 'r' :  color = "red"; break;
     case 'b' : color = "blue" ; break;
     case 'y' : color = "yellow" ; break;
     case 'w' : color = "white" ; break;
     case 'g' : color = "green" ; break;
     case 'B' : color = "Black" ; break;
     case 'W' : color = "White" ; break;
     case 'p' : width_of_line++; ; break;
     case 'o' : width_of_line--; ; break;

     case '1' :  aa+=5; break;
     case '2' :  aa-=5; break;
     case '3' :  bb+=5; break;
     case '4' :  bb-=5; break;

     case 'f' : filling=true ; break;
     case 'u' : filling=false ; break;

     case 'd': x=1000 ; y=2000; create_flag=false; break;

}
temp = color;
}

void if_hovering(int a , int b){
    if(a <= (x + 10) && a >= x-5 && b <= (y + 10) && b >= y -5 && !get_flag() ){
        //color = "yellow";
        create_circle(a,b,5,0,0,1,2);
    }
    else
        color = temp;

}

bool hovering_status(int a , int b){

    if(a <= (x + 10) && a >= x -5  && b <= (y + 10) && b >= y-5){
        return true;
    }
    else{return false;}
}



rectangle(int a=1000 , int b=1000 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(float red=1,float green=1,float blue=1){

    if (create_flag){
        if (not filling){glLineWidth(width_of_line);
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);}
        else
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
         if( color == "red" || color == "RED" ){create_square(x , y , scale*aa , scale*bb ,1,0,0);}
         if ( color == "green"  || color == "GREEN" ){create_square(x , y , scale*aa , scale*bb ,0,1,0);}
         if ( color == "blue" || color == "BLUE" ){ create_square(x , y , scale*aa , scale*bb ,0,0,1);}
         if ( color == "yellow" || color == "YELLOW"  ){create_square(x , y , scale*aa , scale*bb ,1,1,0);}
         if ( color == "black" || color == "BLACK" ){create_square(x , y , scale*aa , scale*bb ,red,green,blue);}
         if (color == "white" || color == "WHITE") {create_square(x , y , scale*aa , scale*bb ,red,green,blue);}
         if ( color == "White"){create_square(x , y , scale*aa , scale*bb ,1,1,1);}
         if ( color == "Black"){create_square(x , y , scale*aa , scale*bb ,0,0,0);}

          }
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}
};


class square{
public:
int x,y,scale = 1,width_of_line=1;
bool filling=true;
bool flag = false;
string color,temp;
float value;
bool create_flag = false;

void change_create_flag(bool b=true){
    create_flag = b;
}

void show_color(){
cout << color << endl;
}

void change_flag(bool b){
    flag = b;
}

bool get_flag(){
return flag;
}

void change_pos(int a , int b){
    if (flag)
{ x = a; y = b;}
}

void change_variables(char c ){

switch (c) {
     case 's' :  scale ++; break;
     case 'a' :  scale --; break;
     case 'r' :  color = "red"; break;
     case 'b' : color = "blue" ; break;
     case 'y' : color = "yellow" ; break;
     case 'w' : color = "white" ; break;
     case 'g' : color = "green" ; break;
     case 'W' : color = "White" ; break;
     case 'B' : color = "Black" ; break;
     case 'f' : filling=true ; break;
     case 'u' : filling=false ; break;
     case 'p' : width_of_line++ ; break;
     case 'o' : width_of_line-- ; break;

     case 'd': x=1000 ; y=2000; create_flag=false; break;

}
temp = color;
}

void if_hovering(int a , int b){
    if(a <= (x + 10) && a >= x-5 && b <= (y + 10) && b >= y -5  && !get_flag() ){
        //color = "yellow";
        create_circle(a,b,5,0,0,1,2);
    }
    else
        color = temp;

}

bool hovering_status(int a , int b){

    if(a <= (x + 10) && a >= x - 5 && b <= (y + 10) && b >= y - 5){
        return true;
    }
    else{return false;}
}



square(int a=1000 , int b=1000 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(float red, float green,float blue){

         if (create_flag){
            if (not filling){
               glLineWidth(width_of_line);
               glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);}
            else
                glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
         if( color == "red" || color == "RED" ){create_square(x,y,scale*40,scale*40,1,0,0);  }
         if ( color == "green"  || color == "GREEN" ){create_square(x,y,scale*40,scale*40,0,1,0);  }
         if ( color == "blue" || color == "BLUE" ){create_square(x,y,scale*40,scale*40,0,0,1);  }
         if ( color == "yellow" || color == "YELLOW"  ){create_square(x,y,scale*40,scale*40,1,1,0); }
         if ( color == "black" || color == "BLACK" ){create_square(x,y,scale*40,scale*40,red,green,blue); }
         if (color == "white" || color == "WHITE") {create_square(x,y,scale*40,scale*40,red,green,blue); }
         if (color == "White") {create_square(x,y,scale*40,scale*40,1,1,1); }
         if (color == "Black") {create_square(x,y,scale*40,scale*40,0,0,0); }
     }


    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

}
};

class triangle{
public:
int x,y,scale = 1,aa=20,bb=40,width_of_line=1;
bool filling=true;
bool flag = false;
string color,temp;
float value;
bool create_flag = false;

void change_create_flag(bool b=true){
    create_flag = b;
}

void show_color(){
cout << color << endl;
}

void change_flag(bool b){
    flag = b;
}

bool get_flag(){
return flag;
}

void change_pos(int a , int b){
    if (flag)
{ x = a; y = b;}
}

void change_variables(char c ){

switch (c) {
     case 's' :  scale ++; break;
     case 'a' :  scale --; break;
     case 'r' :  color = "red"; break;
     case 'b' : color = "blue" ; break;
     case 'y' : color = "yellow" ; break;
     case 'w' : color = "white" ; break;
     case 'g' : color = "green" ; break;
     case 'W' : color = "White" ; break;
     case 'B' : color = "Black" ; break;
     case 'f' : filling=true ; break;
     case 'u' : filling=false ; break;
     case 'p' : width_of_line++ ; break;
     case 'o' : width_of_line-- ; break;


     case '1' :  aa+=5; break;
     case '2' :  aa-=5; break;
     case '3' :  bb+=5; break;
     case '4' :  bb-=5; break;

     case 'd': x=1000 ; y=2000; create_flag=false; break;

}
temp = color;
}

void if_hovering(int a , int b){
    if(a <= (x + 10) && a >= x - 5 && b <= (y + 10) && b >= y - 5  && !get_flag() ){
        //color = "yellow";
        create_circle(a,b,5,0,0,1,2);
    }
    else
        color = temp;

}

bool hovering_status(int a , int b){

    if(a <= (x + 10) && a >= (x - 5) && b <= (y + 10) && b >= y-5){
        return true;
    }
    else{return false;}
}



triangle(int a=1000 , int b=1000 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(float red, float green,float blue){

         if (create_flag){
            if (not filling){glLineWidth(width_of_line);
               glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);}
            else
                glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
         if( color == "red" || color == "RED" ){create_triangle(x,y,scale*aa,scale*bb,1,0,0);  }
         if ( color == "green"  || color == "GREEN" ){create_triangle(x,y,scale*aa,scale*bb,0,1,0);  }
         if ( color == "blue" || color == "BLUE" ){create_triangle(x,y,scale*aa,scale*bb,0,0,1);  }
         if ( color == "yellow" || color == "YELLOW"  ){create_triangle(x,y,scale*aa,scale*bb,1,1,0); }
         if ( color == "black" || color == "BLACK" ){create_triangle(x,y,scale*aa,scale*bb,red,green,blue); }
         if (color == "white" || color == "WHITE") {create_triangle(x,y,scale*aa,scale*bb,red,green,blue); }
         if (color == "White") {create_triangle(x,y,scale*aa,scale*bb,1,1,1); }
         if (color == "Black") {create_triangle(x,y,scale*aa,scale*bb,0,0,0); }
     }

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

}
};



class circle{
public:
int x,y,scale = 1,width_of_line=2;
bool filling=false;
bool flag = false;
string color,temp;
float radius;
bool create_flag = false;

void change_create_flag(bool b=true){
    create_flag = b;
}

void show_color(){
cout << color << endl;
}

void change_flag(bool b){
    flag = b;
}

bool get_flag(){
return flag;
}

void change_pos(int a , int b){
    if (flag)
{ x = a; y = b;}
}

void change_variables(char c ){

switch (c) {
     case 's' :  scale ++; break;
     case 'a' :  scale --; break;
     case 'r' :  color = "red"; break;
     case 'b' : color = "blue" ; break;
     case 'y' : color = "yellow" ; break;
     case 'w' : color = "white" ; break;
     case 'g' : color = "green" ; break;
     case 'W' : color = "White" ; break;
     case 'B' : color = "Black" ; break;
     case 'f' : filling=true ; break;
     case 'u' : filling=false ; break;
     case 'p' : width_of_line++ ; break;
     case 'o' : width_of_line-- ; break;
     case 'd': x=1000 ; y=2000; create_flag=false; break;

}
temp = color;
}

void if_hovering(int a , int b){
    if(a <= (x + 20) && a >= x - 20 && b <= ( y + 20 ) && b >=  y - 20  && !get_flag() ){
        //color = "yellow";
        create_circle(a,b,5,0,0,1,2);
    }
    else
        color = temp;

}

bool hovering_status(int a , int b){

    if(a <= (x + 20) && a >= (x - 20) && b <= ( y + 20 ) && b >=   y-20){
        return true;
    }
    else{return false;}
}



circle(int a=1000 , int b=1000 ,float r=100, string c = "white"):x(a),y(b),radius(r),color(c),temp(c){
}


void sub_create(float rad,float red, float green,float blue){
if( color == "red" || color == "RED" ){create_circle(x,y,scale*rad ,1,0,0,width_of_line);  }
         if ( color == "green"  || color == "GREEN" ){create_circle(x,y,scale*rad ,0,1,0,width_of_line);  }
         if ( color == "blue" || color == "BLUE" ){create_circle(x,y,scale*rad ,0,0,1,width_of_line);   }
         if ( color == "yellow" || color == "YELLOW"  ){create_circle(x,y,scale*rad ,1,1,0,width_of_line);  }
         if ( color == "black" || color == "BLACK" ){create_circle(x,y,scale*rad ,red,green,blue,width_of_line);  }
         if (color == "white" || color == "WHITE") {create_circle(x,y,scale*rad ,red,green,blue,width_of_line);  }
         if (color == "White") {create_circle(x,y,scale*rad ,1,1,1,width_of_line); }
         if (color == "Black") {create_circle(x,y,scale*rad ,0,0,0,width_of_line);  }

}


void create(float red, float green,float blue){
           if (create_flag){
                if(filling){
                    for(float i = 1 ; i < radius ; i+=1){
                        sub_create(i,red,green,blue);
                    }
                }
                else {
                    sub_create(radius,red,green,blue);
                    }
                    }

}

};
