//
//  LongLongInt.h
//  data_structure
//
//  Created by Fushimi on 2025/3/17.
//
#ifndef LONGLONGINT_H
#define LONGLONGINT_H
#include <iostream>

using std::ostream;

class LongLongInt
{
    friend LongLongInt operator+(const LongLongInt &, const LongLongInt &);
    friend LongLongInt operator-(const LongLongInt &, const LongLongInt &);
    friend ostream & operator<<(ostream &, const LongLongInt &);
private:
    char sign;
    char* num;
public:
    LongLongInt(const char *n = "");
    LongLongInt(const LongLongInt &);
    LongLongInt& operator=(const LongLongInt &);
    ~LongLongInt(){delete num;}
};

char* add(const char* s1, const char* s2); //绝对值加法 s1 > s2
char* sub(const char* s1, const char* s2); //绝对值减法 s1 > s2
bool lli_cmp(const char* s1, const char* s2); //if s1 is greater than s2 return ture
#endif
