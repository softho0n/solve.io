#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> temps;
bool words_compare(string a, string b) {
    int a_len = a.size();
    int b_len = b.size();
    int len = min(a_len, b_len);
    int diff_cnt = 0;
    
	for (int i=0; i<len; i++) {
        if(a[i] != b[i]) diff_cnt += 1;
    }
    
    if (diff_cnt == 1) {
        return true;
    }
    return false;
}

void dfs(string begin, string input, string target, vector<string> words, int temp, bool *v, string ans) {
    if (words_compare(begin, input) && input == target) {
        temps.push_back(temp);
        return;
    }
    
    if (words_compare(begin, input)) {
        for(int i=0; i<words.size(); i++) {
            if(v[i] == false) {
                v[i] = true;
                dfs(input, words[i], target, words, temp + 1, v, ans + words[i]);
                v[i] = false;
            }
        }
    }
    else {
        return;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool flag = false;
    for (string str: words) {
        if (str == target) flag = true;
    }
    
    if (!flag) return 0;
    
    for(int i=0; i<words.size(); i++) {
        bool visited[1001] = {false, };
        visited[i] = true;
        string answer = begin + words[i];
        dfs(begin, words[i], target, words, 1, visited, answer);
    }
    
    sort(temps.begin(), temps.end());
    answer = temps[0];
    return answer;
}
