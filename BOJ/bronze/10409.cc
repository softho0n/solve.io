#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, T; cin >> n >> T;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int task; cin >> task;
        v.push_back(task);
    }

    int sum = 0; int cnt = 0;
    for(int i=0; i<n; i++) {
        sum += v[i];
        if(sum > T) { break; }
        cnt += 1;
    }

    cout << cnt;
}
