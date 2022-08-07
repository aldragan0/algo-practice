#include <bits/stdc++.h>

using namespace std;

bool can_place(const vector<pair<int, int>>& s, int x, int y) {
    for (size_t i = 0; i < s.size(); ++i) {
        if ((abs(s[i].first - x) == abs(s[i].second - y))) return false;
    }
    return true;
}

int main() {
    int n, q, x, y;

    cin >> n >> q;
    vector<pair<int, int>> s;
    int cols[n] = { 0 };
    int rows[n] = { 0 };

    cin >> x >> y;
    s.push_back(make_pair(x, y));
    rows[x - 1] = 1;
    cols[y - 1] = 1;
    cout << "YES" << '\n';

    for (int i = 1; i < q; ++i) {
        cin >> x >> y;
        if (rows[x - 1] == 0 && cols[y - 1] == 0 && can_place(s, x, y)) {
            s.push_back(make_pair(x, y));
            rows[x - 1] = 1;
            cols[y - 1] = 1;
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}
