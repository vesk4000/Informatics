#include <iostream>
#include "guess.h"
using namespace std;

int find_number(int MAX) {
	int left = 1;
	int right = MAX;

	while(true) {
		if(right <= left + 1) {
			if(smaller(right))
				return left;
			return right;
		}
		int mid = (right + left) / 2;
		if(smaller(mid + 1)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
}