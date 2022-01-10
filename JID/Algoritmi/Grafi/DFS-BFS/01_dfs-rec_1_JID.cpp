/// DFS с рекурсия, списък съседи

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector <int> G[1024];
bool used[1024];

void dfs (int s)
{
    cout << s+1 << " ";
    used[s]=true;

    for (int i=0; i<G[s].size(); i++)
    {
        if ( !used[ G[s][i] ] )
              dfs(G[s][i]);
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, b, e;
    cin >> n >> m >> s;
    for (int i=0; i<m; i++)
    {
        cin >> b >> e;
        G[b-1].push_back(e-1);
        G[e-1].push_back(b-1);
    }
    dfs(s-1);
    return 0;
} //ю

/**
Input:
10 11 5
8 10
1 2
1 8
2 4
2 7
2 10
3 8
4 3
8 3
5 6
8 6

Output:
5 6 8 10 2 1 4 3 7


Input:
10 14 9
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

Output:
9 2 5 1 4 6 3 7 8 10


*/
