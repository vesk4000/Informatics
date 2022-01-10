/**
по теорията от
https://cp-algorithms.com/graph/dinic.html
и
https://e-maxx.ru/algo/dinic

*/
#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
using namespace std;

struct Edge /// за всяко ребро помни 2-та си върха, капацитета си и потока през него
{
    LL from, to, cap, flow = 0;
    Edge(int from, int to, LL cap) : from(from), to(to), cap(cap) {}
};

struct Dinic
{
    const LL INF = 1e18;
    vector<Edge> edg;		        /// списък ребра на G
    vector<vector<int> >  adj;      /// списък с номерата на ребрата
    int n, m = 0;			        /// n – брой върхове, m – брой ребра
    int s, t;
    vector<int> lev;
    vector<int> ptr;
    queue<int> q;

    Dinic() {}

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n);
        lev.resize(n);
        ptr.resize(n);
    }

    void addEdg(int from, int to, LL cap)
    {
        edg.emplace_back(from, to, cap);	/// право ребро
        edg.emplace_back(to, from, 0);		/// обратно ребро
        adj[from].emplace_back(m); 		/// право ребро (от връх v) - с № m
        adj[to].emplace_back(m+1);		/// обратно ребро (от връх u) - с № m+1
        m += 2;
    }

    bool bfs()                          /// изгражда многослойната мрежа
    {
        fill(lev.begin(), lev.end(), -1);
        lev[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i : adj[v])
            {
                if (edg[i].cap - edg[i].flow < 1) continue;

                if (lev[edg[i].to] != -1) continue;

                lev[edg[i].to] = lev[v] + 1;
                q.push(edg[i].to);
            }
        }
        return lev[t] != -1;
    }

    LL dfs(int from, LL addFlow)
    {
        if ( !addFlow ) return 0;
        if (from == t) return addFlow;

        for (size_t pi = ptr[from]; pi < adj[from].size(); pi++)
        {
            int p = adj[from][pi];            /// индекс на ребро, според поинтера на връх from
            int to = edg[p].to;               /// следващ връх от графа

            if ( lev[from]+1 != lev[to] ) continue;
            if ( edg[p].cap - edg[p].flow < 1 ) continue;

            LL minF = dfs(to, min(addFlow, edg[p].cap - edg[p].flow));
            if (minF == 0) continue;

            edg[p].flow += minF;
            edg[p^1].flow -= minF;          /// (четно^1)=четно+1,(неч^1)=неч-1
            return minF;
        }
        return 0;
    }

    LL flow()
    {
        LL f = 0;
        while ( bfs() )
        {
            fill(ptr.begin(), ptr.end(), 0);
            while ( LL addFlow = dfs(s, INF) )   /// докато намира блокиращ поток
            {
                f += addFlow;
            }
        }
        return f;
    }
};


int main()
{
  /*
    for (int i=0; i<=10; i++)
    {
        cout << i << " " << (i^1) << endl;
    }
    */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);


    int n, m, s, t, from, to;
    LL cap;

    cin >> n >> m >> s >> t;

    Dinic G(n,s,t);

    for(LL i = 0; i < m; i++)
    {
        cin >> from >> to >> cap;
        G.addEdg(from, to, cap);
    }

    cout << G.flow() << endl;
    return 0;
}

/**
Input:
6 9 2 5
0 1 16
0 3 13
3 1 4
1 2 12
2 3 9
3 4 14
4 2 7
2 5 20
4 5 4
Output:
24


Input:
6 7 1 4
0 1 2
0 2 2
1 3 7
1 4 8
2 3 5
3 5 1
4 5 2
Output:
8


Input:
6 9 0 5
0 1 10
0 2 10
1 2 5
1 3 1
1 4 3
2 4 12
3 4 15
3 5 10
4 5 10

Output:
11

*/
/**


*/
