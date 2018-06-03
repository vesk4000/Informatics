#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long int num;
unsigned long long int ans;

vector <int> digs;

void backtrack(unsigned long long int n, int digi)
{
	//cout << n << " " << digi << endl;
	if( n >= num || digi >= digs.size() )
	{
		if( abs(n - num) < abs(ans - num) )
		{
			ans = n;
		}
		else if(abs(n - num) == abs(ans - num) && n < ans)
		{
			ans = n;
		}
		return;
	}

	backtrack(n * digs[digi], digi);
	backtrack(n, digi + 1);
}

int main()
{
	digs.push_back(2);
	digs.push_back(3);
	digs.push_back(5);
	digs.push_back(7);
	digs.push_back(11);
	digs.push_back(13);
	digs.push_back(17);
	digs.push_back(19);

	cin >> num;
	backtrack(1, 0);
	cout << ans << " ";

	cin >> num;
	backtrack(1, 0);
	cout << ans << endl;
	return 0;
}
