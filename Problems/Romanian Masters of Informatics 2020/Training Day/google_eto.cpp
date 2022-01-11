#include <iostream>
#include <string>
using namespace std;
string SolveWithString(string a, string b)
{
    string result = "";
    int remainder = 0;
    for (int i = 1; i <= a.size(); ++i)
    {
        int currentNumberA = a[a.size() - i] - '0', currentNumberB = 0;
        if (i <= (int)b.size()) currentNumberB = b[b.size() - i] - '0';
        int sum = currentNumberA + currentNumberB + remainder;
        a[a.size() - i] = (sum % 10) + '0';
        remainder = sum / 10;
        cout << a << endl;
    }
    if (remainder != 0) result += (remainder) + '0';
    result += a;
    return result;
}

int main()
{
    string s, s1;
    cin >> s >> s1;
    if (s.size() < s1.size()) swap(s, s1);
    cout << SolveWithString(s, s1) << endl;
}