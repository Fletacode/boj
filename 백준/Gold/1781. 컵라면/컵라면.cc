#include<bits/stdc++.h>

using namespace std;

int N;

vector<pair<int,int>> v; // 데드라인, 컵라면
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;


int main(){

    cin >> N;

    for (int i = 0; i < N; i++){
        int d,n;
        cin >> d >> n;
        v.push_back({d,n});
    }    

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++){
        pq.push({v[i].second, v[i].first});

        if (pq.size() > v[i].first){
            pq.pop();
        }

    }

    int ans = 0;

    while(!pq.empty()){
        ans += pq.top().first;
        pq.pop();
    }

    cout << ans;
    
}