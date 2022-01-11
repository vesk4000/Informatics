#include <iostream>

using namespace std;

int n;
const int maxn = 512;
int sum;
const int maxsum = 131072;
int a[maxn];
int dpt[maxn][maxsum];
const int maxt = 64;
int ans[maxt];

int main()
{
	int t;
	cin >> t;
	for(int k = 0;k < t; ++k)
	{
	cin >> n;
	for(int i = 0;i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> sum;

	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j <= sum; ++j)
		{
			dpt[i][j] = 0;
		}
	}
	dpt[0][0] = 1;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j <= sum; ++j)
		{
			if(i > 0)
				dpt[i][j] = dpt[i - 1][j];
			if(j - a[i] >= 0)
				dpt[i][j] += dpt[i][j - a[i]];
		}
	}
	ans[k] = dpt[n - 1][sum];
	}
	for(int i = 0;i < t; ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
