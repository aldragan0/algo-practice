#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;

using namespace std;

int minRowCnt(vector<int> a, int s, int e, int el) {
    int cnt = 0;
    if (s <= e) {
        for(int i = s; i < e; ++i) {
            if(el <= a[i]) {
                ++cnt;
                break;
            }
            ++cnt;
        }
    } else {
        for(int i = s - 1; i >= e; --i) {
            if(el <= a[i]) {
                ++cnt;
                break;
            }
            ++cnt;
        }
    }
    return cnt;
}

int minColCnt(vector<vector<int>> a, int colIdx, int s, int e, int el) {
    int cnt = 0;
    if (s <= e) {
        for(int i = s; i < e; ++i) {
            if(el <= a[i][colIdx]) {
                ++cnt;
                break;
            }
            ++cnt;
        }
    } else {
        for(int i = s - 1; i >= e; --i) {
            if(el <= a[i][colIdx]) {
                ++cnt;
                break;
            }
            ++cnt;
        }
    }
    return cnt;
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

    int maxVal = 0;

    for(int i = 1; i < map.size() - 1; ++i) {
        for(int j = 1; j < map[0].size() - 1; ++j) {
            int el = map[i][j];
            int crs = minRowCnt(map[i], j, 0, el);
            int cre = minRowCnt(map[i], j + 1, map.size(), el);
            int ccs = minColCnt(map, j, i, 0, el);
            int cce = minColCnt(map, j, i + 1, map[i].size(), el);
            int val = crs * cre * ccs * cce;
            if(maxVal < val) maxVal = val;
        }
    }

    cout << maxVal << NL;

}
