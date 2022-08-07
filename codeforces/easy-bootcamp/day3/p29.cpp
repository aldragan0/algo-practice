#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        bool no_build = (a > b + c + 1)
            || (b > a + c + 1)
            || (c > a + b + 1);

        if (no_build) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
}