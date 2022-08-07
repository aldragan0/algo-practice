#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    int a = 0;
    for (int c = n % 10; n != 0; n /= 10, c = n % 10) {
        if (c == 4 || c == 7)
            ++a;
    }
    cout << (a == 4 || a == 7 ? "YES" : "NO");
}