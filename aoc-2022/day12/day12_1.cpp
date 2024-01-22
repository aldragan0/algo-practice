#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

struct Cell {
    float f;
    pair<int, int> parent;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isValid(vector<vector<char>> a, int i, int j) {
    return i >= 0 && i < a.size()
        && j >= 0 && j < a[0].size();
}

pair<int, int> getPos(vector<vector<char>> a, char value) {
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a[0].size(); ++j) {
            if(a[i][j] == value) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);

    string line;
    vector<vector<char>> a;

    while(getline(file, line)) {
        vector<char> temp;
        for(int i = 0; i < line.size(); ++i) {
            temp.push_back(line[i]);
        }
        a.push_back(temp);
    }

    const auto startPos = getPos(a, 'S');
    const auto endPos = getPos(a, 'E');

    a[startPos.first][startPos.second] = 'a';
    a[endPos.first][endPos.second] = 'z';

    queue<tuple<float, int, int>> q;
    q.emplace(0.0, startPos.first, startPos.second);

    vector<vector<bool>> v(a.size(), vector<bool>(a[0].size(), false));
    vector<vector<Cell>> map(a.size(), vector<Cell>(a[0].size(), Cell()));

    while(!q.empty()) {
        const auto curr = q.front();
        q.pop();

        int ci = get<1>(curr), cj = get<2>(curr);

        if(v[ci][cj]) continue;
        v[ci][cj] = true;

        for(int i = 0; i < 4; ++i) {
            int ni = ci + dx[i], nj = cj + dy[i];
            if(isValid(a, ni, nj) && (a[ni][nj] - a[ci][cj]) <= 1) {
                if(!v[ni][nj]) {
                    float nf = map[ci][cj].f + 1;
                    q.emplace(nf, ni, nj);
                    if(map[ni][nj].f == 0 || map[ni][nj].f > nf) {
                        map[ni][nj].f = nf;
                        map[ni][nj].parent = make_pair(ci, cj);
                    }
                }
            }
        }
    }


    cout << map[endPos.first][endPos.second].f;
}
