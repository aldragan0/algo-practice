#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

struct interval {
	int start;
	int end;
};

bool overlaps(interval a, interval b) {
	return ((a.start <= b.start && b.end <= a.end)
			|| (b.start <= a.start && a.end <= b.end));
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	int cnt = 0;
	interval a, b;
	char sep;
	while(f >> a.start >> sep >> a.end >> sep >> b.start >> sep >> b.end) {
		if (overlaps(a, b)) {
			++cnt;
		}
	}

	cout << cnt << NL;
}
