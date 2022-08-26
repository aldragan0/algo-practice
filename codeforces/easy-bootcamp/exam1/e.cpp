#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> p(n + 1, 0);;

	for(int i = 2; i <= n/2; ++i) {
		for(int j = i * 2; j <= n; j += i)
			p[j] = 1;
	}

	long long s = 0;
	for(size_t i = 5; i < p.size(); ++i) {
		if(p[i] == 0 && p[i - 2] == 0) ++s;
	}

	cout << s;
}
