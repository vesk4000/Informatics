#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


class lazy_segment_tree_max {
	private:
		int *tree;
		int *lazy;
		int height;

		void update(int node, int node_range_left, int node_range_right, int update_left, int update_right, int value) {
			/// Update the node if it has any pending updates
			if(lazy[node] != 0) {
				tree[node] += lazy[node];
				propagate_children(node);
				lazy[node] = 0;
			}

			/// If the range of the current node does not overlap with the update range
			if(node_range_left > update_right || node_range_right < update_left)
				return;
			
			/// If the range of the current node lies completely within the update range
			if(update_left <= node_range_left && node_range_right <= update_right) {
				tree[node] += value;
				propagate_children(node, value);
				return;
			}

			/// Else the range of the current node partially overlaps with the update range
			int mid = (node_range_left + node_range_right) / 2;
			update(get_left_child(node), node_range_left, mid, update_left, update_right, value);
			update(get_right_child(node), mid + 1, node_range_right, update_left, update_right, value);

			tree[node] = max(tree[get_left_child(node)], tree[get_right_child(node)]);
		}

		int query(int node, int node_range_left, int node_range_right, int query_left, int query_right) {
			/// Update the node if it has any pending updates
			if(lazy[node] != 0) {
				tree[node] += lazy[node];
				propagate_children(node);
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
			return max( query(get_left_child(node), node_range_left, mid, query_left, query_right),
						query(get_right_child(node), mid + 1, node_range_right, query_left, query_right) );
		}

		void propagate_children(int node, int value) {
			if(!is_leaf(node)) {
				lazy[get_left_child(node)] += value;
				lazy[get_right_child(node)] += value;
			}
		}

		void propagate_children(int node) {
			propagate_children(node, lazy[node]);
		}

		inline bool is_leaf(int node) {
			return node >= get_leaf_node(0) && node <= pow2(height) - 2;
		}

		inline int get_leaf_node(int leaf_index) {
			return leaf_index + pow2(height - 1) - 1;
		}

		inline int get_left_child(int node) {
			return node * 2 + 1;
		}

		inline int get_right_child(int node) {
			return get_left_child(node) + 1;
		}

		inline int pow2(int power) {
			return 1 << power;
		}

		inline int get_parent(int node) {
			if(is_left(node))
				node += 1;
			return (node / 2) - 1;
		}

		inline bool is_left(int node) {
			return node % 2 == 1;
		}

		inline bool is_right(int node) {
			return !is_left(node);
		}

	public:
		lazy_segment_tree_max(int* _tree, int* _lazy, int* leaves, int leaves_size, int default_leaf = 0) {
			tree = _tree;
			lazy = _lazy;
			height = ceil(log2(leaves_size)) + 1;

			for(int i = 0; i < leaves_size; ++i)
				tree[get_leaf_node(i)] = leaves[i];
			
			if(default_leaf != 0) {
				for(int i = leaves_size; i < pow2(height - 1); ++i)
					tree[get_leaf_node(i)] = default_leaf;
			}
			for(int i = get_leaf_node(0) - 1; i >= 0; --i)
				tree[i] = max(tree[get_left_child(i)], tree[get_right_child(i)]);
		}

		lazy_segment_tree_max(int* _tree, int* _lazy, int leaves_size, int default_leaf = 0) {
			tree = _tree;
			lazy = _lazy;
			height = ceil(log2(leaves_size)) + 1;

			if(default_leaf != 0) {
				for(int i = 0; i < pow2(height - 1); ++i)
					tree[get_leaf_node(i)] = default_leaf;
				for(int i = get_leaf_node(0) - 1; i >= 0; --i)
					tree[i] = max(tree[get_left_child(i)], tree[get_right_child(i)]);
			}
		}

		int query(int leaf) {
			return query(leaf, leaf);
		}

		int query(int query_left, int query_right) {
			return query(0, 0, pow2(height - 1) - 1, query_left, query_right);
		}

		void update(int node, int value) {
			update(node, node, value);
		}

		void update(int update_left, int update_right, int value) {
			update(0, 0, pow2(height - 1) - 1, update_left, update_right, value);
		}

		void print() {
			int lvl = 1;
			int lvl_curr = 0;
			for(int i = 0; i <= get_leaf_node(pow2(height - 1) - 1); ++i) {
				cout << tree[i] << " ";
				lvl_curr++;
				if(lvl_curr >= lvl) {
					lvl_curr = 0;
					cout << endl;
					lvl *= 2;
				}
			}
			cout << endl;

			lvl = 1;
			lvl_curr = 0;
			for(int i = 0; i <= get_leaf_node(pow2(height - 1) - 1); ++i) {
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
};


struct point {
	int x, y, compressed_h, compressed_y;
};


int n, w, h;
const int MAXN = 1e5;
point pts[MAXN];
int tree_arr[MAXN * 4], lazy_arr[MAXN * 4];
int ans;


bool sort_by_y_cmp(point a, point b) {
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}


bool sort_by_x_cmp(point a, point b) {
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w >> h;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pts[i].x = x;
		pts[i].y = y;
	}

	/// Compress points
	/// compressed_h - the amount of points that are above every point, but are within h of that point
	/// compressed_y - the amount of points below every point
	sort(pts, pts + n, sort_by_y_cmp);
	int up = 0;
	int down = 0;
	while(down < n) {
		while(up < n && pts[down].y + h >= pts[up].y)
			++up;
		--up;
		pts[down].compressed_h = up - down;
		pts[down].compressed_y = down;
		++down;
	}
	
	/// Solve
	lazy_segment_tree_max seg_tree(tree_arr, lazy_arr, n);
	sort(pts, pts + n, sort_by_x_cmp);

	int left = 0;
	int right = -1;

	while(left < n) {
		while(right < n && pts[left].x + w >= pts[right].x) {
			++right;
			seg_tree.update(pts[right].compressed_y, pts[right].compressed_y + pts[right].compressed_h, 1);
			
		}
		seg_tree.update(pts[right].compressed_y, pts[right].compressed_y + pts[right].compressed_h, -1);
		--right;

		ans = max(ans, seg_tree.query(0, n - 1));

		seg_tree.update(pts[left].compressed_y, pts[left].compressed_y + pts[left].compressed_h, -1);
		++left;
	}

	cout << ans << endl;

	return 0;
}