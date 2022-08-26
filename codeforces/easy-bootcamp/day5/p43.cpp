#include <bits/stdc++.h>

using namespace std;

/*
 * p43 - Numbers on the circle: [compute n!]
 */

int main() {
	int n;
	cin >> n;

	long long s = 0;

	for(int i = 1; i <= n; ++i) {
		int next = (i == n) ? 1 : i + 1;

		long long c = 1;
		for(int j = 1; j <= n; ++j) {
			if(j == i || j == next) continue;
			c *= j;
		}
		s += c;
	}

	cout << s;
}

