#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;

/*
!asdsadasd
TODO ASDADSD
#
? dasdsadasdasdas
* sadsadasdsa
#: #dynamic-programming #dp #asd
*/

int setBit(int n, int k) {
	return (n | (1 << (k - 1)));
}

int clearBit(int n, int k) {
	return (n & (~(1 << (k - 1))));
}

struct IntVectorHash {
	int operator()(const vector<int> &V) const {
		int hash = V.size();
		for(auto &i : V) {
			hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
		}
		return hash;
	}
};

// max size of both the uncopressed char size and compressed char size is 64 bits
// anymore than that would be impractical anyway
vector<bool> compress(
	vector<bool> uncompressed_data,
	const unsigned int uncompr_char_size = 8,
	const unsigned int compr_char_size = 12) {
	
	unordered_map<vector<int>, int, IntVectorHash> dict;

	vector<int> data;
	data.reserve(uncompressed_data.size() / uncompr_char_size + 1);
	int j = 1;
	for(int i = 0; i < uncompressed_data.size(); ++i) {
		
	}
}