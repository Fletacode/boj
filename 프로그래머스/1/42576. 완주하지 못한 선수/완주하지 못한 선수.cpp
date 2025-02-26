#include <bits/stdc++.h>

using namespace std;


map<string,int> m;

string solution(vector<string> part, vector<string> com) {
    string answer = "";
    
    for (string name : part) {
        m[name] = m[name] + 1;   
    }
    
    for (string name : com) {
        m[name] = m[name] - 1;
    }
    
    for (auto iter : m) {
        if (iter.second == 1){
            return iter.first;
        }
    }

    
    return answer;
}