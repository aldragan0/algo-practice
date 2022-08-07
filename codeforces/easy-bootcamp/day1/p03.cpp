#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int len = a[i].length();
        if (len > 10) {
            cout << a[i][0] << len - 2 << a[i][len - 1] << '\n';
        }
        else {
            cout << a[i] << '\n';
        }
    }
}