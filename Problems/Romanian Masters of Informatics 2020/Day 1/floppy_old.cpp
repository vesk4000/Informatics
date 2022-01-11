#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
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

vector<int> delta_compress(vector<int> v) {
	vector<int> ans = v;
	for(int i = 1; i < v.size(); ++i)
		ans[i] = v[i] - v[i - 1];
	return ans;
}

vector<int> delta_decompress(vector<int> v) {
	vector<int> ans = v;
	for(int i = 1; i < v.size(); ++i)
		ans[i] = v[i] + ans[i - 1];
	return ans;
}

string bit_compress(vector<int> v, int byte_size = 8, int bits_for_num_bytes = 2) {
	string ans = "";
	for(int num : v) {
		int num_bytes = 1;
		for(; 1 << (num_bytes * byte_size) < num; ++num_bytes) {}
		//cout << num << " " << num_bytes << endl;

		ans += uint2bits(num_bytes, bits_for_num_bytes) + int2bits(num, num_bytes * byte_size);
		//cout << uint2bits(num_bytes, bits_for_num_bytes) + int2bits(num, num_bytes * byte_size) << endl;
	}
	return ans;
}

vector<int> bit_decompress(string s, int byte_size = 8, int bits_for_num_bytes = 2) {
	vector<int> ans;
	for(int i = 0; i < s.size();) {
		int num_bytes = bits2int(s.substr(i, bits_for_num_bytes));
		i += bits_for_num_bytes;
		ans.push_back(bits2int(s.substr(i, num_bytes * byte_size)));
		i += num_bytes * byte_size;
	}
	return ans;
}

void read_array(int subtask_id, const vector<int>& v) {
	vector<int> nums = delta_compress(v);
	nums = delta_compress(nums);
	save_to_floppy(bit_compress(nums));
	//save_to_floppy("101");
	/*for(auto num : nums)
		cout << num << endl;

	nums = delta_decompress(nums);
	nums = delta_decompress(nums);
	for(auto num : nums)
		cout << num << endl;
	
	cout << endl;
	cout << bit_compress(nums) << endl;
	vector<int> ans = bit_decompress(bit_compress(nums));
	for(auto an : ans)
		cout << an << endl;*/
}

vector<int> solve_queries(int subtask_id, int N, const string& bits,
		const vector<int> &a, const vector<int> &b) {

	vector<int> ans(a.size());
	vector<int> nums = bit_decompress(bits);
	for(auto num : nums)
		cout << num << endl;
	nums = delta_decompress(nums);
	nums = delta_decompress(nums);
	for(auto num : nums)
		cout << num << endl;
	for(int i = 0; i < a.size(); ++i) {
		int mx = numeric_limits<int>::min();
		//cout << a[i] << " " << b[i] << " " << mx << endl;
		for(int j = a[i]; j <= b[i]; ++j) {
			if(nums[j] > mx)
				mx = nums[j];
		}
		ans.push_back(mx);
		cout << a[i] << " " << b[i] << " " << mx << endl;
	}
	return ans;
}

/*int main() {
	int n;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	read_array(0, v);
	return 0;
}*/