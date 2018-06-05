#include <iostream>

using namespace std;

int n;
int cn;
int a[256];
int dp[256][10000];
int sum;
int ans[256];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0;i < n; ++i)
	{
		cin >> cn;
		sum = 0;
		for(int j = 0; j < cn; ++j)
		{
			cin >> a[j];
			sum += a[j];
		}
		if(sum % 2 == 0)
		{
		sum /= 2;

		for(int j = 0;j < cn; ++j)
		{
			for(int k = 0;k <= sum; ++k)
			{
				dp[j][k] = 0;
				if(j == 0)
				{
					if(k == 0 || k == a[j])
						dp[j][k] = 1;
					else
						dp[j][k] = 0;
				}
				else
				{
					if(dp[j - 1][k] == 1)
						dp[j][k] = 1;
					else if(k - a[j] >= 0 && dp[j - 1][k - a[j]] == 1)
							dp[j][k] = 1;
				}
			}
		}
		if(dp[cn - 1][sum] == 1)
			ans[i] = 1;}
	}

	for(int i = 0;i < n; ++i)
		cout << ans[i] << endl;
	return 0;
}
