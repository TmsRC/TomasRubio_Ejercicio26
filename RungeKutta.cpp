#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;


void rk4(float delta,string filename);



int main(){
    
    rk4(0.1,"rk4_01.dat");
    rk4(1,"rk4_001.dat");
    rk4(0.01,"rk4_1.dat");
  
    return 0;
}

void rk4(float delta, string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    float w = 1;
    float y_0 = 1;
    float z_0 = 0; // z=dy/dx
    
    float x_i = 0;
    float x_f = 30;
    
    float x = x_i;
    float y = y_0;
    float z = z_0;
    
    
    while (x < x_f) {
    
        outfile << x << " " << y << " " << z << endl;

        x += delta;
    
        float fy = z/6;
        float fz = (-1*pow(w,2)*y)/6;
    
        float yn = y + delta*z/2;
        float zn = z + delta*(-1*pow(w,2)*y)/2;
        fy += zn/3;
        fz += (-1*pow(w,2)*yn)/3;

        yn = y+ delta*zn/2;
        zn = z + delta*(-1*pow(w,2)*yn)/2;
        fy += zn/3;
        fz += (-1*pow(w,2)*yn)/3;

        yn = y+ delta*zn;
        zn = z + delta*(-1*pow(w,2)*yn);
        fy += zn/6;
        fz += (-1*pow(w,2)*yn)/6;
        
        y += delta*fy;
        z += delta*fz;
     
    }
    
    outfile.close();
}