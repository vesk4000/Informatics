#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n;
int a[MAXN];

/*
	2^x => 1 << x
	left_child(x) => x * 2 + 1
	right_child(x) => x * 2 + 2
	is_leaf(x) => x < leaf(0)
*/

int tree[MAXN * 4], lazy[MAXN * 4];
int height;

int leaf(int index) {
	return (1 << height - 1) - 1 + index;
}

void build() {
	height = ceil(log2(n)) + 1;
	for(int i = 0; i <= leaf(0); ++i)
		tree[leaf(i)] = i < n ? a[i] : 0;
	for(int node = leaf(-1); node >= 0; --node)
		tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

void print(int* arr) {
	int lvl = 1, lvl_curr = 0;
	for(int i = 0; i < leaf(n); ++i) {
		cout << arr[i] << " ";
		++lvl_curr;
		if(lvl_curr >= lvl) {
			cout << endl;
			lvl *= 2;
			lvl_curr = 0;
		}
	}
	cout << endl;
}

void propagate(int node) {
	tree[node] += lazy[node];
	if(node < leaf(0)) {
		lazy[node * 2 + 1] += lazy[node];
		lazy[node * 2 + 2] += lazy[node];
	}
	lazy[node] = 0;
}

int query(int qleft, int qright, int node = 0, int cleft = 0, int cright = leaf(0)) {
	if(qright < cleft || cright < qleft)
		return 0;
	if(qleft <= cleft && cright <= qright) {
		propagate(node);
		return tree[node];
	}
	return query(qleft, qright, node * 2 + 1, cleft, (cleft + cright) / 2)
			+ query(qleft, qright, node * 2 + 2, (cleft + cright) / 2 + 1, cright);
}

void update(int uleft, int uright, int delta, int node = 0, int cleft = 0, int cright = leaf(0)) {
	if(uright < cleft || cright < uleft)
		return;
	if(uleft <= cleft && cright <= uright) {
		lazy[node] += delta;
		tree[node] += (cright - cleft) * lazy[node];
		propagate(node);
		return;
	}
	update(uleft, uright, delta, node * 2 + 1, cleft, (cleft + cright) / 2);
	update(uleft, uright, delta, node * 2 + 2, (cleft + cright) / 2 + 1, cright);
	tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	build();
	print(tree);
	cout << query(2, 4) << endl;
	update(1, 4, -2);
	print(tree);
	print(lazy);
	cout << query(2, 4) << endl;
	return 0;
}