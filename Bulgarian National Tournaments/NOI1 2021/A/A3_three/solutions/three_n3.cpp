#include <iostream>
#include <stdio.h>
using namespace std;

int n;
bool edge[5111][5111];

int main()
{
    int i, j, in;
    long long ans = 0;

    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        edge[a][b] = true;
        edge[b][a] = true;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            for (in = j + 1; in <= n; in++)
            {
                if (!edge[i][j] && !edge[i][in] && !edge[j][in])
                    ans++;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
