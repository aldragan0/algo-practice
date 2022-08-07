#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n + 1);

    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            ++f[j];
        }
    }

    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += f[i];
    }

    cout << s + n;
}