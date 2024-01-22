#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

/*
Improved sieve:

- prime check only the odd nums (all evens are multiples of 2)
- compute primes until sqrt(n)
*/

int main() {
    ll n;
    cin >> n;

    vector<bool> prime(n / 2 + 1, true);

    prime[0] = false;
    for(ll i = 3; i * i <= n; i += 2) {
        if(prime[(i - 1) / 2]) {
            for(ll j = i * i; j <= n; j += i) {
                if(j % 2 != 0) {
                    prime[(j - 1) / 2] = false;
                }
            }
        }
    }

    int s = 1; // include 2
    for(int i = 0; i < n / 2; ++i) {
        s += prime[i];
    }

    cout << s << NL;
}

