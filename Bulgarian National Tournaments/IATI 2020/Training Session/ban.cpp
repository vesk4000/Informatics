#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
const int MAXN = 1000;
vector<int> nbs[MAXN];
bool used[MAXN];
int tin[MAXN];
int low[MAXN];
int step;
int ans;

void dfs(int node, int p = -1) {
	used[node] = true;
	tin[node] = low[node] = step++;
	for (int i = 0; i < nbs[node].size(); ++i) {
		int nb = nbs[node][i];
		if(nb == p)
			continue;
		if(used[nb]) {
			low[node] = min(low[node], tin[nb]);
		}
		else {
			dfs(nb, node);
			low[node] = min(low[node], low[nb]);
			if(low[nb] > tin[node]) {
				++ans;
				//cout << nb + 1 << " " << node + 1 << endl;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int n1, n2;
		cin >> n1 >> n2;
		--n1;
		--n2;
		nbs[n1].push_back(n2);
		nbs[n2].push_back(n1);
	}
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));

	/*for(int i = 0; i < n; ++i) 
		cout << tin[i] << " " << low[i] << endl;*/

	for(int i = 0; i < n; ++i) 
		if(!used[i])
			dfs(i);

	cout << ans << endl;

	return 0;
}