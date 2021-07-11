

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
  if(name == "square")   {create_square(a,b- 5,scale*40,scale*40,red,green,blue);}
  if(name == "pen")   {create_square(a , b  , scale*15 , scale*15 ,red,green,blue);}
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
    }
    else
        color = 0;

}

void draw(int a , int b,float red=1,float green=1,float blue=1){
if (flag){
  if(name == "rectangle")  { create_square(a , b , scale*50 , scale*15 ,red,green,blue);}
  if(name == "square")   {create_square(a,b,scale*40,scale*40,red,green,blue); }
  if(name == "pen")   {create_square(a , b , scale*15 , scale*15 ,red,green,blue);}


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
int x,y,scale = 1;
bool flag = false;
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

}
temp = color;
}

void if_hovering(int a , int b){
    if(a <= (x + scale*50) && a >= x && b <= (y + scale*15) && b >= y && !get_flag() ){
        color = "yellow";
    }
    else
        color = temp;

}

bool hovering_status(int a , int b){

    if(a <= (x + scale*50) && a >= x && b <= (y + scale*15) && b >= y){
        return true;
    }
    else{return false;}
}



rectangle(int a=0 , int b=0 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(float red=1,float green=1,float blue=1){

    if (create_flag){
         if( color == "red" || color == "RED" ){create_square(x , y , scale*50 , scale*15 ,1,0,0);}
         if ( color == "green"  || color == "GREEN" ){create_square(x , y , scale*50 , scale*15 ,0,1,0);}
         if ( color == "blue" || color == "BLUE" ){ create_square(x , y , scale*50 , scale*15 ,0,0,1);}
         if ( color == "yellow" || color == "YELLOW"  ){create_square(x , y , scale*50 , scale*15 ,1,1,0);}
         if ( color == "black" || color == "BLACK" ){create_square(x , y , scale*50 , scale*15 ,red,green,blue);}
         if (color == "white" || color == "WHITE") {create_square(x , y , scale*50 , scale*15 ,red,green,blue);}
          }
}
};


class square{
public:
int x,y,scale = 1;
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
}
temp = color;
}

void if_hovering(int a , int b){
    if(a <= (x + scale*40) && a >= x && b <= (y + scale*40) && b >= y  && !get_flag() ){
        color = "yellow";
    }
    else
        color = temp;

}

bool hovering_status(int a , int b){

    if(a <= (x + scale*40) && a >= x && b <= (y + scale*40) && b >= y){
        return true;
    }
    else{return false;}
}



square(int a=0 , int b=0 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(float red, float green,float blue){

     if (create_flag){
         if( color == "red" || color == "RED" ){create_square(x,y,scale*40,scale*40,1,0,0);  }
         if ( color == "green"  || color == "GREEN" ){create_square(x,y,scale*40,scale*40,0,1,0);  }
         if ( color == "blue" || color == "BLUE" ){create_square(x,y,scale*40,scale*40,0,0,1);  }
         if ( color == "yellow" || color == "YELLOW"  ){create_square(x,y,scale*40,scale*40,1,1,0); }
         if ( color == "black" || color == "BLACK" ){create_square(x,y,scale*40,scale*40,red,green,blue); }
         if (color == "white" || color == "WHITE") {create_square(x,y,scale*40,scale*40,red,green,blue); }
     }

}
};
