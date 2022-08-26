#include <bits/stdc++.h>

using namespace std;

/*
 * Candies 2
 */

#define N 1000

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> c(n);
	vector<int> ct;

	int ss = 0;
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
		ss += c[i];
		if((i + 1) % N == 0) {
			ct.push_back(ss);
			ss = 0;
		}
	}
	ct.push_back(ss);

	while(q--) {
		int a, b;
		cin >> a >> b;
		long long s = 0;

		if(b - a + 1 >= N) {
			for(int da = a / N; da <= b / N; ++da) {
				s += ct[da];
			}

			for(int i = a - (a % N); i < a; ++i)
				s -= c[i];

			for(int i = min(b - (b % N) + N - 1, (int)c.size() - 1); i > b; --i)
				s -= c[i];
		}
		else {
			for(; a <= b; ++a) {
				s += c[a];
			}
		}

		cout << s << '\n';
	}
}

