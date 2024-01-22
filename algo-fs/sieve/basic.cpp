#include <bits/stdc++.h>

#define NL '\n'
#define MOD 1000000007

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<bool> p(n + 1, true);

    p[0] = p[1] = false;
    for(ll i = 2; i <= n; i++) {
        if(p[i])
            for(ll j = i * i; j <= n; j += i) {
                p[j] = false;
            }
    }

    int s = 0;
    for(int i = 0; i < n; ++i)
        s += p[i];

    cout << s << NL;

}

