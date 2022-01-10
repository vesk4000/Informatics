#include <iostream>
#include <string>
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

int main() {
	string a, b;
	cin >> a >> b;
	cout << sum(a, b) << endl;
	return 0;
}