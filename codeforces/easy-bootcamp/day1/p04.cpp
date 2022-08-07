#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;

    cin >> a >> b;

    int diff = 0;
    for (size_t i = 0; i < a.length(); ++i) {
        diff = tolower(a[i]) - tolower(b[i]);
        if (diff != 0) break;
    }

    if (diff != 0) cout << (diff > 0 ? 1 : -1);
    else {
        cout << 0;
    }
}