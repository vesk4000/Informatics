#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int n;
const int MAXNQ = 1e5;
int first_zero_sum[MAXNQ];

int tree[MAXNQ * 4]; 
int tree_height;

int tree_get_leaf_node(int index) {
	return index + (1 << (tree_height - 1)) - 1;
}

void tree_build() {
	tree_height = ceil(log2(n));
	//cout << tree_height << endl;
	for(int i = 0; i < n; ++i) {
		tree[tree_get_leaf_node(i)] = first_zero_sum[i];
	}
	for(int i = n; i < (1 << tree_height); ++i) {
		tree[tree_get_leaf_node(i)] = numeric_limits<int>::max();
	}
	for(int i = tree_get_leaf_node(0) - 1; i >= 0; --i) {
		tree[i] = min(tree[i * 2 + 1], tree[i * 2 + 2]);
	}
}

int tree_query(int node, int node_left, int node_right, int query_left, int query_right) {
	//cout << node << " " << node_left << " " << node_right << endl;  
	// Completely outside
	if(node_left > query_right || node_right < query_left)
		return numeric_limits<int>::max();
	
	//Completely inside
	if(query_left <= node_left && node_right <= query_right)
		return tree[node];
	
	int mid = (node_right + node_left) / 2;
	return min( tree_query(node * 2 + 1, node_left, mid, query_left, query_right), 
			tree_query(node * 2 + 2, mid + 1, node_right, query_left, query_right) );
}

int tree_query(int l, int r) {
	return tree_query(0, 0, (1 << tree_height - 1) - 1, l, r);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> first_zero_sum[i];

	tree_build();
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << tree_query(l, r) << endl;
	}
	
	return 0;
}