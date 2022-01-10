#include <bits/stdc++.h>
#define endl '\n'
#define LLint long long
#define pb push_back
#define mp make_pair
using namespace std;

const LLint maxN = 505, INF = 1e9 + 5;

struct edge
{
    LLint to, cap, flow, rev;

    edge() {}
    edge(LLint to, LLint cap, LLint flow, LLint rev)
    {
        this->to = to;
        this->cap = cap;
        this->flow = flow;
        this->rev = rev;
    }
};

LLint n, m, dep[maxN], curr_node, curr_dep, next_node, ind;
LLint ans;
queue<LLint> q;
vector<edge> g[maxN];

void bfs()
{
    dep[n] = 0;
    q.push(n);
    while(!q.empty())
    {
        curr_node = q.front();
        curr_dep = dep[curr_node];
        q.pop();

        for(LLint i = 0; i < g[curr_node].size(); i++)
        {
            next_node = g[curr_node][i].to;
            ind = g[curr_node][i].rev;

            if(g[next_node][ind].cap > g[next_node][ind].flow && dep[next_node] == -1)
            {
                q.push(next_node);
                dep[next_node] = curr_dep + 1;
            }
        }
    }
}
LLint dfs(LLint node, LLint min_free)
{
    if(node == n)
    {
        ans += (LLint)min_free;
        return min_free;
    }

    LLint curr_min;
    for(LLint i = 0; i < g[node].size(); i++)
    {
        if(dep[g[node][i].to] != dep[node] - 1 || g[node][i].cap == g[node][i].flow) continue;

        curr_min = dfs(g[node][i].to, min(min_free, g[node][i].cap - g[node][i].flow));

        if(curr_min > 0)
        {
            g[node][i].flow += curr_min;
            g[g[node][i].to][g[node][i].rev].flow -= curr_min;

            return curr_min;
        }
    }

    return 0;
}

LLint main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLint u, v, cap, ind_rev;

    cin>>n>>m;
    for(LLint i = 0; i < m; i++)
    {
        cin>>u>>v>>cap;
        ind_rev = g[v].size();

        g[u].pb(edge(v, cap, 0, ind_rev));
        g[v].pb(edge(u, 0, 0, g[u].size() - 1));
    }

    LLint last_ans;
    while(1)
    {
        memset(dep, -1, sizeof(dep));
        bfs();
        if(dep[1] == -1)break;

        while(1)
        {
            last_ans = ans;
            dfs(1, INF);
            if(last_ans == ans)break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
