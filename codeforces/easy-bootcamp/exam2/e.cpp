#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
	int n = 3;
	vector<vector<int>> a(n, vector<int>(n));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	int b, c, d;
	b = c = d = 0;

	for(int j = 0; j < n; ++j) {
		b += a[0][j];
		c += a[1][j];
		d += a[2][j];
	}

	int m = max(b, max(c, d));
	b = abs(b - m);
	c = abs(c - m);
	d = abs(d - m);

	int c1, c2, c3, r1, r2, r3, d1, d2;
	c1 = r1 = b;
	c2 = r2 = d2 = c;
	c3 = r3 = d;
	d1 = b + c + d;
	for(int i = 0; i < n; ++i) {
		c1 += a[i][0];
		c2 += a[i][1];
		c3 += a[i][2];
		r1 += a[0][i];
		r2 += a[1][i];
		r3 += a[2][i];
		d2 += a[i][n - i - 1];
	}

	int found = 0;
	for(int k = 0; k <= 100000; ++k) {
		if(k + c1 == k + c2
				&& k + c2 == k + c3
				&& k + c3 == k + r1
				&& k + r1 == k + r2
				&& k + r2 == k + r3
				&& k + r3 == 3 * k + d1
				&& 3 * k + d1 == k + d2) {
			found = k;
			break;
		}
	}

	a[0][0] = b + found;
	a[1][1] = c + found;
	a[2][2] = d + found;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << a[i][j];
			if(j != n - 1) cout << ' ';
		}
		cout << NL;
	}

}

