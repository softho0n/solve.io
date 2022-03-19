#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a, b, c;
    a = b = c = 0;
    
    for(int i=0; i<answers.size(); i+=5) {
        for(int j=0; j<5; j++) {
            if(j + 1 == answers[i+j]) a += 1;
        }
    }
    
    bool switching = false;
    for(int i=0; i<answers.size(); i+=4) {
        int arr[5];
        if(!switching) {
            arr[0] = 2;
            arr[1] = 1;
            arr[2] = 2;
            arr[3] = 3;
        }
        else {
            arr[0] = 2;
            arr[1] = 4;
            arr[2] = 2;
            arr[3] = 5;
        }
        for(int j=0; j<4; j++) {
            if(arr[j] == answers[i + j]) b += 1;
        }
        switching = !switching;
    }
    
    for(int i=0; i<answers.size(); i+=10) {
        int arr[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        for(int j=0; j<10; j++) {
            if(arr[j] == answers[i + j]) c += 1;
        }
    }
    
    int m = max(a, max(b, c));
    if(m == a) {
        answer.push_back(1);
    }
    if(m == b) {
        answer.push_back(2);
    }
    if(m == c) {
        answer.push_back(3);
    }
    return answer;
}
