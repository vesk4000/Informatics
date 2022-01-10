#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

#define endl '\n'
#define pb push_back
#define fr first
#define sc second
#define ll long long int
#define ld long double
#define bit(idx) idx&(-idx)
#define bin(x) bitset<32>(x)
#define all(A) A.begin(), A.end()
#define de(x) cout << #x << " = " << x << endl;
#define row vector<ll>
#define row_matrix vector<ll>
#define matrix vector<row_matrix>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/// find_by_order(x) -> x-th element in the set
/// order_of_key(x)  -> how many elements are smaller than x
/// insert(x) -> inserts x into the set

struct Edge{
	ll v = 0, cap = 0, flow = 0;
	Edge() {}
	Edge(ll _v, ll _cap){
		v = _v; cap = _cap;
	}
	ll remCap(){
		return cap - flow;
	}
};

const ll INF = 1e9 + 9;

matrix G;
row skip, level;
vector<Edge> edges;
ll n, s, t;

void add_edge(ll u, ll v, ll cap){
	edges.pb(Edge(v, cap));
	edges.pb(Edge(u, 0));
	G[u].pb(edges.size() - 2);
	G[v].pb(edges.size() - 1);
	/// cout << "added edge " << u << " -> " << v << " with cap = " << cap << endl;
}

bool bfs(){
	level = row(n + 1, -1);
	queue<ll> q;
	q.push(s);
	level[s] = 0;
	while(!q.empty()){
		auto u = q.front(); q.pop();
		for(auto i : G[u]){
			ll v = edges[i].v;
			if(level[v] == -1 && edges[i].remCap() > 0){
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	/// for(int i = 0; i < n; i ++) cout << i << "(" << level[i] << ") "; cout << endl;
	return level[t] != -1;
}

ll dfs(ll u, ll cap){
	/// cout << u << " " << cap << endl;
	if(u == t){
		return cap;
	}
	else{
		for(; skip[u] < G[u].size(); skip[u] ++){
			ll i = G[u][skip[u]];
			ll v = edges[i].v, remCap = edges[i].remCap();
			
			if(remCap > 0 && level[u] + 1 == level[v]){
				ll bottle = dfs(v, min(cap, remCap));
				if(bottle > 0){
					/// cout << i << ": " << u << " -> " << v << " = " << remCap << "; " << edges[i].flow << ", " << edges[i].cap << endl;
					edges[i ^ 0].flow += bottle;
					edges[i ^ 1].flow -= bottle;
					return bottle;
				}
			}
		}
		return 0;
	}
}

ll solve(){
	ll ans = 0;
	while(bfs()){
		skip = row(n + 1, 0);
		for(ll curr = dfs(s, INF); curr != 0; curr = dfs(s, INF)){
			/// de(curr);
			ans += curr;
		}
	}
	return ans;
}

int main(){
	/// ios_base::sync_with_stdio(false); cin.tie(NULL);
	n = 6, s = 0, t = 5;
	G = matrix(n + 1);

	add_edge(0, 1, 16);
	add_edge(0, 2, 13);
	
	add_edge(1, 2, 10);
	add_edge(1, 3, 12);

	add_edge(2, 1, 4);
	add_edge(2, 4, 14);
	
	add_edge(3, 2, 9);
	add_edge(3, 5, 20);
	
	add_edge(4, 3, 7);
	add_edge(4, 5, 4);
	cout << solve() << endl;
}
/**

*/
