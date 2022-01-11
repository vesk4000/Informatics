#include <iostream>

using namespace std;

int n;
const int maxn = 100100;
string page;
int dt[maxn];

int solve()
{
	if(n == 1)
		return -1;
	if(n == 2)
	{
		if(page[0] == page[1])
			return 1;
		else
			return -1;
	}
	if(n == 3)
	{
		if(page[0] == page[1] || page[1] == page[2] || page[0] == page[2])
			return 1;
		else
			return -1;
	}
	for(int i = 2;i < n; ++i)
	{
		if(page[i] == page[i - 1])
		{
			dt[i] = dt[i - 2];
		}
	}
}

int main()
{
	///input
	cin >> n;
	cin >> page;
	cout << solve() << endl;
	return 0;
}
