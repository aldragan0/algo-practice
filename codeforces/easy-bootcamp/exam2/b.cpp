#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	ll s = 0;

	for(int i = 1; i < n; ++i) {
		s += (a[i] - a[i - 1] - 1);
	}

	cout << s;
}

