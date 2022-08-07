#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long a, b;
    a = 1;
    b = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0 && i + n / i < a + b) {
            a = i;
            b = n / i;
        }
    }

    cout << 2 * (a + b);
}