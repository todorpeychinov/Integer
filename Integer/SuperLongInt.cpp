#include "SuperLongInt.h"
#include <string.h>
#include <stdlib.h>

SuperLongInt::SuperLongInt()
{
    for (int i = 0; i < 100; i++)
    {
        Number[i] = 0;
    }
	Len = 0;
}

SuperLongInt::SuperLongInt(int decimalNumber)
{
    int counter = 0;
    Number[99] = '\0';
    int i = 98;
    if (decimalNumber < 0)
    {
        NegativeFlag = 1;
        decimalNumber *= -1;
    }

    while (decimalNumber > 0) {
        Number[i] = (char)(decimalNumber % 10 + '0');
        decimalNumber /= 10;
        i--;
        counter++;
    }
    Len = counter;
}

SuperLongInt::SuperLongInt(char* b)
{
    int n = strlen(b);
    int i = 0;
    if (n < 100)
        OverFlowFlag = 0;
    else {
        OverFlowFlag = 1;
        i = n - 100;
    }
    if (b[0] == '-')
        NegativeFlag = 1;
    else
        NegativeFlag = 0;

    for (i = NegativeFlag; i < n; i++)
        Number[100 - n - 1 + i] = b[i];
    Number[99] = '\0';
    Len = 100 - n + NegativeFlag - 1;
      
}

SuperLongInt::SuperLongInt(double number)
{
    int decimalNumber = (int)number;
    int counter = 0;
    Number[99] = '\0';
    int i = 98;
    if (decimalNumber < 0)
    {
        NegativeFlag = 1;
        decimalNumber *= -1;
    }

    while (decimalNumber > 0) {
        Number[i] = (char)(decimalNumber % 10 + '0');
        decimalNumber /= 10;
        i--;
        counter++;
    }
    Len = counter;

}

SuperLongInt::SuperLongInt(const SuperLongInt& p)
{
    strcpy_s(Number, p.Number);
    NegativeFlag = p.NegativeFlag;
    OverFlowFlag = p.OverFlowFlag;
    Len = p.Len;
}

char* SuperLongInt::ToString()
{
    return &Number[99 - Len];
}

int SuperLongInt::ToFinancial()
{
    return atoi(&Number[99 - Len]);
}

SuperLongInt& SuperLongInt::operator=(SuperLongInt& p) 
{
    strcpy_s(Number, p.Number);
    NegativeFlag = p.NegativeFlag;
    OverFlowFlag = p.OverFlowFlag;
    Len = p.Len;
    return *this;
}

SuperLongInt SuperLongInt::operator+(SuperLongInt& p)
{
    int temp_int = (ToFinancial() + p.ToFinancial());
    if (temp_int > 99)
    {
        char num[100];
        num[99] = '\0';
        for (int i = 0; i < 99; i++)
        {
            num[i] = '9';
        }

        SuperLongInt temp(num);
        temp.OverFlowFlag = 1;
        return temp;
    }

    else
        return SuperLongInt(temp_int);
}

SuperLongInt SuperLongInt::operator-(SuperLongInt& p)
{
    int temp_int = (ToFinancial() - p.ToFinancial());
    if (temp_int < 0)
    {
        SuperLongInt temp(abs(temp_int));
        temp.NegativeFlag = 1;
        return temp;
    }
    else
    {
        SuperLongInt temp(temp_int);
        return temp;
    }
}

ostream& operator<<(ostream& o, SuperLongInt& r)
{
    return o << r.ToFinancial() << endl;
}

istream& operator>>(istream& i, SuperLongInt& r)
{
    char num[100];
    i >> num;
    SuperLongInt n(num); 
    r = n;
    return i;
}







