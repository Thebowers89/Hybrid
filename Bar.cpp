#include "Bar.h"
#include "Global.h"
#include <iostream>
using namespace std;

int Bar::init() {
    Global global;
    cout << "Bar v1.0" << endl << "> ";
    getline(cin,cmd);
    cmd = global.ignorecase(cmd);
    if(cmd=="list" || cmd=="search"){
        global.search(cmd,"DrinkList.txt",3,0);
        init();
    }else if(cmd=="help") {
        cout << "list: lists known recipes" << endl 
        << "search: search for a specific drink" << endl 
        << "exit/e: exits program/current branch" << endl;
        init();
    }else if(cmd=="exit"||cmd=="e"){
    }else{
        cout << "Invalid Command\n";
        init();
    }
}
