#include <bits/stdc++.h>

#define NL '\n'
#define M 1000000007

typedef long long ll;

using namespace std;

int main() {
	ll x, y, n, r;

	cin >> x >> y >> n;

	switch(n % 6) {
		case 1: r = x; break;
		case 2: r = y; break;
		case 3: r = y - x; break;
		case 4: r = -x; break;
		case 5: r = -y; break;
		default: r = x - y; break;
	}

	cout << (r % M + M) % M;
}

