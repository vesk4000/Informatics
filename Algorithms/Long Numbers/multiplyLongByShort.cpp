#include <iostream>
#include <string>
#include <algorithm>
#include "add.cpp"

using namespace std;

string MultiplyLongByShort(string la, char lb)
{
	string sum = "";
	int carry = 0;
	for(int i = la.size() - 1;i >= 0; --i)
	{
		cout << sum << " " << la[i] << " " << lb << " " << carry <<endl;
		sum = sum + char( ((la[i] - '0') * (lb - '0') + carry) % 10 + '0' );
		carry = ((la[i] - '0') * (lb - '0')) / 10;
	}
	if(carry > 0)
		sum = sum + char(carry + '0');
	reverse(sum.begin(), sum.end());
	return sum;
}
