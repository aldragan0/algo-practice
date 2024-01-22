#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

// for part two just change the 3 & 4 to 13 & 14

int findMarker(string line) {
    for(int i = 0; i < line.size() - 4; ++i) {
        bool found = true;
        for(int j = i; j < i + 3; ++j) {
            for(int k = j + 1; k < i + 4; ++k) {
                if (line[j] == line[k]) {
                    found = false;
                    break;
                }
            }
            if (!found) break;
        }
        if (found) return i + 4;
    }
    return -1;
}


int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	string line;
	while(getline(f, line)) {
        cout << findMarker(line) << NL;
	}
}
