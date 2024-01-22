#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

int getScore(char a, char b) {
	a -= 'A';
	b -= 'X';
	if(a == b) return 3;
	return (b - a == 1 || b - a == -2) ? 6 : 0;
}

int getSignScore(char a) {
	return a - 'X' + 1;
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	string line;
	int total = 0;
	while(getline(f, line)) {
		char a, b;
		a = line[0];
		b = line[2];
		total += (getScore(a, b) + getSignScore(b));
	}
	cout << total << NL;
}
