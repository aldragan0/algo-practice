#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

struct Point {
    int x;
    int y;
    bool valid;
};

bool canMove(int a[1000][1000], Point t, Point dir) {
    return a[t.x + dir.x][t.y + dir.y] == 0;
}

void move(Point& t, Point dir) {
    t.x += dir.x;
    t.y += dir.y;
}

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);

    int a[1000][1000] = { 0 };

    string line;
    while(getline(f, line)) {
        stringstream ss(line);
        int x, y, ox = 0, oy = 0;
        char c;
        string s;

        while(ss >> y >> c >> x) {
            if(ss >> s) {}
            if(ox == oy && oy == 0) {
                ox = x;
                oy = y;
                continue;
            }

            int mx = max(x, ox);
            int my = max(y, oy);
            for(int i = min(x, ox); i <= mx; ++i)
                a[i][y] = 1;

            for(int i = min(y, oy); i <= my; ++i)
                a[x][i] = 1;

            ox = x;
            oy = y;
        }
    }

    int m = 0;
    for(int i = 0; i < 1000; ++i) {
        for(int j = 0; j < 1000; ++j) {
            if(a[i][j] == 1) m = i;
        }
    }

    for(int j = 0; j < 1000; ++j) {
        a[m + 2][j] = 1;
    }

    Point down = {1, 0, true};
    Point left = {1, -1, true};
    Point right = {1, 1, true};

    int cnt = 0;
    while(true) {
        Point p = {0, 500, true};
        while(true) {
            if(canMove(a, p, down)) move(p, down);
            else if(canMove(a, p, left)) move(p, left);
            else if(canMove(a, p, right)) move(p, right);
            else if(a[p.x][p.y] == 0) {
                a[p.x][p.y] = 1;
                ++cnt;
                break;
            }
            else break;
        }
        if(p.x == 0 && p.y == 500) break;
    }

    cout << cnt << NL;
}
