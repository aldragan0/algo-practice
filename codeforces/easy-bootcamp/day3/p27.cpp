#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int nr;
        cin >> nr;
        auto it = a.begin();
        for (; it != a.end(); ++it) {
            if (*it < nr) break;
        }
        auto pos = a.insert(it, nr);
        cout << pos - a.begin() + 1 << '\n';
    }

    for (const auto& t : a) {
        cout << t << ' ';
    }
}