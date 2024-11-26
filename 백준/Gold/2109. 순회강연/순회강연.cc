#include<bits/stdc++.h>

using namespace std;

int n,p,d;

int A[10001];

struct cmp{
    bool operator()(pair<int,int> p1 ,pair<int,int> p2){
        if (p1.second > p2.second) return 1;
        else if (p1.second < p2.second){
            return 0;
        }else{
            if (p1.first > p2.first) return 1;
            else{
                return 0;
            }
    }
    }

};

bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second < p2.second) return 1;
    else if (p1.second > p2.second){
        return 0;
    }else{
        if (p1.first > p1.first) return 1;
        else{
            return 0;
        }
    }
}


priority_queue<int ,vector<int>, greater<int> > pq;

vector<pair<int,int>> v;

int main(){
    cin >> n;

    while (n--){
        cin >> p >> d;
        v.push_back({d,p});
    }


    sort(v.begin(),v.end());
    

    for (int i = 0; i < v.size(); i++){
        pq.push(v[i].second);
        if (pq.size() > v[i].first){
            pq.pop();
        }
    }
    int ans = 0;
    while (!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
    

    

    
    

}