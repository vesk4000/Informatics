#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

int n;
vector<int> Graph[100111];

int marks[100111];
int unmarked;

void addMark(int ver)
{
    if (marks[ver] == 0)
        unmarked--;
    marks[ver]++;
}

void removeMark(int ver)
{
    marks[ver]--;
    if (marks[ver] == 0)
        unmarked++;
}

void addAllMarks(int ver)
{
    int i;

    addMark(ver);
    for (i = 0; i < Graph[ver].size(); i++)
    {
        addMark(Graph[ver][i]);
    }
}

void removeAllMarks(int ver)
{
    int i;

    removeMark(ver);
    for (i = 0; i < Graph[ver].size(); i++)
    {
        removeMark(Graph[ver][i]);
    }
}

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
    unmarked = n;

    for (i = 1; i <= n; i++)
    {
        addAllMarks(i);

        for (j = i + 1; j <= n; j++)
        {
            if (marks[j] > 0)
                continue;

            addAllMarks(j);

            ans += (llong)unmarked;

            removeAllMarks(j);
        }

        removeAllMarks(i);
    }

    printf("%lld\n", ans / 3LL);

    return 0;
}
