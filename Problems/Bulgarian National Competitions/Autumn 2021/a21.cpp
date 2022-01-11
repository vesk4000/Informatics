#include "hint.h"
#include <iostream>
#include <vector>
using namespace std;

std::vector<bool> genHint(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& sol) {
	vector<bool> hint;
	if(a.size() < b.size()) {
		hint.push_back(true);
		int i = 0;
		for(int soli = 0; soli < sol.size(); ++soli) {
			for(; i < a.size(); ++i) {
				if(sol[soli] == a[i]) {
					hint.push_back(true);
					++i;
					break;
				}
				else {
					hint.push_back(false);
				}

			}
		}
	}
	else {
		hint.push_back(false);
		int i = 0;
		for(int soli = 0; soli < sol.size(); ++soli) {
			for(; i < b.size(); ++i) {
				//cout << sol[soli] << " " << b[i] << endl;
				if(sol[soli] == b[i]) {
					hint.push_back(true);
					++i;
					break;
				}
				else {
					hint.push_back(false);
				}

			}
		}
	}

	return hint;
}


std::vector<int> solve(const std::vector<int>& a, const std::vector<int>& b, const std::vector<bool>& hint) {
	vector<int> sol;
	if(hint[0]) {
		for(int i = 1; i < hint.size(); ++i) {
			if(hint[i])
				sol.push_back(a[i - 1]);
		}
	}
	else {
		for(int i = 1; i < hint.size(); ++i) {
			if(hint[i])
				sol.push_back(b[i - 1]);
		}
	}
	
	return sol;
}