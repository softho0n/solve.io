#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int total_second = 0;
int fish_eat_cnt = 0;
int m[25][25];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int s_y, s_x, s_size;

void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> m[i][j];
            if(m[i][j] == 9) {
                s_y = i;
                s_x = j;
                s_size = 2;
            }
        }
    }
}

bool compare(pair< int, pair <int, int> > a, pair< int, pair <int, int> > b) {
    if(a.first < b.first) {
        return true;
    }
    else if(a.first == b.first) {
        if(a.second.first < b.second.first) {
            return true;
        }
        else if(a.second.first == b.second.first) {
            if(a.second.second < b.second.second) {
                return true;
            }
        }
    }
    return false;
}

bool bfs() {
    bool visited[25][25] = {false, };
    bool canEat[25][25] = {false, };
    int marking[25][25] = {0, };
    queue< pair<int, int> > q; q.push(make_pair(s_y, s_x));
    visited[s_y][s_x] = true;

    while(!q.empty()) {
        pair< int, int > pq = q.front(); q.pop();
        int cy = pq.first; int cx = pq.second;

        for(int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] == true) continue;

            if(s_size >= m[ny][nx]) {
                if(s_size > m[ny][nx] && (m[ny][nx] > 0 && m[ny][nx] < 9)) {
                    canEat[ny][nx] = true;
                }
                visited[ny][nx] = true;
                marking[ny][nx] = marking[cy][cx] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    vector< pair< int, pair< int, int > > > all_cases;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(canEat[i][j]) {
                all_cases.push_back(make_pair(marking[i][j], make_pair(i, j)));
            }
        }
    }
    if(all_cases.size() == 0) return false;
    sort(all_cases.begin(), all_cases.end(), compare);
    
    m[s_y][s_x] = 0;
    s_y = all_cases[0].second.first;
    s_x = all_cases[0].second.second;
    m[s_y][s_x]= 9;
    
    total_second += all_cases[0].first;
    fish_eat_cnt += 1;

    return true;
}

void solution() {
    while(1) {
        if(!bfs()) break;
        if(fish_eat_cnt >= s_size) {
            s_size += 1;
            fish_eat_cnt = 0;
        }
    }
    cout << total_second;
}

void solve() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
}

int main() {
    solve();
}