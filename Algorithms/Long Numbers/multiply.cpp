#include <iostream>
#include <string>
#include "multiplyLongByShort.cpp"

using namespace std;

string Multiply(string la, string lb)
{
	if(la == "0" || lb == "0")
		return "0";
	string sum = "";
	int j = 0;
	for(int i = lb.size() - 1; i >= 0; --i)
	{
		sum = Add(sum, FillBack(MultiplyLongByShort(la, lb[i]), j) );
		++j;
	}
	return sum;
}
