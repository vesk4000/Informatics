#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

string s[26];
//unordered_map<string, long long int> mem;


long long int solve(string cs) {
	/*if(mem.find(cs) != mem.end())
		return mem[cs];*/
	if(cs.size() == 26) {
		return 1;
	}

	bool used[26];
	memset(used, 0, sizeof(used));
	/*for(int i = 0; i < cs.size(); ++i) {
		used[cs[i] - 'A'] = true;
	}*/
	//cout << cs << endl;
	int ans = 0;
	bool usedccs[26];
	memset(usedccs, 0, sizeof(usedccs));
	string ccs = s[cs.size()];
	string tmp;
	for(int i = 0; i < ccs.size(); ++i) {
		char c = ccs[i];
		int ci = c - 'A';
		if(!used[ci] && !usedccs[ci]) {
			usedccs[ci] = true;
			tmp = cs + c;
			ans += solve(tmp);
		}
	}
	//cout << cs << endl;
	//mem[cs] = ans;
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 0; i < 26; ++i) {
		cin >> s[i];
	}
	cout << solve("") << endl;
}
