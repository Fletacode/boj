#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    
    int before = arr[0];
    ans.push_back(arr[0]);
    
    for (int i = 1; i < arr.size(); i++) {
        if (before == arr[i]) continue;
        
        ans.push_back(arr[i]);
        before = arr[i];
    }

    return ans;
}