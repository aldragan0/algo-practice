#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt[3]{ 0, 0, 0 };

    char s[101];
    cin.getline(s, 100);

    int n = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] != '+') {
            ++n;
            ++cnt[s[i] - '1'];
        }
    }

    int i = 0;
    while (i < 3) {
        while (cnt[i] > 0) {
            cout << i + 1;
            --n;
            if (n > 0) {
                cout << '+';
            }
            --cnt[i];
        }
        ++i;
    }
}