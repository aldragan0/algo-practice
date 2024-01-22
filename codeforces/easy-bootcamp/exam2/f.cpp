#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int SN = sqrt(b);

    vector<int> primes;
    vector<char> is_prime(SN + 2, true);

    for(int i = 2; i <= SN; ++i) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= SN; j += i)
                is_prime[j] = false;
        }
    }

    vector<char> block(b - a + 2, true);

    for(int p : primes) {
        int m = a / p + (a % p != 0);
        int j = max(p, m) * p - a;
        for(; j <= b - a + 1; j += p) {
            block[j] = false;
        }
    }

    for(int i = a; i < 2; ++i)
        block[i] = false;

    int s = 0;

    for(int i = 0; i <= b - a; ++i) {
        s += block[i];
    }

    cout << s << NL;
}

