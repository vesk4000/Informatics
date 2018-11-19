#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int n;
const int maxn = 1024;///1000
long long int a[maxn];

long long int dt[maxn][maxn];

///solve recursively with memoization
long long int solve(int left, int right)
{
	///invalid
	if(left > right)
		return 0;

	///memoization
	if(dt[left][right])
		return dt[left][right];

	///end of recursion
	if(left == right)
		return dt[left][right] = a[left];

	dt[left][right] = numeric_limits<long long int>::min();///Basically -INF

	/// 1) take 1
	///take the right one
	dt[left][right] = max(dt[left][right], solve(left, right - 1) + a[right]);

	if(right - left >= 1)
	{
		/// 2) take 2
		///take the 2 rightmost ones
		dt[left][right] = max(dt[left][right], solve(left, right - 2) + a[right] * a[right - 1]);
		///take the 2 leftmost ones
		dt[left][right] = max(dt[left][right], solve(left + 2, right) + a[left] * a[left + 1]);
	}

	if(right - left >= 2)
	{
		/// 3) take 3
		///take the 2 left ones and the right one
		dt[left][right] = max(dt[left][right], solve(left + 2, right - 1) + a[left] * a[left + 1] * a[right]);
		///take the 3 rightmost ones
		dt[left][right] = max(dt[left][right], solve(left, right - 3) + a[right] * a[right - 1] * a[right - 2]);
	}

	return dt[left][right];
}

int main()
{
	///input
	cin >> n;
	for(int i = 0;i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	cout << solve(0, n - 1) << endl;
	return 0;
}
