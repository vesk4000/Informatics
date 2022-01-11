#include <iostream>
#include <vector>
using namespace std;
void _build();
void _delete(int pos);
void _insert(int pos, int new_value);
void _replace(int pos, int new_value);
void _print();
int _get_left(int pos);
int _get_right(int pos);

int n;
const int MAXN = 200001;//200 001
vector<int> v;
int t;
int sum;

void _replace(int pos, int new_value) {
	--pos;
	int left = _get_left(pos);
	int right = _get_right(pos);
	int curr = v[pos];
	if(curr != new_value) {
		if(curr == left) {
			++sum;
		}
		if(curr == right) {
			++sum;
		}
		if(new_value == left) {
			--sum;
		}
		if(new_value == right) {
			--sum;
		}
	}
	v[pos] = new_value;
}

void _insert(int pos, int new_value) {
	--pos;
	v.insert(v.begin() + pos, new_value);
	int left = _get_left(pos);
	int right = _get_right(pos);
	if(new_value != left && new_value != right)
		++sum;
	if(left == right)
		++sum;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	_build();
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int arg1, arg2, arg3;
		cin >> arg1;
		if(arg1 == 1) {
			cin >> arg2;
			_delete(arg2);
		}
		else if(arg1 == 2) {
			cin >> arg2 >> arg3;
			_insert(arg2, arg3);
		}
		else if(arg1 == 3) {
			cin >> arg2 >> arg3;
			_replace(arg2, arg3);
		}
		else if(arg1 == 4) {
			_print();
		}
	}
	return 0;
}

void _delete(int pos) {
	--pos;
	int left = _get_left(pos);
	int right = _get_right(pos);
	int curr = v[pos];
	if(curr != left && curr != right) {
		--sum;
		if(left == right) {
			--sum;
		}
	}
	v.erase(v.begin() + pos);
}

void _print() {
	cout << sum << endl;
}

void _build() {
	++sum;
	for(int i = 1; i < v.size(); ++i) {
		if(v[i] != v[i - 1])
			++sum;
	}
}

int _get_left(int pos) {
	if(pos - 1 < 0) {
		return -1;
	}
	return v[pos - 1];
}

int _get_right(int pos) {
	if(pos + 1 >= v.size()) {
		return -1;
	}
	return v[pos + 1];
}
