#include <bits/stdc++.h>

using namespace std;

/*
 * Little C Loves 3 I
 */

int main() {
	int n, r, i, rr, ri;

	cin >> n;

	i = n / 9;
	r = n % 9;
	ri = r / 3;
	rr = r % 3;

	int a, b, c;

	b = c = 3 * i;
	a = 3 * (i + ri);


	a -= 2;
	b += 1;
	c += 1;

	if (rr == 1) {
		b += 1;
	}

	if (rr == 2) {
		b += 1;
		c += 1;
	}

	cout << a << ' ' << b << ' ' << c;
}

