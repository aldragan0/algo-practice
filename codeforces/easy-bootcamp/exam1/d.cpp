#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	vector<int> f(26);
	for(const char & i : c) {
		f[i - 'A']++;
	}

	for(const char & i : a) {
		f[i - 'A']--;
	}

	for(const char & i : b) {
		f[i - 'A']--;
	}

	for(const int & i : f) {
		if(i != 0) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}

