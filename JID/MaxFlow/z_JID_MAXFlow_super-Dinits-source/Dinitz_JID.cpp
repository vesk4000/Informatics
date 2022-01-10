/**
18.11.2020 г.
JID:
по теорията от:
https://cp-algorithms.com/graph/dinic.html
и
https://e-maxx.ru/algo/dinic
*/

#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18
#define LL long long
using namespace std;


struct Edge
{
    int from, to;
    LL cap, flow = 0;
    Edge(int v, int u, LL cap) : from(v), to(u), cap(cap) {}
};

vector<Edge> edg;		 	    // списък ребра
vector< vector<int> > outE;     // списък номера на ребра
vector<int> lev;			    // нива на всеки връх
vector<int> ptr;			    // указатели за всеки връх към ребро
queue<int> q;
int n, m = 0;			        // n – брой върхове, m – брой ребра
int s, t;				        // s = source, t = target


void addEdge(int v, int u, LL cap)
{
    edg.emplace_back(v, u, cap);		// право ребро
    outE[v].push_back(edg.size()-1);	// № на ребро от връх v (право ребро)
    edg.emplace_back(u, v, 0);		    // обратно ребро
    outE[u].push_back(edg.size()-1);	// № на ребро от връх u (обратно ребро)
}

void init()
{
    int from, to;
    LL cap;

    cin >> n >> m >> s >> t;

    outE.resize(n);
    lev.resize(n);
    ptr.resize(n);

    for(LL i = 0; i < m; i++)
    {
        cin >> from >> to >> cap;
        addEdge(from, to, cap);
    }
}

void bfs(int s)
{
    lev[s] = 0;					        // ниво 0 за стартовия връх
    q.push(s);					        // вкарваме върха в опашката
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int curr : outE[v]) 		// за всяко ребро, излизащо от връх v
        {
            int residCap = edg[curr].cap - edg[curr].flow;
            if ( residCap >= 1 && lev[edg[curr].to] == -1 ) // ако има остатъчен капацитет и не е достъпван краят му
            {
                lev[ edg[curr].to ] = lev[v]+1;
                q.push( edg[curr].to );
            }
        }
    }
}

LL dfs(int v, LL cap)
{
    if ( !cap ) return 0;
    if (v == t) return cap;

    for ( int &p=ptr[v] ; p < (int)outE[v].size(); p++)
    {
        int curr = outE[v][p];
        int next = edg[curr].to;
        LL residualCap = edg[curr].cap - edg[curr].flow;

        if ( residualCap >= 1 && lev[v]+1 == lev[next] )
        {
            LL minCap = dfs(next, min(cap, residualCap));

            if (minCap == 0) continue;

            edg[curr].flow   += minCap;       // право ребро
            edg[curr^1].flow -= minCap;       // обратно ребро
            return minCap;
        }
    }
    return 0;
}

LL Dinitz()
{
    LL fTotal = 0;				            // започва с поток 0 в мрежата
    while (true)
    {
        fill(lev.begin(),lev.end(),-1);
        bfs(s);					            // пускаме bfs(), за да запълни вектора с нивата на върховете (правим многослойната мрежа)
        if ( lev[t]==-1 ) break;	  	    // ако връх t не е достигнат, значи няма път s->t и край на алгоритъма

        fill(ptr.begin(), ptr.end(), 0);
        while (true)
        {
            LL flow = dfs(s,INF);
            if ( !flow ) break;             // ако няма поток, значи всички ребра са наситени и спираме търсенето
            fTotal += flow;
        }
    }
    return fTotal;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << Dinitz() << endl;

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
