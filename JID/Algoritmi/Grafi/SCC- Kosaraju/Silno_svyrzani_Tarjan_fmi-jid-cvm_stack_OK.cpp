#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int n;
vector< vector<int> > G;
vector< vector<int> > tG;

struct Node
{
    int v;
    int t;
    Node() {}
    Node (int _v, int _t)
    {
        v=_v;
        t=_t;
    }
};

stack<Node> discov;
vector<bool> used;
int time;

void dfs1(int u)
{
    used[u] = true;
    time++;

    for (size_t v=0; v < G[u].size(); v++)
    {
        if ( !used[G[u][v]] )
            dfs1(G[u][v]);
    }
    discov.push(Node(u,++time));
}

void dfs2(int u)
{
    used[u] = true;
    cout << u << " ";
    for (size_t v=0; v < tG[u].size(); v++)
    {
        if ( !used[tG[u][v]] )
            dfs2(tG[u][v]);
    }
}

void inputG()
{
    int m, b, e;
    cin >> n >> m;
    G.resize(n);
    tG.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> b >> e;
        G[b].push_back(e);
        tG[e].push_back(b);             // транспонирания граф
    }
}

int main()
{
    inputG();

    time = 0;

    used.resize(n,false);                     /// подготвя used за dfs-a в графа G
    for (int i = 0; i < n; i++)               ///  пуска dfs От всеки непосетен връх на графа G
    {
        if (!used[i])
            dfs1(i);
    }



    used.assign(n,false);                     /// подготвя used за dfs-a в транспонирания граф
    for (int i = 0; i < n; i++)               ///  пуска dfs oт всеки непосетен връх на графа GT
    {
        if (!used[discov.top().v])
        {
            dfs2(discov.top().v);
            cout << endl;
        }
        discov.pop();
    }

    return 0;
}
/**
Input:
8 13
0 4
1 0
2 1
2 3
3 2
4 1
5 1
5 4
5 6
6 2
6 5
7 3
7 6
Output:
7
5 6
2 3
0 1 4

*/
