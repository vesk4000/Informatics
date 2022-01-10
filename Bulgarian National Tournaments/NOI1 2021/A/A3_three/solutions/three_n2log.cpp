#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef long long llong;

int n;
vector<int> Graph[100111];

set<int> common;

int main()
{
    int i, j, in;
    llong ans = 0;

    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i = 1; i <= n; i++)
    {
        common.clear();

        for (int j = 0; j < Graph[i].size(); j++)
        {
            common.insert(Graph[i][j]);
        }

        for (j = i + 1; j <= n; j++)
        {
            if (common.find(j) != common.end())
                continue;

            ans += n - common.size() - 2;

            for (in = 0; in < Graph[j].size(); in++)
            {
                if (common.find(Graph[j][in]) == common.end())
                    ans--;
            }
        }
    }

    printf("%lld\n", ans / 3LL);

    return 0;
}
