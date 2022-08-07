#include <bits/stdc++.h>

using namespace std;

int main() {
    char a[100], ch;

    cin.getline(a, 100);

    ch = 1;
    int i = 0;
    while (a[i] != '\0') {
        if (ch == 7) {
            break;
        }
        if (a[i] == a[i + 1]) {
            ch += 1;
        }
        else {
            ch = 1;
        }
        ++i;
    }

    cout << (ch == 7 ? "YES" : "NO");
}
