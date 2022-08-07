#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> a;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] < s[i] && s[i + 1] < s[i]) {
            a.push_back(i + 1);
        }
    }

    int day_len = 0;
    for (int i = 2; i <= n; ++i) {
        if (n % i != 0) continue;
        size_t idx = 0;
        bool good_day;
        for (int j = 1; j <= n / i; ++j) {
            good_day = false;
            while (idx < a.size() && a[idx] > i * (j - 1) && a[idx] <= i * j) {
                good_day = true;
                ++idx;
            }
            if (!good_day) break;
        }

        if (good_day) {
            day_len = i;
            break;
        }
    }

    if (day_len == 0) {
        cout << 0;
    }
    else {
        cout << n / day_len;
    }
}