#ifndef TELESCIENCE_H
#define TELESCIENCE_H
#include <iostream>
using namespace std;

class Telescience {
public:
    void init();
    void load();
    void save();
    int input(auto b, int a);
    void allinputs();
    void build();
    void inpbuild();
    void sof();
    void find();
    void tsearch();
private:
    string saveload,exit,yn,sf;
    double xin,yin,xout1,yout1,xout2,yout2,mx,my,cx,cy;
};

#endif