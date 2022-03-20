#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
vector<int> v[3001];
bool cycle[3001] = {false, };
bool visited[3001] = {false, };

bool dfs(int start, int here, bool *visited, int line) {
    if (start == here && line >= 2) {
        return true;
    }

    visited[here] = true;
    for (int i=0; i<v[here].size(); i++) {
        int nxt = v[here][i];

        if (visited[nxt] == false) {
            if(dfs(start, nxt, visited, line + 1)) {
                return true;
            }
        }
        else {
            if (nxt == start && line >= 2) {
                if(dfs(start, nxt, visited, line)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void make_cycle_array() {
    for(int i=1; i<=n; i++) {
        memset(visited, false, sizeof(visited));
        if(dfs(i, i, visited, 0)) {
            cycle[i] = true;
        }
    }
}

void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    make_cycle_array();
}

int distance(int node) {
    memset(visited, false, sizeof(visited));
    queue< pair<int, int> > q; q.push(make_pair(node, 0)); visited[node] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cycle[cur]) {
            return cnt;
        }

        for (int i=0; i<v[cur].size(); i++) {
            int nxt = v[cur][i];
            if (!visited[nxt]) {
                q.push(make_pair(nxt, cnt + 1));
                visited[nxt] = true;
            }
        }
    }
    return -1;
}

void solution() {
    for(int i=1; i<=n; i++) {
        cout << distance(i) << " ";
    }
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
}
