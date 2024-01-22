#include <bits/stdc++.h>

#define nl '\n'

typedef long long ll;

using namespace std;

/*
 * Collatz conjecture
 */

void solve(long long n) {
	cout << n << nl;

	if(n == 1) return;
	else if(n % 2 == 0)
		solve(n / 2);
	else
		solve(3 * n + 1);
}

int main() {
	long long n;
	cin >> n;
	solve(n);
}

