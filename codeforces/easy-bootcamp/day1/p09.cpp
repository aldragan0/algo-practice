#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int freq = 0;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == '8') ++freq;
    }

    if (!freq || n < 11)
        cout << 0;
    else {
        freq = min(freq, n / 11);
        cout << freq;
    }
}