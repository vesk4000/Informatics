#include <iostream>
#include <limits>
#include <vector>
#include <cstring>
using namespace std;

int n;
int q;
const int MAXNQ = 5000;
int c[MAXNQ];
//vector<int> zero_sums[MAXNQ];// The indexes of all of the elements that zero_sums[i] forms a zero sum with
int first_zero_sum[MAXNQ];// The index of the first element that c[i] forms a zero sum with

int solve(int l, int r) {
	//cout << l << " " << r << endl;
	if(l > r) // If we have gone past the end of the query range
		return 0;
	if(l == r) { // If we are at the last element
		if(first_zero_sum[l] == l)
			return 1;
		return 0;
	}

	int ans = 0;
	if(first_zero_sum[l] != -1 && first_zero_sum[l] <= r)
		ans = max( solve(first_zero_sum[l] + 1, r) + 1, solve(l + 1, r) );
	else
		ans = solve(l + 1, r);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> c[i];

	memset(first_zero_sum, -1, sizeof(first_zero_sum));

	for(int i = 0; i < n; ++i) {
		long long int sum = 0;
		for(int j = i; j < n; ++j) {
			sum += c[j];
			if(sum == 0) {
				first_zero_sum[i] = j;
				break;
			}
		}
		//cout << c[i] << " " << first_zero_sum[i] << endl;
	}

	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		cout << solve(l, r) << endl;
	}

	return 0;
}