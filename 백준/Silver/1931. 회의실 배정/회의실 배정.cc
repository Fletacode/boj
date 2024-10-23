#include<bits/stdc++.h>


using namespace std;

int N;

vector<pair<int,int>> v;

bool compare(pair<int,int> a,pair<int,int> b){
    if (a.first < b.first) return 1;
    else{
        if (a.first == b.first){
            if (a.second < b.second){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int a,b;
    for (int i = 0 ; i < N; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(),compare);

    int cnt = 0;
    int st = v[0].first;
    int end = v[0].second;
    cnt++;


    for (int i = 1; i < v.size(); i++){
        //교체
        if (v[i].second < end){
            if (v[i].second - v[i].first < end-st
             && end >= v[i].second){
                st = v[i].first;
                end = v[i].second; 
                continue;
             }
            
        }

        if (end <= v[i].first){
            cnt++;
            st = v[i].first;
            end = v[i].second;
        }
    }

    cout << cnt;
}