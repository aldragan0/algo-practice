#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

int getScore(char b) {
	return (b - 'X') * 3;
}

int getSignScore(char a, char b) {
	a -= 'A';
	b = b - 'X' - 1;
	int c = (int)(a + b) % 3;
	if (c == -1) c = 2; // when a is rock and we have to lose (choose scissors)
	return c + 1;
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	string line;
	int total = 0;
	while(getline(f, line)) {
		char a, b;
		a = line[0];
		b = line[2];
		total += (getScore(b) + getSignScore(a, b));
	}
	cout << total << NL;
}
