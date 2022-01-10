#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector <int> G[1024];
queue <int> q;
bool used[1024];

void bfs(int s)
{
    cout << s+1 << " ";
    q.push(s);
    used[s]=true;                   /// !!!

    while(!q.empty())
    {
        s=q.front();
        for (int i=0; i<G[s].size(); i++)
        {
            if ( !used[G[s][i]] )
            {
                cout << G[s][i]+1 << " ";
                q.push( G[s][i] );
                used[ G[s][i] ]=true;
            }
        }
        q.pop();
    }
    cout << endl;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, b, e;
    cin >> n >> m >> s; /// scanf("%d%d%d",&n,&m,&s);
    for (int i=0; i<m; i++)
    {
        cin >> b >> e; /// scanf("%d%d",&b,&e);
        G[b-1].push_back(e-1);
        G[e-1].push_back(b-1);
    }
    bfs(s-1);
    return 0;
} //þ
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
5 6 8 10 1 3 2 4 7

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
9 2 3 5 8 6 10 7 1 4

*/
