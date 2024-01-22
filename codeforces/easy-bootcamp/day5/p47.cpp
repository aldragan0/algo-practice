#include <bits/stdc++.h>

#define nl '\n'

typedef long long ll;

using namespace std;

/*
 * Hexadecimal's theorem
 */

int main() {
	int n;
	cin >> n;

	int a = 0, b = 1;

	if(n == 2) cout << a << ' ' << b << ' ' << b;
	else if(n == 1) cout << a << ' ' << a << ' ' << b;
	else if(n == 0) cout << a << ' ' << a << ' ' << a;
	else {
		while((a + b) < n) {
			int t = a + b;
			a = b;
			b = t;
		}

		cout << a << ' ' << b << ' ' << 0;
	}
}

