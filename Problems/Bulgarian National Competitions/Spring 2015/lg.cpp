#include <bits\stdc++.h>

using namespace std;

enum compAns {smaller, equul, bigger};
compAns Compare(string la, string lb);
string Add(string la, string lb);
string FillFront(string la, int ln);
string MultiplyLongByShort(string la, char lb);
string Multiply(string la, string lb);
string FillBack(string la, int ln);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	string k;
	cin >> a >> b;

	if(Compare(a, b) == smaller)
	{
		cout << 0 << endl;
		return 0;
	}
	string orb = b;
	for(k = "1";;k = Add(k, "1"))
	{
		b = Multiply(b, orb);
		//cout << k << " " << b << endl;
		if(Compare(a, b) == smaller)
		{
			cout << k << endl;
			return 0;
		}
	}
	return 0;
}

///Compare
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

///Add
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

///FillFront
string FillFront(string la, int ln)
{
	for(int i = 0;i < ln; ++i)
		la = '0' + la;
	return la;
}

///FillBack
string FillBack(string la, int ln)
{
	for(int i = 0;i < ln; ++i)
		la = la + '0';
	return la;
}

///MultiplyLongByShort
string MultiplyLongByShort(string la, char lb)
{
	string sum = "";
	int carry = 0;
	for(int i = la.size() - 1;i >= 0; --i)
	{
		sum = sum + char( ((la[i] - '0') * (lb - '0') + carry) % 10 + '0' );
		carry = ((la[i] - '0') * (lb - '0') + carry) / 10;
	}
	if(carry > 0)
		sum = sum + char(carry + '0');
	reverse(sum.begin(), sum.end());
	return sum;
}

///Multiply
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
