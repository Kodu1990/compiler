/* 
 * File:   cradle.h
 * Author: Adam
 *
 * Created on October 25, 2015, 10:01 PM
 */
#include <string>
#ifndef CRADLE_H
#define	CRADLE_H
#define UPCASE(C) ((C - 'a') + 'A')
#define MAX_BUF 100
extern char tmp[MAX_BUF];
extern char look;
extern char CR;

void getChar();

void Error (std::string s);
void Abort (std::string s);
void Expected(std::string s);
void Match(char x);
void SkipWhite();
bool isAlpha(char c);
bool isWhite(char c);
bool isDigit(char c);
bool isAddop(char c);
bool isAlNum(char c);
std::string getName();
int getNum();

void Emit(std::string s);
void EmitLn(std::string s);
void init();
#endif	/* CRADLE_H */

