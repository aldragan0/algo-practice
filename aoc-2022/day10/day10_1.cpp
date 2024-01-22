#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

    int cycle = 0;
    int x = 1;
    ll sum = 0;

	string line;
	while(getline(f, line)) {
        int pos = line.find(' ');
        int value = 0;
        if(pos == -1) { // op is noop
            ++cycle;
            value = 0;
        } else { // op is addx
            value = stoi(line.substr(pos + 1, line.size()));
            x += value;
            cycle += 2;
        }

        if (cycle >= 20) {
            if ((cycle - 20) % 40 == 0) {
                if (value == 0) {
                    // was noop before
                    sum += cycle * x;
                } else {
                    // subtract if was addx before, because addx finishes at the end of cycle
                    sum += cycle * (x - value);
                }
            } else if((cycle - 20) % 40 == 1 && value != 0) {
                // we're after an addx op that passed the clock sample count
                sum += (cycle - 1) * (x - value);
            }
        }
	}

    cout << sum << NL;
}
