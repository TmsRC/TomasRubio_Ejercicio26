#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

float dzdt(float t, float y, float z, float omega);
float dydt(float t, float y, float z, float omega);

int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  return 0;
}

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    float w = 1;
    float y_0 = 1;
    float z_0 = 0; // z=dy/dx
    
    float t = t_init;
    float y = y_0;
    float z = z_0;
    float delta = delta_t;
    
    
    while (t < t_end) {
        outfile << t << " " << y << " " << z << endl;
        
        float y_old = y;
        float z_old = z;
        
        t += delta;
        y = y + delta*z_old;
        z = z + delta*(-1*w*w*y_old);
        
    }
    
    outfile.close();
}

void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    float w = omega;
    float y_0 = 1;
    float z_0 = 0; // z=dy/dx
    
    float t = t_init;
    float y = y_0;
    float z = z_0;
    float delta = delta_t;
    
    
    while (t < t_end) {
    
        outfile << t << " " << y << " " << z << endl;

        t += delta;
    
        float fy = z/6;
        float fz = (-1*w*w*y)/6;
    
        float yn = y + delta*z/2;
        float zn = z + delta*(-1*w*w*y)/2;
        fy += zn/3;
        fz += (-1*w*w*yn)/3;

        yn = y+ delta*zn/2;
        zn = z + delta*(-1*w*w*yn)/2;
        fy += zn/3;
        fz += (-1*w*w*yn)/3;

        yn = y+ delta*zn;
        zn = z + delta*(-1*w*w*yn);
        fy += zn/6;
        fz += (-1*w*w*yn)/6;
        
        y += delta*fy;
        z += delta*fz;
     
    }
    
    outfile.close();
}

void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename) {
    
    ofstream outfile;
    outfile.open(filename);
    
    float w = 1;
    float y_0 = 1;
    float z_0 = 0; // z=dy/dx
    
    float t = t_init;
    float y = y_0;
    float z = z_0;
    float delta = delta_t;
    
    
    while (t < t_end) {
        outfile << t << " " << y << " " << z << endl;
        
        z += + delta*(-1*w*w*y)/2;
        y = y + delta*z;
        z = z + delta*(-1*w*w*y)/2;
        
        t+= delta;
        
    }
    
    outfile.close();
}