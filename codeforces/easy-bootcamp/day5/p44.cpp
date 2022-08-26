#include <bits/stdc++.h>

using namespace std;

double n_choose_k(int n, int k) {
	double h = 1;
	
	int i = n, j = 2;
	for(; i > n - k && j <= k; --i, ++j)
		h *= ((double)i / j);
	for(; i > n - k; --i)
		h *= i;
	for(; j <= k; ++j)
		h /= j;
	return h;
}

int main() {
	int n;
	cin >> n;

	if (n < 4) {
		cout << n;
		return 0;
	}

	double s = 1;
	for(int i = 1; i <= n / 2; ++i) {
		s += n_choose_k(n - i, i);
	}

	cout.precision(20);
	cout << s;
}

