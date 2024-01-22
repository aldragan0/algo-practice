#include <bits/stdc++.h>

#define NL '\n'

typedef long long ll;
typedef long unsigned int lui;

using namespace std;

vector<string> split(const string& s, const string& delim) {
    vector<string> items;
    lui start, end;
    for(start = 0U, end = s.find(delim);
        end != string::npos; 
        start = end + delim.length(), end = s.find(delim, start)) {

        items.push_back(s.substr(start, end - start));
    }
    items.push_back(s.substr(start, end));
    return items;
}

struct Point {
    string name;
    int w;
};


struct Path {
    uint64_t v;
    int time;
    int score;
    vector<int> e;
};

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);

	string line;
    regex expr("Valve (\\w+) has flow rate=(\\d+); tunnels? leads? to valves? (((\\w+),? ?)+)");

    unordered_map<string, vector<string>> nb;
    unordered_map<int, Point> p;
    unordered_map<string, int> pos;

    int idx = 0;
	while(getline(f, line)) {
        smatch results;
        regex_search(line, results, expr);

        string name = *(results.begin() + 1);
        int weight = stoi(*(results.begin() + 2));
        vector<string> neighbors = split(*(results.begin() + 3), ", ");

        p[idx] = {name, weight};
        nb[name] = neighbors;
        pos[name] = idx;
        idx++;
	}

    int time[100][100] = {0};

    for(const auto& c: p) {
        unordered_set<int> v;
        queue<pair<int, int>> q;
        q.push({c.first, 0});

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            if(v.find(curr.first) != v.end()) continue;

            const auto el = p[curr.first];
            if(c.first != curr.first) {
                int t = ((el.w == 0) ? curr.second : curr.second + 1);
                time[c.first][curr.first] = t;
            }
            v.insert(curr.first);

            for(const auto& n : nb[p[curr.first].name]) {
                int nn = pos[n];
                if(v.find(nn) == v.end())
                    q.push({nn, curr.second + 1});
            }
        }
    }

    vector<int> cand;

    for(const auto& c : p) {
        if(c.second.w != 0) cand.push_back(c.first);
    }

    stack<Path> q;

    q.push({ 1ULL << pos["AA"], 30, 0, vector<int>{pos["AA"]} });

    Path best = {};

    while(!q.empty()) {
        // pop node
        Path curr = q.top();

        if(curr.time >= 0 && curr.score > best.score)
            best = curr;

        q.pop();
 
        // generate all the candidates moves

        for(int c : cand) {
            // if node doesn't contain candidate
            // copy the node and add it to queue

            if((curr.v & 1ULL << c) == 0) {
                Path other = curr;
                other.time -= time[other.e.back()][c];

                if(other.time < 0) continue;

                other.v |= 1ULL << c;
                other.e.push_back(c);
                other.score += p[c].w * other.time;
                q.push(other);
            }
        }

    }

    cout << best.score << NL;
}
