#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

string explicitSheme(float w,float dt,float t_i,float t_f,float y_i);
string implicitSheme(float w,float dt,float t_i,float t_f,float y_i);

int main(){
    float w=10.0;
    ofstream archivo;
    ofstream archivo1;
    string mensaje1;
    string mensaje2;
    archivo.open("datos1.txt",std::ios::app);
    archivo1.open("datos2.txt",std::ios::app);
    float dt;
    float t_i=0;
    float t_f;
    float y_i=1.0;
    dt=0.1/w;
    t_f=4/w;
    mensaje1=explicitSheme(w,dt, t_i, t_f, y_i);
    mensaje2=implicitSheme(w,dt, t_i, t_f, y_i);
    archivo<<mensaje1<<endl;
    archivo1<<mensaje2<<endl;
    return 0;
}

string explicitSheme(float w,float dt,float t_i,float t_f,float y_i){
    double y=y_i;
    double t=t_i;
    string m="";
    while(t<t_f){
        m=m+to_string(t)+" "+to_string(y)+"\n";
        y=y-dt*w*y;
        t+=dt;
    }
    return m;
}

string implicitSheme(float w,float dt,float t_i,float t_f,float y_i){
    double y=y_i;
    double t=t_i;
    string m1="";
    while(t<t_f){
        m1=m1+to_string(t)+" "+to_string(y)+"\n";
        y=y/(1+dt*w);
        t+=dt;
    }
    return m1;
}