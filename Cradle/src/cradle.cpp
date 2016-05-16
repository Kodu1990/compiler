
#include <cradle.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
char look ;
char tmp [MAX_BUF];
void getChar()
{
    look = cin.get();
}

void Error (std::string s){
    cerr << "\nError: " << s << endl;
}

void Abort(std::string s){
    Error(s);
    exit(1);
}

void Expected(std::string s){
    cout <<  s <<" Expected" << endl;
}

void Match (char x){
    if(look ==x){
        getChar();
        SkipWhite();
    }else{
        cout << tmp << x;
        Expected(tmp);
    }
}

void SkipWhite(){
    while(isWhite(look)){
        getChar();
    }
}

bool isAlpha(char c){    
    return (UPCASE(c) >= 'A') && (UPCASE(c)<='Z');
}

bool isDigit(char c){
    return (c >='0') && (c<='9');
}

bool isAddop(char c){
    return (c == '+') || (c == '-');
}
bool isAlNum(char c){
    return isAlpha(c) || isDigit(c);
}
bool isWhite(char c){
    return c == ' ' || c == '\t';
}
string getName(){
    string token ="";
    
    if(!isAlpha(look)){
        Expected("Name");
    }
    while(isAlNum(look)){
        token = token + (char)UPCASE(look);
        getChar();
    }
    SkipWhite();
    return token;
}

int getNum(){
    
    int value =0;

    if(!isDigit(look)){
        Expected("Integer");
        return -1;
    }
    while(isDigit(look)){
        value = 10* value +static_cast<int>(look)-'0';
        getChar();
    }
    SkipWhite();
    return value;
}

void Emit(std::string s){
    cout << "\t" <<s << endl;
}

void EmitLn(std::string s){
    Emit(s);
    cout << "\n" << endl;
}
void init(){
    getChar();
    SkipWhite();
}