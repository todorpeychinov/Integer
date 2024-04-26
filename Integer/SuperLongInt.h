#pragma once
#include <iostream>
using namespace std;

class SuperLongInt
{
	char Number[100];
	int Len;
	int OverFlowFlag = 0;
	int NegativeFlag = 0;

public:
	SuperLongInt();
	SuperLongInt(int decimalNumber);
	SuperLongInt(char* number);
	SuperLongInt(double number);
	SuperLongInt(const SuperLongInt& p);
	char* ToString();
	int ToFinancial();
	SuperLongInt& operator=(SuperLongInt& p);
	SuperLongInt operator+(SuperLongInt& p);
	SuperLongInt operator-(SuperLongInt& p);
	friend ostream& operator<<(std::ostream& o, SuperLongInt& r);
	friend istream& operator>>(std::istream& i, SuperLongInt& r);
	



};

