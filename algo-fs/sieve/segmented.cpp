#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

/*
 * Segmented sieve:
 *   1. precompute all primes [1..sqrt(n)]
 *   2. segment the interval [1..n] in blocks of size S
 *   3. sieve each block using the precomputed primes
 */

int main() {
    const int S = 10000;
    int n;
    cin >> n;

    int sn = sqrt(n);
    vector<int> primes;
    vector<char> prime(sqrt(n) + 1, true);

    for(int i = 2; i <= sn; i++) {
        if(prime[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= sn; j += i)
                prime[j] = false;
        }
    }

    int s = 0;
    vector<char> block(S);
    for(int k = 0; k * S <= n; ++k) {
        fill(block.begin(), block.end(), 1);
        int start = k * S;
        for(int p : primes) {
            // m smallest num. | m * p >= k * S
            // convert m * p to zero-based index
            int m = start / p + (start % p != 0);
            int j = max(m, p) * p - start;
            for(; j < S; j += p)
                block[j] = 0;
        }

        if(k == 0) {
            block[0] = block[1] = 0;
        }
        for(int i = 0; i < S && start + i <= n; ++i) {
            s += block[i];
        }
    }

    cout << s << NL;

}

