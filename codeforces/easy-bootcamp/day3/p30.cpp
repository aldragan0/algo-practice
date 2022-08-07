#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b, upper, lower;
    for (int i = 0; i < n; ++i) {
        int c, r;
        cin >> a >> b >> c >> r;

        if (a < b) swap(a, b);
        upper = min(a, c + r);
        lower = max(b, c - r);
        int cover_area = max(upper - lower + 1, 1);

        cout << a - b + 1 - cover_area << '\n';
    }
}