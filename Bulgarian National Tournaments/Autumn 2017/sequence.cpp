#include <iostream>

using namespace std;

int n, m, k;
long long int dt[32][32][32];

///Recursion with memoization
long long int solve(int index, int num, int currK) {
	//cout << index << " " << num << " " << currK << endl;
	if(index == n)
		return 1;
	if(dt[index][num][currK])
		return dt[index][num][currK];
	long long int ans = 0;
	if(num < m)
		ans += solve(index, num + 1, 0);
	if(currK < k)
		ans += solve(index + 1, num, currK + 1);
	return dt[index][num][currK] = ans;
}

int main() {
	cin >> n >> m >> k;
	cout << solve(0, 1, 0) << endl;
	return 0;
}
