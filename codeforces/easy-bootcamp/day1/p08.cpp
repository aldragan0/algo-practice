#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;

    if (n == 0) {
        cout << L / a;
        return 0;
    }

    vector<int> t(n), l(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> l[i];
    }

    int nb = 0;
    for (int i = 0; i < n - 1; ++i) {
        nb += (t[i + 1] - t[i] - l[i]) / a;
    }

    nb += (L - t[n - 1] - l[n - 1]) / a + t[0] / a;
    cout << nb;
}