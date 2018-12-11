#include "Telescience.h"
#include "Global.h"
#include <iostream>
#include <fstream>
using namespace std;
void Telescience::init(){
    Global global;
    cout << "Telescience 5.0" << endl << "> ";
    getline(cin,saveload);
    saveload = global.ignorecase(saveload);
    if(saveload=="load") {
        load();
    }else if(saveload=="build"){
        build();
    }else if(saveload=="inpbuild"){
        inpbuild();
    }else if(saveload=="help") {
        cout << "build: builds a new offset equation" << endl
        << "inpbuild: builds a new equation from existing offsets" << endl
        << "load: loads the last built equation" << endl
        << "exit/e: exits program or current branch" << endl;
        init();
    }else if(saveload=="exit"||saveload=="e") {
    }else{
        cout << "invalid command\n";
        init();
    }
}
void Telescience::load(){
    ifstream saveFile("CurrentEquation.txt");
    saveFile >> mx >> my >> cx >> cy;
    saveFile.close();
    sof();
}
void Telescience::save(){
    ofstream saveFile("CurrentEquation.txt");
    saveFile << mx << ' ' << my << ' ' << cx << ' ' << cy;
    saveFile.close();
    cout << "Equation Built!" << endl;
}
int Telescience::input(auto b, int a) {
    if(!(cin >> *b)) {
        cin.clear();
        cin.ignore(1000, '\n');
        if(a==1){
            cout << "Invalid Data Type" << endl;
        }
        return 0;
    }
    return 1;
}
void Telescience::allinputs() {
    cout << "X input value: ";
    while(input(&xin,1)!=1) {
        cout << "X input value: ";
    }
    cout << "Y input value: ";
    while(input(&yin,1)!=1) {
        cout << "Y input value: ";
    }
    cout << "X result value: ";
    while(input(&xout1,1)!=1) {
        cout << "X result value: ";
    }
    cout << "Y result value: ";
    while(input(&yout1,1)!=1) {
        cout << "Y result value: ";
    }
    cout << "Second X result value: ";
    while(input(&xout2,1)!=1) {
        cout << "Second X result value: ";
    }
    cout << "Second Y result value: ";
    while(input(&yout2,1)!=1) {
        cout << "Second Y result value: ";
    }
}
void Telescience::build(){
    allinputs();
    mx = xout2-xout1;
    my = yout2-yout1;
    cx = xout1-mx*xin;
    cy = yout1-my*yin;
    save();
    cin.ignore();
    sof();
}
void Telescience::inpbuild(){
    cout << "MX: ";
    while(input(&mx,1)!=1) {
        cout << "MX: ";
    }
    cout << "MY: ";
    while(input(&my,1)!=1) {
        cout << "MY: ";
    }
    cout << "CX: ";
    while(input(&cx,1)!=1) {
        cout << "CX: ";
    }
    cout << "CY: ";
    while(input(&cy,1)!=1) {
        cout << "CY: ";
    }
    save();
    cin.ignore();
    sof();
}
void Telescience::sof(){
    cout << "'find', 'search', 'list', or 'print'?" << endl << "> ";
    getline(cin,sf);
    if(sf == "list" || sf == "search") {
        tsearch();
        sof();
    }else if(sf == "find") {
        find();
    }else if(sf == "print") {
        cout << "MX: " << mx << " " << "MY: " << my << " " << "CX: " << cx << " "
             << "CY: " << cy << " " << endl << endl
             << "X Equation" << "(X-" << cx << ")/" << mx << endl
             << "Y Equation" << "(Y-" << cy << ")/" << my << endl;
        sof();
    }else if(sf == "exit" || sf == "e") {
        init();
    }else{
        cout << "Invalid Command" << endl;
        sof();
    }
}
void Telescience::find(){
    exit = "n";
    while(exit=="n") {
        cout << "Desired X: ";
        if(input(&xout1,0)!=1) {
            exit = "y";
        }
        if(exit!="y") { 
            cout << "Desired Y: ";
            if(input(&yout1,0)!=1) {
                exit = "y";
            }
        }
        if(exit!="y") {
            cout << "Input X: " << (xout1-cx)/mx << " Input Y: " << (yout1-cy)/my << endl << endl;
        }
    }
    sof();
}
void Telescience::tsearch(){
    Global global;
    int test=1;
    while(test==1) {
        if(sf == "list"||sf == "search"){ //unnecessary check?
            if(global.search(sf,"Coordinates.txt",3,2)==1) {
                test=0;
            }else{
                if(global.pub3==1){
                    xout1=global.pub1;
                    yout1=global.pub2;
                    cout << "Input X: " << (xout1-cx)/mx << " Input Y: " << (yout1-cy)/my << endl;
                    global.pub3=0;
                }else if(global.pub3==2){
                    int vecsize = global.pubvec.end()-global.pubvec.begin();
                    for(int x=0; x<vecsize-1;x++){
                        cout << endl << "Enter item name: " << global.pubvec[x] << endl;
                        xout1=global.todouble(global.pubvec[++x]);
                        yout1=global.todouble(global.pubvec[++x]);
                        cout << "Input X: " << (xout1-cx)/mx << " Input Y: " << (yout1-cy)/my << endl << endl;
                    }
                    global.pubvec.clear();
                    global.pub3=0;
                }else{
                    cout << "Unknown Coordinates" << endl;
                }
            }
        }
        sf = "search";
    }
}