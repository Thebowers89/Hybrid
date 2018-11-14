#ifndef TELESCIENCE_H
#define TELESCIENCE_H
#include <iostream>
using namespace std;

class Telescience {
public:
    void init();
    int input(auto b);
    void find();
    void allinputs();
    void build();
    void load();
    void sof();
    void tsearch();
private:
    string saveload,exit,yn,sf;
    double xin,yin,xout1,yout1,xout2,yout2,mx,my,cx,cy;
};

#endif