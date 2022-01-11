#include <iostream>
#include <string>
#include <algorithm>
#include "compare.cpp"
#include "fillWithZeros.cpp"

using namespace std;

string Add(string la, string lb)
{
	if(Compare(la, lb) == smaller)
		swap(la, lb);
	lb = FillFront(lb, la.size() - lb.size());

	string sum = "";
	int carry = 0;
	for(int i = la.size() - 1;i >= 0; --i)
	{
		sum = sum + char( ((la[i] - '0') + (lb[i] - '0') + carry) % 10 + '0');
		carry = ((la[i] - '0') + (lb[i] - '0') + carry) / 10;

	}
	if(carry == 1)
		sum = sum + '1';
	reverse(sum.begin(), sum.end());
	return sum;
}
