#include <iostream>
using namespace std;

int n;
const int MAXN = 1e6 + 1;

int q[MAXN];

int fact(int x) {
	if(x == 0)
		return 1;
	return x * fact(x - 1);
}

int solve(int b[22]) {
	int numminone = 0;

	int a[22];
	for(int i = 0; i < n; ++i)
		a[i] = b[i];
	

	for(int i = 0; i < n; ++i) {
		if(a[i] == -1)
			++numminone;
	}

	for(int i = 1; i < n - 1; ++i) {
		if(q[i] != a[i - 1] && q[i] != a[i + 1]) {
			int ans = 0;
			if(!(a[i - 1] == -1 || a[i + 1] == -1)) {
				return 0;
			}
			if(a[i - 1] == -1) {
				a[i - 1] = q[i];
				ans += solve(a);
				a[i - 1] = -1;
				--numminone;
			}
			if(a[i + 1] == -1) {
				a[i + 1] = q[i];
				ans += solve(a);
				a[i + 1] = -1;
				--numminone;
			}
			if(a[i + 1] == -1 && a[i - 1] == -1)
			++numminone;
			return ans * fact(numminone);
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> q[i];
	}
	int a[22];
	for(int i = 0; i < 22; ++i)
		a[i] = -1;
	a[1] = q[0];
	a[n - 2] = q[n - 1];
	cout << solve(a) << endl;
}

/*
5
1 3 1 4 2
*/