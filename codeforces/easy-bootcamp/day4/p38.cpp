#include <bits/stdc++.h>

using namespace std;

/*
 * Vasya and the golden ticket
 */

int main() {
	int n;
	cin >> n;

	string num;
	cin >> num;

	vector<int> a(n);

	long long s = 0;
	for(size_t i = 0; i < num.size(); ++i) {
		a[i] = num[i] - '0';
		s += a[i];
	}

	for(;s >= 0; --s) {
		int nseg = 0, curr = 0;
		size_t i = 0;

		for(; i < a.size(); ++i) {
			curr += a[i];
			if(curr == s) {
				nseg++;
				curr = 0;
			}
			if(curr > s) break;
		}

		if(i == a.size() && nseg >= 2 && curr == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}

