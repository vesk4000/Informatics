#include <iostream>

using namespace std;

int n;
int mw;
int w[500];///maxn
int v[500];///maxn
int dt[500][1000];/// index max n; weight max mw

int main()
{
	cin >> n;
	for(int i = 1;i <= n; ++i)
	{
		cin >> w[i] >> v[i];
	}
	cin >> mw;

	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= mw; ++j)
		{
			if(w[i] > j)
			dt[i][j] = dt[i - 1][j];
			else
			dt[i][j] = max(dt[i - 1][j], v[i] + dt[i - 1][j - w[i]]);
		}
	}
	cout << dt[n][mw] << endl;
	return 0;
}
