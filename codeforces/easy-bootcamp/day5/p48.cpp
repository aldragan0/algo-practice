#include <bits/stdc++.h>

#define nl '\n'

typedef long long ll;

using namespace std;

/*
 * The line - same idea as p44 but N is huge
 * ------------------------------------------
 * Actually what's required is to compute the
 * N'th term of the fibonnaci sequence mod P
 */

int main() {
	ll n, p;
	cin >> n >> p;

	ll a = 1, b = 1;

	for(int i = 1; i <= n; ++i) {
		ll t = (a + b) % p;
		a = b;
		b = t;
	}

	cout << a;
}

