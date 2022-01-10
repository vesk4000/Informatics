#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

vector<int> G[MAXN];
bool used[MAXN];
bool cycled=false;

void dfs(int s, int prev)
{
    if ( cycled ) return;
    used[s]=true;
    for (int i=0; i<G[s].size(); i++)
    {
        if ( !used[G[s][i]] ) dfs( G[s][i], s);
        else if ( G[s][i] != prev )
        {
            cout << "YES" << endl;
            cycled=true;
            exit(0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, b, e;

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> b >> e;
        G[b-1].push_back(e-1);
        G[e-1].push_back(b-1);
    }
    dfs(0, -1);
    cout << "NO" << endl;
}

/**
Input:
10 14
1 4
1 5
2 5
2 6
2 9
2 10
3 5
3 7
3 9
4 5
4 6
5 9
7 8
8 9

Out:
YES

================

1------2 ----3-----4-----6
|      |     |
|      |     |
5      8     7
Input:
8 7
1 2
1 5
2 3
2 8
3 4
3 7
4 6
Out:
NO

*/
