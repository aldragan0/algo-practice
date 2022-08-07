#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int div = 0;
    for (int i = 1; i <= min(k, n); ++i) {
        if (k % i == 0 && k / i <= n) {
            ++div;
        }
    }

    cout << div;
}