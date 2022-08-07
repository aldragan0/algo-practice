#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        int nr = sqrt(s[i]);
        if ((long long)nr * nr == s[i] && nr > 1) {
            for (long long d = 2; d * d <= nr; ++d) {
                if (s[i] % d == 0) nr = -1;
            }
        }
        else {
            nr = -1;
        }
        if (nr != -1) cout << "YES\n";
        else cout << "NO\n";
    }
}