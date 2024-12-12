#include<bits/stdc++.h>

using namespace std;


int N;
vector<int> v;

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    int cnt = 0;
    for (int i =0; i < N; i++){
        cnt += v[i];
        ans += cnt;
    }
    
    cout << ans;
}