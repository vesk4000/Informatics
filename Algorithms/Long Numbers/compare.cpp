#include <iostream>

using namespace std;

enum compAns {smaller, equul, bigger};

compAns Compare(string la, string lb)
{
	if(la.size() > lb.size())
		return bigger;
	if(la.size() < lb.size())
		return smaller;

	for(int i = 0;i < la.size(); ++i)
	{
		if(la[i] > lb[i])
			return bigger;
		if(la[i] < lb[i])
			return smaller;
	}

	return equul;
}

string Bigger(string la, string lb)
{
	if(Compare(la, lb) == bigger || Compare(la, lb) == equul)
		return la;
	return lb;
}

string Smaller(string la, string lb)
{
	if(Compare(la, lb) == smaller || Compare(la, lb) == equul)
		return lb;
	return la;
}
