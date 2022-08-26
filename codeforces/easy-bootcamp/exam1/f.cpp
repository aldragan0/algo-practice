#include <bits/stdc++.h>

using namespace std;

int pmax(const vector<int> & a) {
	int ci = 0;
	int cm = a[0];
	for(int i = 1; i < 26; ++i) {
		if(cm < a[i]) {
			ci = i;
			cm = a[i];
		}
	}
	return ci;
}


int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(26);

	for(int i = 0; i < n; ++i) {
		char m;
		cin >> m;
		a[m - 'A']++;
	}

	long long s = 0;

	while(k > 0) {
		int argmax = pmax(a);
		int nmin = min(a[argmax], k);
		s += (long long)nmin * nmin;
		a[argmax] -= nmin;
		k -= nmin;
	}

	cout << s;
}

