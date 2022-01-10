#include <iostream>
#include <string>
#include "brperm.h"
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

string colours;

void init(int n, const char s[]) {
	for(int i = 0; i < n; ++i)
		colours += s[i];
	return;
}

int query(int i, int k) {
	if(i + (1 << k) > colours.size())
		return 0;

	string ccols = colours.substr(i, 1 << k);

	char ncols[(int)1e5];
	for(int i = 0; i < ccols.size(); ++i) {
		ncols[bits2int("0" + reversed(uint2bits(i, k)))] = ccols[i];
	}

	for(int i = 0; i < ccols.size(); ++i) {
		//cout << ccols[i] << " " << ncols[i] << endl;
		if(ccols[i] != ncols[i])
			return 0;
	}
	
	return 1;
}
