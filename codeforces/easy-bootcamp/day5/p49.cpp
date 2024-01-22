#include <bits/stdc++.h>

#define nl '\n'

typedef long long ll;

using namespace std;

/*
 * King Moves
 */

int main() {
	char c;
	int d;
	cin >> c >> d;

	c -= ('a' - 1);

	int npos = 8;

	if(c == 1 || c == 8)
		npos -= 3;
	if(d == 1 || d == 8)
		npos -= 3;
	if(npos == 2) ++npos;

	cout << npos;
}

