#include <iostream>
#include <string>
using namespace std;
void input();
void gen_commands();
void build_tree(int x);
bool is_leaf(int x);
int get_leaf(int x);
int get_leaf_index(int x);
int get_left_child(int x);
int get_right_child(int x);
void print_tree();
void update_tree(int left, int right);
bool is_left(int x);
bool is_right(int x);
int get(int x);

int n, q;
string cs;
int l;
const int MAXL = 500000;///500 000
int c[MAXL];
int overall_sum = 0;

const int TREE_HEIGHT = 20;
int tree[1 << TREE_HEIGHT];
int lazy[1 << TREE_HEIGHT];

void input() {
	cin >> n >> q;
	cin >> cs;
	gen_commands();
	build_tree(0);
	overall_sum = tree_query(get_leaf(0), get_leaf(l - 1));
	//print_tree();
	for(int i = 0; i < q; ++i) {
		int left, right;
		cin >> left >> right;
		--left;
		--right;
		update_tree(left, right);
		int sum = query_tree(left, right);
		overalls_sum -= sum;

	}
}

void update_tree(int left, int right) {
	left = tree_get_leaf(left);
	right = tree_get_leaf(right);

	while(left + 1 < right) {
		tree[left] = tree[get_left_child(left)] + lazy[get_left_child(left)] + tree[get_right_child(left)] + lazy[get_right_child(left)];
		tree[right] = tree[left] = tree[get_left_child(right)] + lazy[get_left_child(right)] + tree[get_right_child(right)] + lazy[get_right_child(right)];
		if(is_left(left)) {
			lazy[left + 1] = -2(tree[left + 1] + lazy[left + 1]);
		}
		if(is_right(right)) {
			lazy[right + 1] = -2(tree[right - 1] + lazy[right - 1]);
		}

	}
}

int get(int x) {
	tree[x] += lazy[x];
	if(!is_leaf(x)) {

	}
}

void build_tree(int x) {
	if(is_leaf(x)) {
		if(x < MAXL)
			tree[x] = c[get_leaf_index(x)];
		else
			tree[x] = 0;
	}
	else {
		build_tree(get_left_child(x));
		build_tree(get_right_child(x));
		tree[x] = tree[get_left_child(x)] + tree[get_right_child(x)];
	}
}

bool is_leaf(int x) {
	if(x >= get_leaf(0))
		return true;
	return false;
}

int get_leaf(int x) {
	return x + (1 << (TREE_HEIGHT - 1)) - 1;
}

int get_leaf_index(int x) {
	return x - (1 << (TREE_HEIGHT - 1)) + 1;
}

int get_left_child(int x) {
	return x * 2 + 1;
}

int get_right_child(int x) {
	return get_left_child(x) + 1;
}

void print_tree() {
	int lvl = 1;
	int lvl_curr = 0;
	for(int i = 0; i <= 1 << TREE_HEIGHT; ++i) {
		cout << tree[i] << " ";
		lvl_curr++;
		if(lvl_curr >= lvl) {
			lvl_curr = 0;
			cout << endl;
			lvl *= 2;
		}
	}
}

bool is_left(int x) {
	return x % 2 == 1;
}

bool is_right(int x) {
	return !is_left(x);
}

void gen_commands() {
	l = cs.size();
	for(int i = l - 1; i >= 0; --i) {
		if(cs[i] == '+') {
			c[i] = 1;
		}
		if(cs[i] == '-') {
			c[i] = -1;
		}
		if(cs[i] == 'o') {
			c[i] = 0;
			c[i - 1] = 0;
			--i;
		}
	}
	/*for(int i = 0; i < l; ++i)
		cout << c[i] << " ";
	cout << endl;*/
}

int main() {
	input();
	return 0;
}
