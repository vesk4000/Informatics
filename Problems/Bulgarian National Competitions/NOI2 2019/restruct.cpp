#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void BFS();
int getAnswer(int x);

int n, k;
const int MAXN = 5024;

vector<int> nb[MAXN];
vector<int> ch[MAXN];

void BFS() {
	int ans = 1000000;
	for(int i = 1; i <= n; ++i) {
		//cout << i << endl;
		for(int j = 1;j <= n; ++j) {
			ch[j].clear();
		}
		queue<int> q;
		q.push(i);
		bool used[MAXN] = {false};
		used[i] = true;
		while(!q.empty()) {
			int c = q.front();
			//cout << c << endl;
			//used[c] = true;
			for(int j = 0; j < nb[c].size(); ++j) {
				int cc = nb[c][j];
				if(!used[cc]) {
					used[cc] = true;
					q.push(cc);
					ch[c].push_back(cc);
				}
			}
			q.pop();
		}
		int curr_ans = 0;
		for(int j = 1; j <= n; ++j) {
			//cout << j << " - " << getAnswer(j) << endl;
			curr_ans += getAnswer(j);
			//cout << curr_ans << endl;
		}
		ans = min(ans, curr_ans);
		//cout << endl;
	}
	cout << ans  * k << endl;
}

int getAnswer(int x) {
	int sum = 1;
	for(int i = 0; i < ch[x].size(); ++i) {
		sum += getAnswer(ch[x][i]);
	}
	//cout << x << " - " << sum << endl;
	return sum;

}

int main() {
	input();
	BFS();
	return 0;
}

void input() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		int n2;
		cin >> n2;
		for(int j = 0; j < n2; ++j) {
			int to;
			cin >> to;
			nb[to].push_back(i);
		}
	}
}
