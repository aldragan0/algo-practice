#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 4; i <= n; ++i) {
        int ci = i;
        for (int c = ci % 10; ci != 0; ci /= 10, c = ci % 10) {
            if (c != 4 && c != 7) {
                ci = -1;
                break;
            }
        }
        if (ci == -1) continue;
        if (n % i == 0) {
            n = -1;
            break;
        }
    }

    cout << (n == -1 ? "YES" : "NO");
}