#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string bools2string(vector<bool> bools) {
	string output = "";
	for(int i = 0; i < bools.size(); i += 8) {
		char chr = 0;
		int curr = 128;
		for(int j = i; j < bools.size(); ++j) {
			if(bools[j])
				chr += curr;
			curr /= 2;
			if(curr <= 0)
				break;
		}
		output += chr;
	}
	return output;
}

vector<bool> string2bools(string input) {
	vector<bool> output;
	for(int i = 0; i < input.size(); ++i) {
		int curr = 128;
		int chr = (int)(uint8_t)input[i];
		while(curr > 0) {
			//cout << chr << endl;
			if(chr - curr >= 0) {
				output.push_back(true);
				//cout << 1 << endl;
				chr -= curr;
			}	
			else {
					output.push_back(false);
					//cout << 0 << endl;
			}
				
			curr /= 2;
		}
	}
	return output;
}

vector<bool> ints2bools(vector<int> ints) {
	vector<bool> bools;
		for(int i = 0; i < ints.size(); ++i) {
		long long int curr = 2147483648;
		long long int chr = (unsigned int)ints[i];
		while(curr > 0) {
			//cout << chr << endl;
			if(chr - curr >= 0) {
				bools.push_back(true);
				chr -= curr;
			}	
			else
				bools.push_back(false);
			curr /= 2;
		}
	}
	return bools;
}

vector<int> bools2ints(vector<bool> bools) {
	vector<int> ints;
	for(int i = 0; i < bools.size(); i += 32) {
		unsigned int chr = 0;
		unsigned int curr = 2147483648;
		for(int j = i; j < bools.size(); ++j) {
			if(bools[j])
				chr += curr;
			curr /= 2;
			if(curr <= 0)
				break;
		}
		ints.push_back((int)chr);
	}
	return ints;
}

vector<int> encode(string input) {
	vector<int> output;
	unordered_map<string, int> dict;
	for(int i = 0; i <= 255; ++i) {
		string chr = "";
		chr += char(i);
		dict[chr] = i;
		/*if(i > 128)
			cout << i << " " << char(i) << " " << (int)char(i) << endl;*/
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
			/*cout << p << " " << dict[p] << endl;
			cout << p + c << " " << curr << endl;*/
			dict[p + c] = curr;
			++curr;
			p = c;
		}
		else
			p += c;
		
		c = "";
	}
	//cout << p << " " << dict[p] << endl;
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
	cout << (int)(bool)1 << endl;
	vector<bool> bools;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		bool b;
		cin >> b;
		bools.push_back(b);
	}
	/*cout << bools2ints(bools).size() << endl;
	cout << "?" << endl;*/
	//string o1 = bools2string(bools);
	//cout << o1 << endl;
	//cout.flush();
	/*
	vector<int> o2 = encode(o1);
	for(auto i : o2)
		cout << i << " ";
	cout << endl;
	//cout.flush();

	vector<bool> o3 = ints2bools(o2);
	for(auto i : o3)
		cout << i << " ";
	cout << endl;
	cout.flush();

	vector<int> o4 = bools2ints(o3);
	for(auto i : o4)
		cout << i << " ";
	cout << endl;
	cout.flush();
	
	string o5 = decode(o4);
	//cout << o5 << endl;
	//cout.flush();
	
	vector<bool> o6 = string2bools(o5);
	for(auto i : o6)
		cout << (int)i << " ";
	cout << endl;
	cout.flush();*/

	vector<bool> bools2 = string2bools(decode(bools2ints(ints2bools(encode(bools2string(bools))))));
	cout << bools2.size() << endl;
	for(int i = 0; i < bools2.size(); ++i)
		cout << bools2[i] << endl;
	return 0;
}