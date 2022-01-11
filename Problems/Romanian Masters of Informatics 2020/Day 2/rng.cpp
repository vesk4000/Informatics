#include <iostream>
using namespace std;

int irandom(int mn, int mx) { 
	return rand() % (abs(mx - mn) + 1) + mn;
}

int main() {
	int n;
	cin >> n;
	/*int mn;
	cin >> mn;
	int mx;
	cin >> mx;*/
	for(int i = 0; i < n; ++i) {
		cout << irandom(-10, 10) << endl;
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l = irandom(1, n);
		cout << l << " " << irandom(l, n) << endl; 
	}
	return 0;
}