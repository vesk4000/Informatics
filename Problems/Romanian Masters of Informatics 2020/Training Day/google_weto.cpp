#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverse(string &a) {
	string ans = "";
	for(int i = a.size() - 1; i >= 0; --i)
		ans += a[i];
	a = ans;
}

string sum(string a, string b) {
	reverse(a);
	reverse(b);
	if(a.size() < b.size())
		swap(a, b);
	
	string ans = "";
	int d = 0;
	for(int i = 0; i < a.size(); ++i) {
		int da = a[i] - '0';
		int db;
		if(i < b.size())
			db = b[i] - '0';
		else
			db = 0;
		int dans = da + db + d;
		if(dans >= 10) {
			dans -= 10;
			d = 1;
		}
		else
			d = 0;
		
		ans += dans + '0';
	}
	if(d > 0)
		ans += '1';
	reverse(ans);
	return ans;
}

string SolveWithString(string a, string b)
{
	if (a.size() < b.size())
		swap(a, b);
    string result = "";
    int remainder = 0;
    for (int i = 1; i <= a.size(); ++i)
    {
        int currentNumberA = a[a.size() - i] - '0', currentNumberB = 0;
        if (i <= (int)b.size()) currentNumberB = b[b.size() - i] - '0';
        int sum = currentNumberA + currentNumberB + remainder;
        a[a.size() - i] = (sum % 10) + '0';
        remainder = sum / 10;
        //cout << a << endl;
    }
    if (remainder != 0) result += (remainder) + '0';
    result += a;
    return result;
}

int main() {
	while(true) {
		string a = "", b = "";
		int a_n = rand() % 1000;
		int b_n = rand() % 1000;
		for(int i = 0; i < a_n; ++i)
			a += to_string(rand());
		for(int i = 0; i < b_n; ++i)
			b += to_string(rand());
		
		if(sum(a, b) != SolveWithString(a, b)) {
			cout << "WRONG!" << endl;
			cout << a << " " << b << endl;
			cout << sum(a, b) << endl;
			cout << SolveWithString(a, b) << endl;
			break;
		}
		else
			cout << "correct" << endl;
	}
	
	return 0;
}