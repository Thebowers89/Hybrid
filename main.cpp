#include "Chemistry.h"
#include "Telescience.h"
#include "Food.h"
#include "Bar.h"
#include <iostream>
using namespace std;

string cmd;
//We're on MinGW Now :D
void init(){
    cout << "SS13 Program Hub v1.0" << endl << "> ";
    getline(cin,cmd);
    if(cmd=="chem"){
        Chemistry chem;
        chem.init();
        init();
    }else if(cmd=="sci"){
        Telescience sci;
        sci.init();
        init();
    }else if(cmd=="food"){
        Food food;
        food.init();
        init();
    }else if(cmd=="bar"){
        Bar bar;
        bar.init();
        init();
    }else if(cmd=="help"){
        cout << "chem: opens chemistry wiki" << endl
        << "sci: opens telescience console" << endl
        << "food: opens food wiki" << endl
        << "bar: opens drinks wiki" << endl;
        init();
    }else if(cmd=="exit"||cmd=="e"){
    }else{
        cout << "Invalid Command\n";
        init();
    }
}

int main() {
    init();
}