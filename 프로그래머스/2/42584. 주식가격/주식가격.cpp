#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans;
    
    for (int i = 0; i < prices.size() - 1; i++) {
        
        int j = i + 1;
        
        int now = prices[i];
        
        while (now <= prices[j]) {
            if (j >= prices.size() - 1) break;
            j++;
        }
        
        ans.push_back(j-i);
        
    }
    
    ans.push_back(0);
    
    return ans;
}