#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool even = n % 2 == 0;
    if (!even) {
        n -= 3;
    }
    n /= 2;

    if (!even) {
        cout << n + 1 << '\n';
    }
    else {
        cout << n << '\n';
    }

    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << 2;
    }
    if (!even) {
        cout << " " << 3;
    }
}