#include <bits/stdc++.h>

using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

stack<char> st;

bool solution(string s) {
    bool answer = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (!st.empty() && st.top() == '('){
                st.pop();
            } else {
                return false;
            }
        } else {
            st.push(s[i]);
        }
    }
    
    if (!st.empty()) {
        return false;
    }
    
    return true;
}