#include <iostream>
#include <math.h>
using namespace std;

int pow2(int x);
//void tree_update(int left, int right, int value);
void tree_update(int node, int value);
void tree_update(int update_left, int update_right, int value);
void tree_update(int node, int node_range_left, int node_range_right, int update_left, int update_right, int value);
bool tree_is_node_leaf(int index);
//int tree_query(int left, int right);
int tree_query(int leaf);
int tree_query(int query_left, int query_right);
int tree_query(int node, int node_range_left, int node_range_right, int query_left, int query_right);
void tree_build();
int tree_get_leaf(int x);
int tree_get_left_child(int x);
int tree_get_right_child(int x);
int tree_get_parent(int x);
void tree_print();
bool is_left(int x);
bool is_right(int x);
void tree_update(int index, int value);
void tree_propagate_children(int node);
void tree_propagate_children(int node, int value);
void lazy_print();


int n;
const int MAXN = 1e5;/// 100 000
int a[MAXN];
const int MAXA = 1e5;/// 100 000

const int TREE_MAX = ceil(log2(MAXA));
int tree[1 << TREE_MAX];
int lazy[1 << TREE_MAX];
int tree_height;


void tree_build() {
	tree_height = ceil(log2(n)) + 1;
	for(int i = 0; i < n; ++i) {
		tree[tree_get_leaf(i)] = a[i];
	}
	for(int i = tree_get_leaf(0) - 1; i >= 0; --i) {
		tree[i] = max(tree[tree_get_left_child(i)], tree[tree_get_right_child(i)]);
	}
	tree_print();
}


void tree_update(int node, int value) {
	tree_update(node, node, value);
}


void tree_update(int update_left, int update_right, int value) {
	tree_update(0, 0, n - 1, update_left, update_right, value);
}


void tree_update(int node, int node_range_left, int node_range_right, int update_left, int update_right, int value) {
	cout << node << " " << node_range_left << " " << node_range_right << endl;

	/// Update the node if it has any pending updates
	if(lazy[node] != 0) {
		tree[node] += lazy[node];
		tree_propagate_children(node);
		lazy[node] = 0;
	}
	
	/// If the range of the current node does not overlap with the update range
	if(node_range_left > update_right || node_range_right < update_left)
		return;
	
	/// If the range of the current node lies completely within the update range
	if(update_left <= node_range_left && node_range_right <= update_right) {
		tree[node] += value;
		tree_propagate_children(node, value);
		return;
	}

	/// Else the range of the current node partially overlaps with the update range
	int mid = (node_range_left + node_range_right) / 2;
	//cout << mid << endl;
	tree_update(tree_get_left_child(node), node_range_left, mid, update_left, update_right, value);
	tree_update(tree_get_right_child(node), mid + 1, node_range_right, update_left, update_right, value);

	tree[node] = max(tree[tree_get_left_child(node)], tree[tree_get_right_child(node)]);
}


int tree_query(int leaf) {
	return tree_query(leaf, leaf);
}

int tree_query(int query_left, int query_right) {
	return tree_query(0, 0, n - 1, query_left, query_right);
}

int tree_query(int node, int node_range_left, int node_range_right, int query_left, int query_right) {
	cout << node << " " << node_range_left << " " << node_range_right << endl;

	/// Update the node if it has any pending updates
	if(lazy[node] != 0) {
		tree[node] += lazy[node];
		tree_propagate_children(node);
		lazy[node] = 0;
	}

	/// If the range of the current node does not overlap with the query range
	if(node_range_left > query_right || node_range_right < query_left)
		return 0;

	/// If the range of the current node lies completely within the query range
	if(query_left <= node_range_left && node_range_right <= query_right)
		return tree[node];

	/// Else the range of the current node partially overlaps with the update range
	int mid = (node_range_left + node_range_right) / 2;
	return max( tree_query(tree_get_left_child(node), 0, mid, query_left, query_right),
				tree_query(tree_get_right_child(node), mid + 1, node_range_right, query_left, query_right) );
}


void tree_propagate_children(int node, int value) {
	if(!tree_is_node_leaf(node)) {
		lazy[tree_get_left_child(node)] += value;
		lazy[tree_get_right_child(node)] += value;
	}
}


void tree_propagate_children(int node) {
	tree_propagate_children(node, lazy[node]);
}


bool tree_is_node_leaf(int index) {
	return index >= tree_get_leaf(0) && index <= tree_get_leaf(n - 1);
}


void tree_print() {
	//cout << "height = " << tree_height << endl; 


	int lvl = 1;
	int lvl_curr = 0;
	for(int i = 0; i <= tree_get_leaf(n - 1); ++i) {
		cout << tree[i] << " ";
		lvl_curr++;
		if(lvl_curr >= lvl) {
			lvl_curr = 0;
			cout << endl;
			lvl *= 2;
		}
	}
	cout << endl;
	lazy_print();
}

void lazy_print() {
	//cout << "height = " << tree_height << endl; 
	int lvl = 1;
	int lvl_curr = 0;
	for(int i = 0; i <= tree_get_leaf(n - 1); ++i) {
		cout << lazy[i] << " ";
		lvl_curr++;
		if(lvl_curr >= lvl) {
			lvl_curr = 0;
			cout << endl;
			lvl *= 2;
		}
	}
	cout << endl;
}

int tree_get_leaf(int x) {
	return x + pow2(tree_height - 1) - 1;
}

int tree_get_left_child(int x) {
	return x * 2 + 1;
}

int tree_get_right_child(int x) {
	return tree_get_left_child(x) + 1;
}

int pow2(int x) {
	return 1 << x;
}

int tree_get_parent(int x) {
	if(is_left(x)) {
		x += 1;
	}
	x /= 2;
	x--;
	return x;
}

bool is_left(int x) {
	return x % 2 == 1;
}

bool is_right(int x) {
	return !is_left(x);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	tree_build();

	string type = "";
	int arg1, arg2, arg3;
	while(cin >> type) {
		if(type == "u" || type == "update") {
			cin >> arg1 >> arg2 >> arg3;
			tree_update(arg1, arg2, arg3);
		}
		if(type == "q" || type == "query") {
			cin >> arg1 >> arg2;
			cout << tree_query(arg1, arg2) << endl;
		}
		if(type == "p" || type == "print") {
			tree_print();
		}
		if(type == "e" || type == "exit") {
			break;
		}
	}
	return 0;
}
