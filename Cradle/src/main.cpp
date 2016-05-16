/* 
 * File:   main.cpp
 * Author: Adam
 *
 * Created on October 24, 2015, 5:35 PM
 */

#include <cstdlib>
#include <cradle.h>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;


int Term();
int Expression();
int Factor();
char CR='\n';

void Ident(){
    // convert to string     
    string name =getName();
    
    if(look == '('){
        Match('(');
        Match(')');
        EmitLn("bsr $"+ name);
    }
    else{
        string s = "movl $"+name+", %edx";
        EmitLn(s);
    }
}
int Factor()
{
    int val =0;
    if(look == '(') 
    {
        Match('(');
        val = Expression();
        Match(')');
        return val;
    } 
    else 
    {
        return getNum();
    }
}

int Term()
{
    int value =getNum();
    while (strchr("*/", look)) 
    {
        switch(look)
        {
            case '*':
                value = value*getNum();
                break;
            case '/':
                value = value/getNum();
                break;
            default:
                Expected("Mulop");
        }
    }
    return value;
}

int Expression()
{
    int val ;
    if(isAddop(look))
        val =0;
    else
        val = getNum();


    while (isAddop(look)) 
    {
        switch(look)
        {
            case '+':
                Match('+');
                val = val + Term();
                break;
            case '-':
                Match('-');
                val = val - Term();
                break;
            default:
                Expected("Addop");
        }
    }
    return val;
}

void Assignment()
{
    string name = getName();    
    Match('=');
    Expression();
    EmitLn("leal %eax, "+name);
    EmitLn("movl %eax, %edx");
}




int main()
{
    while(true)
    {
        init();
        cout << Expression() <<CR;
//        Assignment();
//        if(look != CR){
//            Expected("NewLine");
//        }
    }
    return 0;
}

