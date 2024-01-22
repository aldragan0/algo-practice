#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

struct interval {
	int start;
	int end;
};

int overlapCount(interval a, interval b) {
	return min(a.end, b.end) - max(a.start, b.start) + 1;
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	int cnt = 0;
	interval a, b;
	char sep;
	while(f >> a.start >> sep >> a.end >> sep >> b.start >> sep >> b.end) {
		if (overlapCount(a, b) > 0) {
			++cnt;
		}
	}

	cout << cnt << NL;
}
