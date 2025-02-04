#include <bits/stdc++.h>

using namespace std;


map<string,int> m;

bool check(vector<string> &phone_book){
    
    for (string str : phone_book) {
        for (int i = 1; i < str.size(); i++){
            string temp = str.substr(0,i);
            if (m[temp] > 0) return false;
        }
    }
    
    return true;
}


bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (string str : phone_book) {
        m[str] += 1;
    }
    
        
    return check(phone_book);
}