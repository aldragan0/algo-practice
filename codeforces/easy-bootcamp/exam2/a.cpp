#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> a(n);

	ll s = 0;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int i = 0;
	for(; i < n && s < x; ++i) {
		s += a[i];
	}

	cout << (s >= x ? i : -1);
}

