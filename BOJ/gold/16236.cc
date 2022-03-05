#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int map[21][21];

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

int fish_count() {
    int cnt = 0;
    for(int i=0; i<n; )
}

void solution() {
    
}

void solve() {
    input();
    solution();
}

int main() {
    solve();
}
