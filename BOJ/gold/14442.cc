#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[1001][1001][11] = {false, };
int M[1001][1001] = {0, };

void input() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &M[i][j]);
        }
    }
}

void solution() {
    queue< pair< pair< int, int >, pair< int, int > > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(1, 0))); visited[0][0][0] = true;
    while(!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cCnt = q.front().second.first;
        int cWall = q.front().second.second;
        q.pop();

        if (cy == n-1 && cx == m-1) {
            cout << cCnt;
            return;
        }

        for(int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nx >= 0 && ny >= 0 && ny < n && nx < m) {
                if(M[ny][nx] == 0 && !visited[ny][nx][cWall]) {
                    visited[ny][nx][cWall] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(cCnt + 1, cWall)));
                }
                else if(M[ny][nx] == 1 && !visited[ny][nx][cWall] && cWall < k) {
                    visited[ny][nx][cWall + 1] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(cCnt + 1, cWall + 1)));
                }
            }
        }
    }
    cout << -1;
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
}
