#include <iostream>

using namespace std;

int tree_query(int left_index, int right_index);
void tree_update(int index, int value);
int tree_get_leaf(int x);
bool is_left_child(int x);
bool is_right_child(int x);
int tree_get_parent(int x);
int tree_get_left_child(int x);
int tree_get_right_child(int x);
void tree_print();

int n;
const int MAXN = 100000;///100 000
int a[MAXN];
const int MAXA = 100000;///100 000

int dp[MAXN];

const int TREE_HEIGHT = 20;
int tree[2][1 << TREE_HEIGHT];
int ct = 0;///current tree

void tree_update(int index, int value) {
	tree[ct][index] = value;
	index = tree_get_parent(index);
	while(index >= 0) {
		//cout << index << endl;
		tree[ct][index] = max(tree[ct][tree_get_left_child(index)], tree[ct][tree_get_right_child(index)]);
		index = tree_get_parent(index);
	}
}

int tree_query(int left_index, int right_index) {
	left_index = tree_get_leaf(left_index);
	right_index = tree_get_leaf(right_index);
	//cout << left_index << " " << right_index << endl;
	int ans = max(tree[ct][left_index], tree[ct][right_index]);
	//cout << ans << endl;
	while(left_index + 1 < right_index) {
		//cout << left_index << " " << right_index << endl;
		if(is_left_child(left_index)) {
			ans = max(ans, tree[ct][left_index + 1]);
		}
		if(is_right_child(right_index)) {
			ans = max(ans, tree[ct][right_index - 1]);
		}
		left_index = tree_get_parent(left_index);
		right_index = tree_get_parent(right_index);
		//cout << ans << endl;
	}
	return ans;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	///Ascending
	for(int i = 0; i < n; ++i) {
		dp[i] = tree_query(0, a[i] - 1) + 1;
		tree_update(tree_get_leaf(a[i]), dp[i]);
		//cout << i << " - " << dp[i] << endl;
		/*for(int j = 0; j < 10; ++j) {
			cout << tree[ct][tree_get_leaf(j)] << " ";
		}
		cout << endl;*/
		//tree_print();
	}
	///Backwards Ascending
	ct = 1;
	for(int i = n - 1; i >= 0; --i) {
		int tc = tree_query(0, a[i] - 1) + 1;
		tree_update(tree_get_leaf(a[i]), tc);
		dp[i] += tc - 1;
		//cout << i << " - " << dp[i] << endl;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}

void tree_print() {
	int index = 0;
	int lvl = 0;
	int mx_lvl = 1;
	while(index < (1 << TREE_HEIGHT)) {
		cout << tree[ct][index] << " ";
		lvl++;
		if(lvl >= mx_lvl) {
			lvl = 0;
			mx_lvl *= 2;
			cout << endl;
		}
		index++;
	}
}

int tree_get_left_child(int x) {
	return x * 2 + 1;
}
int tree_get_right_child(int x) {
	return tree_get_left_child(x) + 1;
}

int tree_get_parent(int x) {
	if(is_left_child (x)) {
		x += 1;
	}
	x /= 2;
	x--;
	return x;
}

bool is_left_child(int x) {
	return x % 2 == 1;
}

bool is_right_child(int x) {
	return !is_left_child(x);
}

int tree_get_leaf(int x) {
	return x + (1 << (TREE_HEIGHT - 1)) - 1;
}
