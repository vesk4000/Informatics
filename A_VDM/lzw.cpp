#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> encode(string input) {
	vector<int> output;
	unordered_map<string, int> dict;
	for(int i = 0; i <= 255; ++i) {
		string chr = "";
		chr += char(i);
		dict[chr] = i;
	}
	
	int curr = 256;
	string c = "";
	string p = "";
	p += input[0];
	for(int i = 0; i < input.size(); ++i) {
		if(i < input.size() - 1)
			c += input[i + 1];
		if(dict.find(p + c) == dict.end()) {
			output.push_back(dict[p]);
			cout << p << " " << dict[p] << endl;
			cout << p + c << " " << curr << endl;
			dict[p + c] = curr;
			++curr;
			p = c;
		}
		else
			p += c;
		
		c = "";
	}
	cout << p << " " << dict[p] << endl;
	output.push_back(dict[p]);
	return output;
}

string decode(vector<int> input) {
	unordered_map<int, string> dict;
	for(int i = 0; i <= 255; ++i) {
		string chr = "";
		chr += char(i);
		dict[i] = chr;
	}

	
	int p = input[0];
	string s = dict[p];
	string output = "";
	output += s;
	string c = "";
	c += s[0];
	int curr = 256;
	
	for(int i = 0; i < input.size() - 1; ++i) {
		if(dict.find(input[i + 1]) == dict.end()) {
			s = dict[p];
			s = s + c;
		}
		else
			s = dict[input[i + 1]];
		output += s;
		c = "";
		c += s[0];
		dict[curr] = dict[p] + c;
		++curr;
		p = i + 1;
	}
	return output;
}

int main() {
	string s;
	cin >> s;
	cout << decode(encode(s)) << endl;
	vector<int> encoded = encode(s);
	cout << encoded.size() << " " << s.size() << endl;
	for(int i = 0; i < encoded.size(); ++i) {
		cout << encoded[i] << endl;
	}
	return 0;
}