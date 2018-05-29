#include <bits\stdc++.h>

using namespace std;

enum compAns {smaller, ravni, bigger};

string a, b;
string k;

string add(string la, string lb);
compAns comp(string la, string lb);
string multprivate(string la, char lb);
string multpublic(string la, string lb);
string fillWithZeros(string la, int br);
string addZeros(string la, int br);


string add(string la, string lb)
{
    string sum = "";
    if(comp(la, lb) == smaller)
        swap(la, lb);

        lb = fillWithZeros(lb,la.size() -  lb.size());
    reverse(la.begin(), la.end());
    reverse(lb.begin(), lb.end());



    int prenos = 0;
    for(int i = 0;i < la.size(); ++i)
    {
        if(prenos + la[i] - '0' + lb[i]  - '0' > 9 )
        {
            sum = sum + char( prenos + (la[i] - '0') + (lb[i]  - '0') - 10 +'0' );
            prenos = 1;
        }
        else
        {
            sum = sum + char( prenos + la[i] - '0' + lb[i]  - '0' + '0' );
            prenos = 0;
        }
    }
    if(prenos == 1)
    {
        sum = sum + '1';
    }
    reverse(sum.begin(), sum.end() );
    return sum;
}

compAns comp(string la, string lb)///a comp. to b
{
    if(la.size() < lb.size())
        return smaller;
    if(la.size() > lb.size())
        return bigger;

    for(int i = 0;i < la.size(); ++i)
    {
        if(la[i] < lb[i])
            return smaller;
        if(la[i] > lb[i])
            return bigger;
    }
    return ravni;
}

string multprivate(string la, char lb)
{
    string sum = "";
    reverse(la.begin(), la.end());
	if(lb == '0')
		return "0";
    int prenos = 0;
    for(int i = 0;i < la.size(); ++i)
    {
        if(prenos + ( (la[i] - '0') * (lb  - '0') ) > 9 )
		{
            sum = sum + char( (prenos + ( (la[i] - '0') * (lb  - '0') ) ) % 10 + '0');
            prenos = (prenos + ( (la[i] - '0') * (lb  - '0') ) ) / 10;
        }
        else
        {
            sum = sum + char(prenos + ( (la[i] - '0') * (lb  - '0') )  + '0');
            prenos = 0;
        }
    }
    if(prenos > 0)
        sum = sum + char(prenos + '0');

    reverse(sum.begin(), sum.end());
    //cout << sum << endl;
    return sum;
}

string fillWithZeros(string la, int br)
{
    for(int i= 0;i < br;++i)
    {
        la = '0' + la;
    }
    return la;
}

string multpublic(string la, string lb)
{
    string sum = "0";
    if(comp(la, lb) == smaller)
        swap(la, lb);

	int j = 0;
    for(int i = lb.size() - 1; i >= 0; --i)
    {
		//cout << sum << " " << multprivate(la, lb[i])) << endl;
        sum = add(sum, addZeros(multprivate(la, lb[i]), j));
        //cout << sum << endl;
        ++j;
    }
    return sum;
}

string addZeros(string la, int br)
{
	for(int i = 0;i < br; ++i)
		la = la + '0';
	return la;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    if(comp(a,b) == smaller)
    {
       cout << 0 << endl;
       return 0;
    }

    //cout << multprivate(a, b[0]) << " " << add(a, b) << endl;
    cout << multpublic(a, b) << endl;
    return 0;
}
