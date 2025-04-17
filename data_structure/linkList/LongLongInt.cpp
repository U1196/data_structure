//
//  LongLongInt.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/17.
//
#include <iostream>
#include "LongLongInt.h"

using namespace std;

LongLongInt::LongLongInt(const char *n)
{
    const char *tmp; //保留参数绝对值
    
    //设置符号位
    switch (n[0])
    {
        case '+':
            tmp = n + 1;
            sign = '+';
            break;
        case '-':
            tmp = n + 1;
            sign = '-';
        default:
            tmp = n;
            sign = '+';
            break;
    }
    
    //设置0为空字符串
    if(strcmp(tmp, "0") == 0)
    {
        tmp = "";
    }
    
    unsigned long len = strlen(tmp);
    num = new char [len + 1];
    for(int i = 0; i < len; ++i)
    {
        num[i] = tmp[len - i - 1];
    }
    num[len] = '\0';
}

LongLongInt::LongLongInt(const LongLongInt &other)
{
    sign = other.sign;
    num = new char[strlen(other.num) + 1];
    strcpy(num, other.num);
}

LongLongInt& LongLongInt::operator=(const LongLongInt &right)
{
    if(this == &right)
    {
        return *this;
    }
    delete num;
    sign = right.sign;
    num = new char[strlen(right.num) + 1];
    strcpy(num, right.num);
    return *this;
}

ostream& operator<<(ostream &os, const LongLongInt &obj)
{
    if(strlen(obj.num) == 0)
    {
        os << 0;
    }
    else
    {
        os << obj.sign;
        for(int i = strlen(obj.num) - 1; i >= 0; --i)
        {
            os << obj.num[i];
        }
    }
    return os;
}

LongLongInt operator+(const LongLongInt &n1, const LongLongInt &n2)
{
    LongLongInt n;
    delete n.num;
    if(n1.sign == n2.sign)
    {
        n.sign = n1.sign;
        n.num = add(n1.num, n2.num);
    }
    else if(lli_cmp(n1.num, n2.num))
    {
        n.sign = n1.sign;
        n.num = sub(n1.num, n2.num);
    }
    else
    {
        n.sign = n2.sign;
        n.num = sub(n2.num, n1.num);
    }
    return n;
}

LongLongInt operator-(const LongLongInt &n1, const LongLongInt &n2)
{
    LongLongInt n(n2);
    if(n.sign == '+')
    {
        n.sign = '-';
    }
    else
    {
        n.sign = '+';
    }
    return n1 + n;
}

char* add(const char* s1, const char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int minLen = (len1 > len2 ? len2 : len1);
    int len = (len1 > len2 ? len1 : len2) + 1; //include '\0'
    int carry = 0, result;
    char *num = new char[len + 1]; //include possible last carry
    int i; //加法进行位数记录
    for(i = 0; i < minLen; ++i)
    {
        result = s1[i] - '0' + s2[i] - '0' + carry;
        num[i] = result % 10 + '0';
        carry = result / 10;
    }
    while(i < len1) //n2结束
    {
        result = s1[i] - '0' + carry;
        num[i] = result % 10 + '0';
        carry = result / 10;
        ++i;
    }
    while(i < len2) //n2结束
    {
        result = s2[i] - '0' + carry;
        num[i] = result % 10 + '0';
        carry = result / 10;
        ++i;
    }
    if(carry != 0)
    {
        num[i++] = carry + '0';
    }
    num[i] = '\0';
    return num;
}

char* sub(const char* s1, const char* s2) //abs(s1) >= abs(s2)
{
    if(!strcmp(s1, s2))
    {
        return (char*)"";
    }
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int minus = 0;
    char* tmp = new char[len1 + 1];
    int i;
    for(i = 0; i < len2; ++i)
    {
        tmp[i] = s1[i] - s2[i] - minus;
        if(tmp[i] < 0)
        {
            tmp[i] += 10;
            minus = 1;
        }
        else
        {
            minus = 0;
        }
        tmp[i] += '0';
    }
    for(; i < len1; ++i)
    {
        tmp[i] = s1[i] - '0' - minus;
        if(tmp[i] < 0)
        {
            tmp[i] += 10;
            minus = 1;
        }
        else
        {
            minus = 0;
        }
        tmp[i] += '0';
    }
    do
    {
        --i;
    } while(i >= 0 && tmp[i] == 0); //去除前导0
    tmp[i + 1] = '\0';
    return tmp;
}

bool lli_cmp(const char* s1, const char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 > len2)
    {
        return true;
    }
    else if(len1 < len2)
    {
        return false;
    }
    else
    {
        for(int i = len1 - 1; i >= 0; --i)
        {
            if(s1[i] > s2[i])
            {
                return true;
            }
            else if(s1[i] < s2[i])
            {
                return false;
            }
            else ;
        }
        return false;
    }
}
