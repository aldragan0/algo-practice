#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min = INT_MAX;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (min > c) {
            min = c;
            p = i;
        }
    }

    cout << p;
}