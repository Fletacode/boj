#include<bits/stdc++.h>


using namespace std;

int N,K;

vector<int> v;

int main(){
    
    cin >> N >> K;
        
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int ans = 0;
    
    for (int i = N-1; i >= 0; i--){
       if (K / v[i] > 0){
           ans += K / v[i];
           K %= v[i];
       }
    }
    cout << ans;
}