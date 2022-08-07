#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    int nmax = 0, l = 0;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        nmax = max(i - l, nmax);
        if (2 * s[i] < s[i + 1]) {
            l = i + 1;
        }
    }

    cout << nmax + 1;
}