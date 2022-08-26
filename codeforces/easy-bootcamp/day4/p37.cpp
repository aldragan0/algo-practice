#include <bits/stdc++.h>

using namespace std;

/*
 * Make product equal one
 */

int main() {
	int n;
	cin >> n;

	vector<int> a(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long s = 0;
	int cn = 0, cz = 0;

	for (int i = 0; i < n; ++i) {
		if(a[i] > 0) {
			s += a[i] - 1;
			a[i] -= a[i] - 1;
		}
		else if(a[i] < 0) {
			s -= (a[i] + 1);
			a[i] -= (a[i] + 1);
			++cn;
		}
		else {
			++s;
			++cz;
		}
	}

	if(cz == 0 && cn % 2 != 0) {
		s += 2;
	}

	cout << s;
}

