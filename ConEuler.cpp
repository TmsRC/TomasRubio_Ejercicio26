#include <fstream>
#include <iostream>
using namespace std;


void eulerS(float step,string name);



int main(){
    
    float deltax = 0.1;
    
    eulerS(deltax,"conEuler.dat");
  
    return 0;
}

void eulerS(float delta, string filename){
    
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
    
    
    while (t < t_f) {
        outfile << t << " " <<  y << endl;
        
        float y_old = y;
        float z_old = z;
        
        x += delta;
        y = y + delta*z_old;
        z = z + delta*(-1*pow(w,2)*y_old);
        
    }
    
    outfile.close();
}