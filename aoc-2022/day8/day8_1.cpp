#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

int maxRowEl(vector<int> a, int s, int e) {
    int m = 0;
    for(int i = s; i < e; ++i)
        if(m < a[i]) m = a[i];
    return m;
}

int maxColEl(vector<vector<int>> a, int colIdx, int s, int e) {
    int m = 0;
    for(int i = s; i < e; ++i)
        if(m < a[i][colIdx]) m = a[i][colIdx];
    return m;
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	string line;
    vector<vector<int>> map;

	while(getline(f, line)) {
        vector<int> l;
        for(const auto ch : line) {
            l.push_back(ch - '0');
        }
        map.push_back(l);
	}

    vector<vector<int>> hmap(map.size(), vector<int>(map.size(), 0));

    for(int i = 1; i < map.size() - 1; ++i) {
        for(int j = 1; j < map[0].size() - 1; ++j) {
            int mrs = maxRowEl(map[i], 0, j);
            int mre = maxRowEl(map[i], j + 1, map.size());
            int mcs = maxColEl(map, j, 0, i);
            int mce = maxColEl(map, j, i + 1, map[i].size());
            hmap[i][j] = min({mrs, mre, mcs, mce});
        }
    }

    int result = 4 * map.size() - 4;


    for(int i = 1; i < map.size() - 1; ++i) {
        for(int j = 1; j < map[0].size() - 1; ++j) {
            if(map[i][j] > hmap[i][j]) ++result;
        }
    }

    cout << result << NL;
}
