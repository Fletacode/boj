#include <bits/stdc++.h>

using namespace std;



bool solution(vector<string> book) {
    bool answer = true;
    
    sort(book.begin(), book.end());
        
    
    
    for (int i = 0; i < book.size() - 1; i++) {
        if (book[i] == book[i+1].substr(0,book[i].size())) {
            return false;
        }
    }
    
    
    return true;
}