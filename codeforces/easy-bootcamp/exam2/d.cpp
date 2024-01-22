#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> f;

	int a = 0, b = 1;

	while(a <= n) {
		f.push_back(a);
		int t = a + b;
		a = b;
		b = t;
	}

	for(int i = f.size() - 1; i >= 0; --i) {
		bool found = binary_search(f.begin(), f.end(), n - f[i]);
		if(found) {
			cout << "yes";
			return 0;
		}
	}

	cout << "no";
}

