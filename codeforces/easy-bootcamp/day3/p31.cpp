#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string p, h;
        vector<int> freq(26);
        cin >> p >> h;

        for (const auto& c : p) {
            ++freq[c - 'a'];
        }

        bool equal = false;

        for (int i = 0; i < (int)(h.length() - p.length()) + 1; ++i) {
            vector<int> subs_freq(26);
            equal = true;

            for (int j = 0; j < (int)p.length(); ++j) {
                ++subs_freq[h[i + j] - 'a'];
            }

            for (int k = 0; k < 26; ++k) {
                if (freq[k] != subs_freq[k]) {
                    equal = false;
                    break;
                }
            }
            if (equal) break;
        }

        if (equal) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}