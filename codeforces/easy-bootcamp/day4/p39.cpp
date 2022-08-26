#include <bits/stdc++.h>

using namespace std;

/*
 * Vitamins
 */

int main() {
	int t, c;
	cin >> t;

	size_t i = 0;
	string s;

	vector<int> p(t);
	vector<int> v(t);
	while(t--) {
		cin >> c >> s;
		int isa = s.find('A') != -1;
		int isb = s.find('B') != -1;
		int isc = s.find('C') != -1;

		p[i] = c;
		v[i] = (isc << 2) + (isb << 1) + isa;
		++i;
	}

	int m = INT_MAX;

	for(i = 0; i < p.size(); ++i) {
		if(v[i] == 7) {
			m = min(m, p[i]);
			continue;
		}

		for(size_t j = i + 1; j < p.size(); ++j) {
			if((v[i] | v[j]) == 7) {
				m = min(m, p[i] + p[j]);
				continue;
			}

			for(size_t k = j + 1; k < p.size(); ++k) {
				if((v[i] | v[j] | v[k]) == 7) {
					m = min(m, p[i] + p[j] + p[k]);
				}
			}
		}
	}
	cout << ((m == INT_MAX) ? -1 : m) <<'\n';
}

