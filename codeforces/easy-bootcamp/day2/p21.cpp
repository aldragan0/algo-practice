#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sieve(n + 1);
    sieve[0] = sieve[1] = 1;

    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (sieve[i] == 1) continue;
        ++cnt;
        for (int j = i * 2; j <= n; j += i) {
            sieve[j] = 1;
        }
    }

    cout << cnt << '\n';
    for (int i = 2; i <= n; ++i) {
        if (sieve[i] == 0) {
            if (i != 2) {
                cout << ' ';
            }
            cout << i;
        }
    }
}