#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int n;
const int MAXN = 1e5;
unordered_set<int> true_nbs[MAXN];
unordered_set<int> nbs[MAXN];
bool used_global[MAXN];
bool used[MAXN];

int bfs(int s) {
    for(int i = 0; i < n; ++i) {
        used[i] = false;
    }
    int ans = 0;
    for(int nb : nbs[s]) {
        if(!used[nb] && !used_global[nb]) {
            for(int nbnb : nbs[nb]) {
                if(!used[nbnb] && !used_global[nbnb]) {
                    if(nbs[nbnb].find(s) != nbs[nbnb].end()) {
                        ++ans;
                    }
                }
            }
        }
        used[nb] = true;
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        true_nbs[from].insert(to);
        true_nbs[to].insert(from);
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(true_nbs[i].find(j) == true_nbs[i].end() && i != j)
                nbs[i].insert(j);

    /*for(int i = 0; i < n; ++i) {
        cout << i << " ";
        for(int j : nbs[i]) {
            cout << j << " ";
        }
        cout << endl;
    }*/

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        ans += bfs(i);
        used_global[i] = true;
    }
    cout << ans << endl;

    return 0;
}
