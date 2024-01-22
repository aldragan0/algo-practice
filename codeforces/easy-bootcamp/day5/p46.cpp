#include <bits/stdc++.h>

#define nl '\n'

typedef long long ll;

using namespace std;

/*
 * Eleven
 */

int main() {
	int n;
	cin >> n;

	vector<int> f;

	int a = 1, b = 1;
	while(a <= n) {
		f.push_back(b);
		int temp = a + b;
		a = b;
		b = temp;
	}

	for(int i = 1; i <= n; ++i) {
		if(find(f.begin(), f.end(), i) != f.end()) cout << 'O';
		else cout << 'o';
	}
}

