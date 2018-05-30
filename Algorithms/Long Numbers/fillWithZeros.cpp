#include <iostream>

using namespace std;

string FillBack(string la, int ln)
{
	for(int i = 0;i < ln; ++i)
		la = la + '0';
	return la;
}

string FillFront(string la, int ln)
{
	for(int i = 0;i < ln; ++i)
		la = '0' + la;
	return la;
}
