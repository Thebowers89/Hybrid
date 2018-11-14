#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
using namespace std;

class Global {
public:
    double todouble(string input);
    void prettiness(string prettiness);
    int contains(string contains,char character);
    string ignorecase(string ignorecase);
    void read(string a);
    void loop();
    int search(string lcmd, string lfile, int lelm, int lall);
    double pub1,pub2;
private:
    string inp, cmd, file;
    int all, elm;
};

#endif