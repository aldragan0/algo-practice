#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> c(26);
	for(int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		c[ch - 'a']++;
	}

	for(int i = 0; i < 26; ++i)
		if(k < c[i]) {
			cout << "NO";
			return 0;
		}

	cout << "YES";
}

