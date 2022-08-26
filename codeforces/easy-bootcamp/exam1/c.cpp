#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	if(n < 4) {
		cout << 0;
		return 0;
	}

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(), [](int i, int j) { return i > j; });
	cout << (long long)a[3] * a[3];
}

