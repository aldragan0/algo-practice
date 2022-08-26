#include <bits/stdc++.h>

using namespace std;

#define N 300000
#define NSEG 1000

int main() {
	int q;
	cin >> q;

	vector<bool> p(N + 1);
	p[1] = 1;
	
	for(int i = 2; i <= N / 2; ++i) {
		if (p[i] == 1) continue;

		for(int j = i * 2; j <= N; j += i) {
			p[j] = 1;
		}
	}

	int c = 0;
	vector<int> np;

	for(int i = 0; i < N; ++i) {
		c += 1 - p[i];
		if((i + 1) % NSEG == 0) {
			np.push_back(c);
			c = 0;
		}
	}
	np.push_back(c);

	while(q--) {
		int a, b;
		cin >> a >> b;

		int s = 0;
		if(b - a + 1 <= NSEG) {
			for(; a <= b; ++a)
				s += 1 - p[a];
		} else {
			for(int i = a / NSEG; i <= b / NSEG; ++i)
				s += np[i];

			for(int i = a - (a % NSEG); i < a; ++i)
				s -= 1 - p[i];
			
			for(int i = min(b + NSEG - (b % NSEG) - 1, N); i > b; --i)
				s -= 1 - p[i];
		}
		cout << s << '\n';
	}
}

