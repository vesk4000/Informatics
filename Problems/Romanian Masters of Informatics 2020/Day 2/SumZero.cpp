#include <iostream>
#include <limits>
#include <vector>
#include <cstring>
#include <map>
#include <math.h>
using namespace std;

int n;
int q;
const int MAXNQ = 1e5;
int c[MAXNQ];
int first_zero_sum[MAXNQ];// The index of the first element that c[i] forms a zero sum with

int tree[MAXNQ * 4]; 
int tree_height;

int tree_get_leaf_node(int index) {
	return index + (1 << (tree_height - 1)) - 1;
}

void tree_build() {
	tree_height = ceil(log2(n)) + 1;
	//cout << tree_height << endl;
	for(int i = 0; i < n; ++i) {
		if(first_zero_sum[i] != -1)
			tree[tree_get_leaf_node(i)] = first_zero_sum[i];
		else
			tree[tree_get_leaf_node(i)] = numeric_limits<int>::max();
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> c[i];

	memset(first_zero_sum, -1, sizeof(first_zero_sum));

	for(int i = 0; i < n; ++i) {
		long long int sum = 0;
		for(int j = i; j < n; ++j) {
			sum += c[j];
			if(sum == 0) {
				first_zero_sum[i] = j;
				break;
			}
		}
	}
	//cout << log2(n) << endl;
	tree_build();

	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;

		int ans = 0;
		while(true) {
			//cout << l << " " << r << endl;

			if(l > r) // If we have gone past the end of the query range
				break;

			if(l == r) { // If we are at the last element
				if(first_zero_sum[l] == l)
					++ans;
				break;
			}

			if(first_zero_sum[l] == -1) {
				++l;
				continue;
			}

			if(first_zero_sum[l] == l) { // Basically if c[l] = 0
				++ans;
				++l;
				continue;
			}

			if(first_zero_sum[l] > r) {
				++l;
				continue;
			}

			/*int mn = first_zero_sum[l];
			for(int j = l + 1; j <= first_zero_sum[l]; ++j) {
				if(first_zero_sum[j] != -1 && first_zero_sum[j] < mn) {
					mn = first_zero_sum[j];
				}
			}*/
			//cout << l << " " << first_zero_sum[l] << endl;

			int mn = tree_query(l, first_zero_sum[l]);
			++ans;
			l = mn + 1;
		}

		cout << ans << endl;
	}

	return 0;
}