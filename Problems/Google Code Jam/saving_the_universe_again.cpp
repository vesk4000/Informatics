#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int t;
int d;
int curr_d;
string p;
string anz;

string convertToString(int n)
{
    ostringstream convert;
    convert << n;
    string result = convert.str();
    return result;
}

int calculate_damage(string x) {
	int c_dmg = 1;
	int a_dmg = 0;
	for(int i = 0; i < x.size(); ++i) {
		if(x[i] == 'S')
			a_dmg += c_dmg;
		if(x[i] == 'C')
			c_dmg *= 2;
	}
	return a_dmg;
}

int main() {
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cin >> d >> p;
		int ans = 0;
		while(calculate_damage(p) > d) {
			bool flag = false;
			for(int j = p.size() - 1; j >= 0; --j) {
				if(p[j] == 'C' && (j != p.size() - 1 && p[j + 1] != 'C')) {
					swap(p[j], p[j + 1]);
					break;
				}
				if(j == 0)
					flag = true;
			}
			if(flag == true) {
				anz = anz + "Case #" + convertToString(i) + ": " + "IMPOSSIBLE" + "\n";
				ans = -1;
				break;
			}
			++ans;
		}
		if(ans != -1)
			anz = anz + "Case #" + convertToString(i) + ": " + convertToString(ans) + "\n";
	}
	cout << anz;
	return 0;
}
