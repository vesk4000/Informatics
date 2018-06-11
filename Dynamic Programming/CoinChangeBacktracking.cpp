#include <iostream>

using namespace std;

const int maxn = 10000;
int a[maxn];
int ans;
int n;

void backtrack(int index, int sum)
{
	if(sum < 0)
	{
		return;
	}

	if(sum == 0)
	{
		++ans;
		return;
	}

	if(index < 0 && sum >= 1)
	{
		return;
	}

	backtrack(index, sum - a[index]);
	backtrack(index - 1, sum);
}

int main()
{
	int sum;
	cin >> n;
	for(int i = 0;i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> sum;

	cout << 0 << " ";
	for(int i = 0;i <= sum; ++i)
	{
		cout << i << " ";
	}
	cout << endl;

	for(int i = 0;i < n; ++i)
	{
		cout << a[i] << " ";
		for(int j = 0;j <= sum; ++j)
		{
			ans = 0;
			backtrack(i, j);
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
