#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = 1;
    for (int i = min(n, 16); i >= 2; i >>= 1) {
        for (int j = 1; j <= n / i; ++j) {
            bool sorted = true;
            for (int k = (j - 1) * i; k < j * i - 1; ++k) {
                if (a[k] > a[k + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                m = max(m, i);
                break;
            }
        }
    }

    cout << m;
}