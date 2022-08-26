#include <bits/stdc++.h>

using namespace std;

char replace(char ch) {
	switch(ch) {
		case 'a': return '4';
		case 'i': return '1';
		case 'e': return '3';
		case 'o': return '0';
		case 's': return '5';
		default: return ch;
	}
}


int main() {
	string s;
	getline(cin, s);

	for(uint32_t i = 0; i < s.size(); ++i) {
		s[i] = replace(s[i]);
	}
	cout << s;
}

