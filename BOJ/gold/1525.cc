#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

string Start, End;

void input() {
    End = "123456780";
    Start = "";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int tmp; cin >> tmp;
            char c = tmp + '0';
            Start = Start + c;
        }
    }
}

void solution() {
    queue< pair< string, int > > q; set<string> v;
    q.push(make_pair(Start, 0)); v.insert(Start);
    bool flag = false;

    while(!q.empty()) {
        string cur_s = q.front().first; int cur_point = q.front().second; q.pop();
        int cur_y = cur_s.find('0') / 3; int cur_x = cur_s.find('0') % 3;
        int cur_idx = cur_s.find('0');

        if(cur_s == End) {
            cout << cur_point;
            flag = true;
            break;
        }

        for(int i=0; i<4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < 3 && nx < 3) {
                int nidx = 3 * ny + nx;
                string cur = cur_s;
                swap(cur[nidx], cur[cur_idx]);
                if(v.find(cur) == v.end()) {
                    v.insert(cur);
                    q.push(make_pair(cur, cur_point + 1));
                }
            }
        }
    }

    if(!flag) {
        cout << -1;
    }
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
}
