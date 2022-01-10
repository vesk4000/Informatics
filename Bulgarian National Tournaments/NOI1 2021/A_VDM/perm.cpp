#include <iostream>
using namespace std;

int n;
long long int m;
const int MAXN = 30001;
int p[MAXN];

int cycle[MAXN];
int curr_cycle = 1;
int cycle_counts[MAXN];

int ans[MAXN];

void perm(int v, int rm) {
    int pos = v;
    for(int i = 0; i < rm; ++i) {
        pos = p[pos];
    }
    ans[v] = pos;
}

void dfs(int v) {
    ++cycle_counts[cycle[v]];
    if(cycle[p[v]] != 0)
        return;
    cycle[p[v]] = cycle[v];
    dfs(p[v]);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    for(int i = 0; i < n; ++i) {
        if(cycle[i] == 0) {
            cycle[i] = curr_cycle;
            dfs(i);
            ++curr_cycle;
        }
    }

    /*for(int i = 0; i < n; ++i) {
        cout << i << " " << cycle[i] << " " << cycle_counts[cycle[i]] << endl;
    }*/

    for(int i = 0; i < n; ++i) {
        int real = m % cycle_counts[cycle[i]];
        perm(i, real);
    }

    for(int i = 0; i < n - 1; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << ans[n - 1] + 1 << endl;

    return 0;
}
