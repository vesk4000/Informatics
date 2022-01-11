#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int parent[10001];
long long sum = 0;

struct st
{
    int a, b;
    long long d;
};

st node[100000];

bool cmp(st p, st q)
{
    if (p.d < q.d) return 1;
    return 0;
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void input()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> node[i].a >> node[i].b >> node[i].d;
        sum += node[i].d;
    }

    sort (node, node + m, cmp);


    int rem = n - 1;
    for (int i = 0; i < m; i++)
    {
        if (!rem) break;
        int aRoot = find (node[i].a);
        int bRoot = find (node[i].b);
        if (aRoot != bRoot)
        {
            parent[aRoot] = find(bRoot);
            sum -= node[i].d;
            rem--;
        }
    }

    if (rem) cout << -1 << endl;
    else cout << sum << endl;

}

int main()
{
    input();

    return 0;

}
