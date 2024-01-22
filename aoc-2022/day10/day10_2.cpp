#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

    int cycle = 0;
    int x = 1;

	string line;
    string buffer;
	while(getline(f, line)) {
        int pos = line.find(' ');
        int value = 0;
        int cycleTime = 0;

        if(pos == -1) cycleTime = 1;
        else cycleTime = 2;

        for(int i = 0; i < cycleTime; ++i) {
            if (cycle != 0 && cycle % 40 == 0) {
                cout << buffer << NL;
                buffer.clear();
            }

            if (abs((cycle % 40) - x) <= 1) {
                buffer.push_back('#');
            } else {
                buffer.push_back('.');
            }

            ++cycle;
        }

        if (cycleTime == 2) {
            value = stoi(line.substr(pos + 1, line.size()));
            x += value;
        }
	}
    if (!buffer.empty()) cout << buffer << NL;
}
