#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long x, y;
    x = y = 0;

    for (int i = 0; i < n / 2; ++i) {
        x += a[i];
        y += a[n - i - 1];
    }

    if (n % 2 != 0)
        y += a[n / 2];

    cout << (x * x + y * y);
}