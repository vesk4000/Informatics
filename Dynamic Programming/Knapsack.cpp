#include <iostream>

using namespace std;

int n;
const int maxn = 128;
int capacity;
const int maxsum = 128;
int weights[maxn];
int values[maxn];
int dpt[maxn][maxsum];

int main()
{
	cin >> n;
	for(int i = 1;i <= n; ++i)
	{
		cin >> weights[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		cin >> values[i];
	}
	cin >> capacity;

	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= capacity; ++j)
		{
			/*int a, b;
			if(i == 0) dpt[i][j] = 0;
			else
			{

				if(j - weights[i-13] >=0)
				{
					a = dpt[i-1][j];
					b = dpt[i-1][j - weights[i]] + values[i - 1];
					dpt[i][j] = max(a,b);
				}
				else dpt[i][j] = 0;
			}*/

			if(weights[i] > j)
			dpt[i][j] = dpt[i - 1][j];
			else
			dpt[i][j] = max(dpt[i - 1][j], values[i] + dpt[i][j - weights[i]]);
			cout << dpt[i][j] << " ";
		}
		cout << endl;
	}
	cout<<dpt[n-1][capacity]<<endl;
	return 0;
}
