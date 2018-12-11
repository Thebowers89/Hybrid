#include "Chemistry.h"
#include "Telescience.h"
#include "Food.h"
#include "Bar.h"
#include "Global.h"
#include <iostream>
using namespace std;

string cmd;

void init(){
    Global s;
    cout << "SS13 Program Hub v1.0" << endl << "> ";
    getline(cin,cmd);
    if(s.ignorecase(cmd)=="chem"){
        Chemistry chem;
        chem.init();
        init();
    }else if(s.ignorecase(cmd)=="sci"){
        Telescience sci;
        sci.init();
        init();
        Food food;
        food.init();
        init();
    }else if(s.ignorecase(cmd)=="bar"){
        Bar bar;
        bar.init();
        init();
    }else if(s.ignorecase(cmd)=="help"){
        cout << "\nchem: opens chemistry wiki" << endl
        << "sci: opens telescience console" << endl
        << "food: opens food wiki" << endl
        << "bar: opens drinks wiki\n" << endl;
        init();
    }else if(s.ignorecase(cmd)=="exit"||s.ignorecase(cmd)=="e"){
    }else{
        cout << "Invalid Command\n";
        init();
    }
}

int main() {
    init();
}