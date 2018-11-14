#include "Chemistry.h"
#include "Global.h"
#include <iostream>
using namespace std;
int Chemistry::init() {
    Global global;
    cout << "Chemistry v2.0" << endl << "> ";
    getline(cin,cmd);
    if(cmd=="list" || cmd=="search"){
        global.search(cmd,"ChemList.txt",3,s);
        init();
    }else if(cmd=="stat"){
        if(s==0){
            s=1;
            cout << "Stat mode enabled" << endl;
            init();
        }else{
            s=0;
            cout << "Stat mode disabled" << endl;
            init();
        }
    }else if(cmd=="help") {
        cout << "list: lists known chems" << endl 
        << "search: search for a specific chem" << endl 
        << "stat: toggles stat mode" << endl
        << "exit/e: exits program/current branch" << endl;
        init();
    }else if(cmd=="exit"||cmd=="e"){
    }else{
        cout << "Invalid Command\n";
        init();
    }
}