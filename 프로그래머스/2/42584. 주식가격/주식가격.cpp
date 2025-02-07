#include <bits/stdc++.h>

using namespace std;

stack<pair<int,int>> st;

vector<int> solution(vector<int> prices) {
    vector<int> ans(prices.size(),0);
    
    for (int i = 0; i < prices.size() - 1 ; i++) {
        if (st.empty()) st.push({i,prices[i]});
        else {
            if (st.top().second > prices[i]) {
                while(!st.empty() && st.top().second > prices[i]) {
                    int idx = st.top().first;
                    //cout << idx << " " << i;
                    ans[idx] = i - idx;
                    st.pop();
                }
                st.push({i,prices[i]});
            } else {
                //cout << i << " " << prices[i] << "\n";
                st.push({i,prices[i]});
            }
            
            
        }
    }
    
 
    
    while(!st.empty()) {
        pair<int,int> p = st.top();
        //cout << p.first << "\n";
        ans[p.first] = prices.size() - 1 - p.first;
        st.pop();
    }
    
    
    return ans;
}