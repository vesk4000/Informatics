#include<iostream>
#include<algorithm>
using namespace std;
int items[51][2];
int capacity = 0, n = 0;
int matrix[51][25001];
int main()
{
	cin >> capacity;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i][0];
		cin >> items[i][1];

	}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0;j < capacity + 1; j++)
		{
			if (i == 0) matrix[i][j] = 0;
			else
			{
				int excluding = 3123132;
				int including = 12122121;
				int current = 0;
				if (j - items[i - 1][1] >= 0) {
					current = matrix[i - 1][j - items[i - 1][1]];

					excluding = matrix[i - 1][j];
					including = items[i - 1][0] + current;
					matrix[i][j] = max(excluding, including);
				}
				else matrix[i][j] = 0;
			}
		}
	}

	cout << matrix[n][capacity] << endl;
    return 0;
}
