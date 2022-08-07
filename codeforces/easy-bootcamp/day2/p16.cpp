#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s{ 2 };

    for (int j = 3; j <= n / 2; j += 2) {
        bool prime = true;
        for (int i = 3; i * i <= j; ++i) {
            if (j % i == 0) {
                prime = false;
                break;
            }
        }
        if (!prime) continue;
        s.push_back(j);
    }

    int nr = 0;
    for (int i = 0; i <= n; ++i) {
        int cnt = 0;
        for (const auto& j : s) {
            if (i % j == 0) ++cnt;
            if (j > i / 2 || cnt > 2) break;
        }
        if (cnt == 2) ++nr;
    }

    cout << nr;
}