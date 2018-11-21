#include <iostream>
using namespace std;

int n;
int a[512];
int dt[512][512];

int solve(int l, int r) {
	if(l > r)
		return 0;
	if(l == r)
		return 0;
	//cout << l << " " << r << " " << dt[l][r] << endl;
	if(dt[l][r])
		return dt[l][r];
	if(a[l] == a[r]) {
		return dt[l][r] =  max(solve(l + 1, r - 1) + 2, solve(l + 1, r) + solve(l, r - 1) );
	}
	else
		return dt[l][r] = solve(l + 1, r)+ solve(l, r - 1);
}

int main() {
	cin >> n;
	for(int i = 0;i < n; ++i)
		cin >> a[i];
	cout << solve(0, n - 1) << endl;
	for(int l = 0;l < n; ++l) {
		for(int r = l + 1;r < n; ++r) {
			cout << "left: " << l << " right: " << r << "| " << dt[l][r] << "|";
			for(int i = l; i <= r; ++i)
				cout << " " << a[i];
			cout << endl;
		}
		//cout << endl;
	}
	return 0;
}
