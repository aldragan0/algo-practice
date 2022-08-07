#include <bits/stdc++.h>

using namespace std;

bool isVow(char c) {
    string v = "aeiouy";
    for (int i = 0; i < 6; ++i) {
        if (c == v[i]) return true;
    }
    return false;
}

int main() {
    char s[102];
    cin.getline(s, 101);

    for (int i = 0; s[i] != '\0'; ++i) {
        char c = tolower(s[i]);
        if (!isVow(c)) {
            cout << '.' << c;
        }
    }
}