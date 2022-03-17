// https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<string> temps;

void dfs(vector<int> idx_v, bool *v, int cur_idx, vector<vector<string>> tickets) {
    if(idx_v.size() == tickets.size()) {
        string answer = "ICN";
        for(int i=0; i<idx_v.size(); i++) {
            answer += tickets[idx_v[i]][1];
        }
        temps.push_back(answer);
        return;
    }

    string nxt_city = tickets[cur_idx][1];
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == nxt_city && v[i] == false) {
            idx_v.push_back(i);
            v[i] = true;
            dfs(idx_v, v, i, tickets);
            idx_v.pop_back();
            v[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == "ICN") {
            vector<int> index_vector;
            bool visited[10001] = {false, };
            visited[i] = true;
            index_vector.push_back(i);
            dfs(index_vector, visited, i, tickets);
        }
    }
    
    sort(temps.begin(), temps.end());
    string ans = temps[0];
    for(int i=0; i<ans.size(); i+=3) {
        answer.push_back(ans.substr(i, 3));
    }
    return answer;
}
