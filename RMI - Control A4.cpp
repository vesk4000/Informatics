#include <iostream>
#include <map>
using namespace std;

int primes[169] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

map<pair<int, int>, int> mem_primes;
map<pair<int, int>, int> mem;

int solve_primes(int n, int k) {
	if(mem_primes.find({n, k}) != mem_primes.end())
		return mem_primes[{n, k}];
	if(k == 1) {
		if(n % 2 == 0)
			return mem_primes[{n, k}] = n / 2;
		return mem_primes[{n, k}] = n / 2 + 1;
	}
	int ans = 1e5;
	for(int i = 0; i < 169 && primes[i] <= n; ++i) {
		if(n % primes[i] == 0) {
			int n1 = n / primes[i];
			if(primes[i] % 2 == 0) {
				ans = min(ans, solve_primes(n1, k - 1) * (primes[i] / 2));
			}
			else {
				ans = min(ans, solve_primes(n1, k - 1) * (primes[i] / 2 + 1));
			}
		}
	}
	return mem_primes[{n, k}] = ans;
}


int solve(int n, int k) {
	if(mem.find({n, k}) != mem.end())
		return mem[{n, k}];
	if(k == 1) {
		if(n % 2 == 0)
			return mem[{n, k}] = n / 2;
		return mem[{n, k}] = n / 2 + 1;
	}
	int ans = 1e5;
	for(int i = 1; i <= n; ++i) {
		if(n % i == 0) {
			int n1 = n / i;
			if(i % 2 == 0) {
				ans = min(ans, solve(n1, k - 1) * (i / 2));
			}
			else {
				ans = min(ans, solve(n1, k - 1) * (i / 2 + 1));
			}
		}
	}
	return mem[{n, k}] = ans;
}


int main() {
	int n, k;
	cin >> n >> k;
	cout << solve_primes(n, k) << endl;
	/*cout << solve(n, k) << endl;
	for(auto item : mem) {
		cout << item.first.first << " " << item.first.second << " " << item.second << endl;
	}*/
	/*cout << solve_primes(n, k) << endl;
	for(auto item : mem_primes) {
		cout << item.first.first << " " << item.first.second << " " << item.second << endl;
	}*/
	/*for(int n = 1; n <= 1000; ++n) {
		for(int k = 1; k <= 10; ++k) {
			cout << n << " " << k << " ";
			int ans_primes = solve_primes(n, k);
			int ans = solve(n, k);
			if(ans_primes != ans)
				cout << "PRIMES DOES NOT WORK: SOLVE: " << ans << " SOLVE_WITH_PRIMES: " << ans_primes;
			else
				cout << ans;
			cout << endl;
		}
	}*/
	return 0;
}