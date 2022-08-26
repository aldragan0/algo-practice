#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int max_el = a[n-1];
	
	int min_c = 0;

	int kmax = max_el + m;

	for(int i = 0; i < n; ++i)
		min_c += max_el - a[i];

	m = max(0, m - min_c);

	int kmin = max_el + m / n + (m % n != 0);

	cout << kmin << ' ' << kmax;
}

