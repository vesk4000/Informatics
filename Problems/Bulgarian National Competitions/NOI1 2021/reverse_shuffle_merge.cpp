#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    int left_chars[26];
    memset(left_chars, 0, sizeof(left_chars));
    for(int i = 0; i < s.size(); ++i)
        ++left_chars[s[i] - 'a'];
    
    int tp_chars[26];
    for(int i = 0; i < 26; ++i)
        tp_chars[i] = left_chars[i] / 2;
    
    for(int i = 0; i < 26; ++i)
        if(tp_chars[i] != 0)
            cout << (char)(i + 'a') << " " << tp_chars[i] << endl;
    
    char min_char = 'z';
    int min_char_index = -1;
    
    string ans = "";
    
    for(int i = s.size() - 1; i >= 0; --i) {
        if(min_char > s[i] && tp_chars[s[i] - 'a'] > 0) {
            min_char = s[i];
            min_char_index = i;
        }
        //cout << ans << " " << s[i] << " " << s.substr(0, i + 1) << endl;
        --left_chars[s[i] - 'a'];
        if(left_chars[s[i] - 'a'] < tp_chars[s[i] - 'a']) {
            //cout << "done" << endl;
            /*for(int i = 0; i < 26; ++i)
                if(tp_chars[i] != 0)
                    cout << (char)(i + 'a') << " " << tp_chars[i] << endl;
            for(int i = 0; i < 26; ++i)
                if(left_chars[i] != 0)
                    cout << (char)(i + 'a') << " " << left_chars[i] << endl;*/
            ans += min_char;
            --tp_chars[min_char - 'a'];
            for(; i < min_char_index; ++i)
                ++left_chars[s[i] - 'a'];
            min_char = 'z';
        }
        
    }
    
    return ans;
}

int main() {
	string s;
	cin >> s;
	cout << reverseShuffleMerge(s) << endl;
	return 0;
}