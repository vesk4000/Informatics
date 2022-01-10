#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

int n;
vector<int> Graph[100111];

int fathers(int ver)
{
    return ver == 1 ? 0 : 1;
}

int children(int ver)
{
    return Graph[ver].size() - fathers(ver);
}

llong ans = 0;
void DFS(int ver, int dad)
{
    int i;
    llong childCnt = children(ver);

    ans -= childCnt * (childCnt - 1) / 2;

    for (i = 0; i < Graph[ver].size(); i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        ans -= children(Graph[ver][i]);

        ans -= (n - fathers(ver) - children(ver) - 1 - children(Graph[ver][i]));

        DFS(Graph[ver][i], ver);
    }
}

int main()
{
    int i, j, in;

    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    ans = (llong)n * (llong)(n - 1) * (llong)(n - 2) / 6LL;

    DFS(1, 0);

    printf("%lld\n", ans);

    return 0;
}
