#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ns = 0, l = 0, r = 0;
    cin >> n;

    bool inc = false;
    int a[n] = { 0 };
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            if ((l == 0 && r == 0) || inc == true) {
                ++ns;
                l = r = i;
                inc = false;
            }
            ++r;
        }
        else {
            inc = true;
        }
    }

    if ((l > 0 && a[l - 1] > a[r])
        || (r < n - 1 && a[l] > a[r + 1])
        || ns > 1)
        cout << "no";
    else {
        cout << "yes\n";
        cout << l + 1 << " " << r + 1;
    }
}