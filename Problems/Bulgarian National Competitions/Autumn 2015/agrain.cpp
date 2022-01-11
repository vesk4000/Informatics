#include <iostream>

using namespace std;

int n, d, l;
int x, a, b;

int nArr[10000000];///10 000 000

void input();
int binarySearch(int index);

int main()
{
	input();
	binarySearch();
	return 0;
}

void input()
{
	cin >> n >> d >> l;
	cin >> x >> a >> b;
	nArr[0] = x;
	for(int i = 1; i < n; ++i)
	{
		nArr[i] = ((nArr[i - 1] * a) + b) % (l + 1);
	}
	cout << binarySearch(n / 2) << endl;
}

void binarySearch(int index)
{
	bool workArr[1000000000] = {0};///1 000 000 000
	currentLength = 0;
	for(int i = 0; i < index; ++i)
	{
		if(nArr[i] == 1)
			workArr
	}
}
