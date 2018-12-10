#include "Global.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

double Global::todouble(string input){
    double ret=0;
    int places=0;
    if(input.length()==3) {
        places = 3;
    }else if(input.length()==2){
        places = 2;
    }else if(input.length()==1){
        places = 1;
    }
    for(int a=0;a<input.length();a++){
        if(places==3){
            ret += (input[a]-48)*100;
            places --;
        }else if(places==2){
            ret += (input[a]-48)*10;
            places --;
        }else if(places==1){
            ret += (input[a]-48);
        }
    }
    return ret;
}
void Global::prettiness(string prettiness) {
    string dashes;
    char c = '-';
    for(int a=0;a<prettiness.length();a++){
        dashes+=c;
    }
    cout << dashes << endl << prettiness << endl << dashes << endl;
}
int Global::contains(string contains,char character) {
    auto check = contains.find(character);
    if(check != string::npos) {
        return 1;
    }else{
        return 0;
    }
}
string Global::ignorecase(string ignorecase) {
    for(int a=0;a<ignorecase.length();a++) {
        ignorecase[a] = char(tolower(ignorecase[a]));
    }
    return ignorecase;
}
void Global::read(string a) {
    int strtpnt,endpnt,el=0,hashnumber=0;
    for(int x=0;x<a.length();x++){
        if(a[x]=='`'){
            hashnumber++;
        }
    }
    string sarray[hashnumber/2];
    while(endpnt != a.length()){
        strtpnt = a.find('`');
        a.replace(strtpnt,1,"");
        endpnt = a.find('`');
        a.replace(endpnt,1,"");
        sarray[el] = a.substr(strtpnt,endpnt-strtpnt);
        el++;
    }
    if(cat==1){
        if(contains(sarray[0],'|')==0){
            pubvec.push_back(sarray[0]);
            pubvec.push_back(sarray[1]);
            pubvec.push_back(sarray[2]);
        }else{
            cat=0;
            pub3=2;
        }
    }
    if(all==2){
        if(cmd=="search") {
            cmd="tsearch";
        }
    }
    if(cmd=="search"||cmd=="tsearch"){
        if(ignorecase(inp) == ignorecase(sarray[0]) && contains(inp,'|') == 0) {
            if(cmd=="search") {
                if(all==1) {
                    elm = hashnumber/2;
                }
                for(int i=1;i<elm;i++){
                    cout << sarray[i] << endl;
                }
            }else if(cmd=="tsearch") {
                pub1=todouble(sarray[1]);
                pub2=todouble(sarray[2]);
                pub3=1;
            }
        }else if(ignorecase(inp) == ignorecase(sarray[0]) && contains(inp,'|') == 1){
            if(cat==0){
                cat=1;
            }
        }
    }else if(cmd=="list"){
        if(contains(sarray[0],'|') == 1) {
            sarray[0].replace(sarray[0].find('|'),1,"");
            prettiness(sarray[0]);
        }else{
            cout << sarray[0] << endl;
        }
    }
}
void Global::loop(){
    if(cmd=="search"){
        cout << "\nEnter item name: ";
        getline(cin,inp);
    }
    ifstream infile(file);
    while(getline(infile,a)) {
        auto thing = a.rfind('\r');
        if(thing != string::npos)
            a = a.substr(0,thing);
            read(a);
    }
    infile.close();
}
int Global::search(string lcmd, string lfile, int lelm, int lall){
    cmd = lcmd;
    file = lfile;
    elm = lelm;
    all = lall;
    loop();
    if(cmd=="tsearch"&&inp!="exit"&&inp!="e"){
        return 0;
    }
    if(cmd=="list"&&inp!="exit"&&inp!="e"){
        cmd="search";
        loop();
    }
    if(ignorecase(inp)=="exit"||ignorecase(inp)=="e"){
        inp = "potato";
        return 1;
    }else{
        search(cmd,file,elm,all);
    }
}