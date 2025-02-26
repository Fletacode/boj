#include <bits/stdc++.h>

using namespace std;

set<string> s;

bool solution(vector<string> book) {
    bool answer = true;
    
    for (int i  =0; i < book.size(); i++) {
        s.insert(book[i]);
    }
    
    for (int i  =0; i < book.size(); i++) {
        for (int j = 0; j < book[i].size() - 1; j++) {
            string temp = book[i].substr(0, j + 1);
            if (s.find(temp) != s.end()){
                return false;
            }
        }
    }
    
    
    return true;
}