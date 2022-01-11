#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>
#include "floppy.h"
using namespace std;

string reversed(string s){
	string ans = "";
	for(int i = s.size() - 1; i >= 0; --i)
		ans += s[i];
	return ans;
}

string int2bits(int num, int num_bits) {
	if(num > 1 << num_bits) {
		cout << "BIT OVERFLOW" << endl;
		return "";
	}

	string ans = "0";
	if(num < 0) {
		num = -num;
		ans = "1";
	}

	string bits = "";
	if(num == 0)
		bits = "0";
	else {
		while(num > 1) {
			bits += num % 2 + '0';
			num /= 2;
		}
		bits += '1';
		bits = reversed(bits);
	}

	for(int i = 0; i < num_bits - bits.size() - 1; ++i)
		ans += '0';
	ans += bits;
	return ans;
}

string uint2bits(int num, int num_bits) {
	string ans = int2bits(num, num_bits + 1);
	return ans.substr(1, num_bits);
}

int bits2int(string bits) {
	int ans = 0;
	int sign = 1;
	if(bits[0] == 1)
		sign = -1;
	for(int i = 1; i < bits.size(); ++i) {
		ans *= 2;
		ans += bits[i] - '0';
	}
	ans *= sign;
	return ans;
}

struct number {
	int val, orig_index;
};

bool number_cmp(number a, number b) {
	return a.val < b.val;
}

void read_array(int subtask_id, const vector<int>& v) {
	vector<number> nums;
	for(int i = 0; i < v.size(); ++i) {
		number num;
		num.val = v[i];
		num.orig_index = i;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), number_cmp);

	string ans = "";
	for(number num : nums)
		ans += uint2bits(num.orig_index, 14);
	save_to_floppy(ans);
}


vector<int> solve_queries(int subtask_id, int N, const string& bits,
		const vector<int> &a, const vector<int> &b) {
	
	vector<int> indexes;
	for(int i = 0; i < bits.size(); i += 14)
		indexes.push_back(bits2int("0" + bits.substr(i, 14)));
	/*cout << indexes.size() << endl;
	for(auto index : indexes)
		cout << index << endl;*/

	vector<int> nums(N);
	for(int i = 0; i < indexes.size(); ++i)
		nums[indexes[i]] = i;
	/*for(auto num : nums)
		cout << num << endl;*/

	vector<int> ans;
	for(int i = 0; i < a.size(); ++i) {
		int mx = numeric_limits<int>::min();
		int mx_index = -1;
		for(int j = a[i]; j <= b[i]; ++j)
			if(nums[j] > mx) {
				mx = nums[j];
				mx_index = j;
			}
		ans.push_back(mx_index);
		//cout << a[i] << " " << b[i] << " " << ans[i] << endl;
	}

	return ans;
}