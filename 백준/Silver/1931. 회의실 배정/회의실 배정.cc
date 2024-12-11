#include<bits/stdc++.h>


using namespace std;

int N;

vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++){
        int st, end;
        cin >> st >> end;
        v.push_back({st,end});
    }
    
    sort(v.begin(), v.end());
    
    
    int st = v[0].first;
    int end = v[0].second;
    
    int ans = 1;
    
    for (int i = 1; i < v.size(); i++){
        int vst = v[i].first;
        int vend = v[i].second;
        
        //추가
        if (end <= vst){
            ans += 1;
            st = vst;
            end = vend;
        } else if (end > vend){
            st = vst;
            end = vend;
        }
    }
    
    cout << ans;
    
}