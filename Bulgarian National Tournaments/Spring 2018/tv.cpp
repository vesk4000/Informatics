#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
int q;
string s;
const int MAXL = 500000;///500 000
short command[MAXL];
int l;
int command_sum;
int channel = 1;
void set_channel(int x) {
	while(x > n) {
		x -= n;
	}
	while(x < 1) {
		x += n;
	}
	channel = x;
}

void generate_command() {
	stack<int> command_s;
	for(int i = s.size() - 1; i >= 0; --i) {
		if(s[i] == 'o') {
			if(i > 0) {
				command_s.push(0);
				command_s.push(0);
				--i;
			}
			else {
				command_s.push(0);
			}
		}
		else if(s[i] == '+') {
			command_s.push(1);
		}
		else if(s[i] == '-') {
			command_s.push(-1);
		}
	}
	int idx = 0;
	l = command_s.size();
	while(!command_s.empty()) {
		command[idx] = command_s.top();
		command_s.pop();
		++idx;
	}
	for(int i = 0; i < l; ++i) {
		//cout << command[i] << endl;
		command_sum += command[i];
	}
}

int main() {
	cin >> n;
	cin >> q;
	cin >> s;
	generate_command();
	for(int i = 0; i < q; ++i) {
		channel = 1;
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		int change_sum = 0;
		for(int i = a; i <= b; ++i) {
			if(command[i] == -1) {
				command[i] = 1;
				change_sum += 2;
			}
			else if(command[i] == 1) {
				command[i] = -1;
				change_sum -= 2;
			}
		}
		/*for(int i = 0; i < l; ++i) {
			cout << command[i] << " ";
		}
		cout << endl;*/
		int curr_sign = -2;
		int curr_num = 0;
		for(int i = 0; i < l; ++i) {
			if(command[i] != curr_sign) {
				set_channel(channel + (curr_sign * curr_num));
				curr_num = 1;
				curr_sign = command[i];
			}
			else {
				++curr_num;
				if(i == l - 1) {
					set_channel(channel + (curr_sign * curr_num));
				}
			}

		}
		cout << channel << endl;
	}
	return 0;
}
