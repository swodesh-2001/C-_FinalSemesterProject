
int temp{0};



class menu{
private:
int x,y,scale = 1;
string name;
bool flag = false;
float color = 0;
int id;


public :
//static int c ;
menu(string s = "none",int a = 0 , int b = 0):name(s),x(a),y(b){ id = temp; counter();}

int get_id(){
return id;
}

void create(){
  int a = 100*id+x;
  int b = y;
  create_square(a,b,100,50,0,1,color);
  a = 100*id+x + 20;
  b = y + 10;
  if(name == "resistor")  { create_square(a , b , scale*50 , scale*15 ,1,1,1); }
  if(name == "voltage_source")   {create_square(a,b,scale*40,scale*5,1,1,1); create_square(a+scale*15,b+scale*16,scale*10,scale*5,1,1,1);}
  if(name == "node")   {create_square(a , b , scale*15 , scale*15 ,1,1,1);}
}

static void counter(){
temp++;
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

void draw(int a , int b){
if (flag){
  if(name == "resistor")  { create_square(a , b , scale*50 , scale*15 ,1,1,1);}
  if(name == "voltage_source")   {create_square(a,b,scale*40,scale*5,1,1,1); create_square(a+scale*15,b+scale*16,scale*10,scale*5,1,1,1);}
  if(name == "node")   {create_square(a , b , scale*15 , scale*15 ,1,1,1);}


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








class resistor{
public:
int x,y,scale = 1;
bool flag = false;
string color,temp;
float value;



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


void if_hovering(int a , int b){
    if(a <= (x + scale*50) && a >= x && b <= (y + scale*15) && b >= y){
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



resistor(int a=0 , int b=0 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(){
         if( color == "red" || color == "RED" ){create_square(x , y , scale*50 , scale*15 ,1,0,0);}

         if ( color == "green"  || color == "GREEN" ){create_square(x , y , scale*50 , scale*15 ,0,1,0);}

         if ( color == "blue" || color == "BLUE" ){ create_square(x , y , scale*50 , scale*15 ,0,0,1);}

         if ( color == "yellow" || color == "YELLOW"  ){create_square(x , y , scale*50 , scale*15 ,1,1,0);}

         if ( color == "black" || color == "BLACK" ){create_square(x , y , scale*50 , scale*15 ,0,0,0);}

         if (color == "white" || color == "WHITE") {
        create_square(x , y , scale*50 , scale*15 ,1,1,1);
         }


}



};


class voltage_source{
public:
int x,y,scale = 1;
bool flag = false;
string color,temp;
float value;



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


void if_hovering(int a , int b){


    if(a <= (x + scale*50) && a >= x && b <= (y + scale*15) && b >= y){
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



voltage_source(int a=0 , int b=0 ,float val=100, string c = "white"):x(a),y(b),value(100),color(c),temp(c){
}

void create(){
         if( color == "red" || color == "RED" ){create_square(x,y,scale*40,scale*5,1,0,0); create_square(x+scale*15,y+scale*16,scale*10,scale*5,1,0,0);}

         if ( color == "green"  || color == "GREEN" ){create_square(x,y,scale*40,scale*5,0,1,0); create_square(x+scale*15,y+scale*16,scale*10,scale*5,0,1,0);}

         if ( color == "blue" || color == "BLUE" ){create_square(x,y,scale*40,scale*5,0,0,1); create_square(x+scale*15,y+scale*16,scale*10,scale*5,0,0,1);}


         if ( color == "yellow" || color == "YELLOW"  ){create_square(x,y,scale*40,scale*5,1,1,0); create_square(x+scale*15,y+scale*16,scale*10,scale*5,1,1,0);}


         if ( color == "black" || color == "BLACK" ){create_square(x,y,scale*40,scale*5,0,0,0); create_square(x+scale*15,y+scale*16,scale*10,scale*5,0,0,0);}


         if (color == "white" || color == "WHITE") {
       {create_square(x,y,scale*40,scale*5,1,1,1); create_square(x+scale*15,y+scale*16,scale*10,scale*5,1,1,1);}

         }


}
};


class node{
public:
vector<int> x_points;
vector<int> y_points;
int scale = 1;
bool flag = true;
string color = "white",temp;
float value;



void show_color(){
cout << color << endl;
}

void change_flag(bool b){
    flag = b;
}

bool get_flag(){
return flag;
}


void if_hovering(int a , int b){
    for(int i=0 ; i < x_points.size() ; i++){
            int x,y;
        x = x_points[i];
        y = y_points[i];
        if(a <= (x + scale*5) && a >= x && b <= (y + scale*5) && b >= y){
        color = "yellow";
    }
    else
        color = temp;
    }
}

void del(){
x_points.clear();
y_points.clear();
}

bool hovering_status(int a , int b){
 for(int i=0 ; i < x_points.size() ; i++){
        int x,y;
        x = x_points[i];
        y = y_points[i];
    if(a <= (x + scale*5) && a >= x && b <= (y + scale*5) && b >= y){
        return true;
    }
    else{return false;}
}
}

void create(){
     for(int i=0 ; i < x_points.size() ; i++){
            int x,y;
        x = x_points[i];
        y = y_points[i];
         if( color == "red" || color == "RED" ){create_square(x,y,scale*5,scale*5,1,0,0); }

         if ( color == "green"  || color == "GREEN" ){create_square(x,y,scale*5,scale*5,0,1,0);}

         if ( color == "blue" || color == "BLUE" ){create_square(x,y,scale*5,scale*5,0,0,1);}


         if ( color == "yellow" || color == "YELLOW"  ){create_square(x,y,scale*5,scale*5,1,1,0); }


         if ( color == "black" || color == "BLACK" ){create_square(x,y,scale*5,scale*5,0,0,0); }


         if (color == "white" || color == "WHITE") { create_square(x,y,scale*5,scale*5,1,1,1);}
     }

}
};











