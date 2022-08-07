#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int min = INT_MAX;
        int p = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] < min) {
                min = a[j];
                p = j;
            }
        }
        swap(a[i], a[p]);

        for (const auto& t : a) {
            cout << t << " ";
        }
        cout << '\n';
    }
}