#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long ll;

using namespace std;
 

struct cmp{
    bool operator()(ll n1, ll n2){
        return n1 < n2;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    int M,V;

    cin >> N >> K;

    pair<ll,ll> jew[N];
    ll bag[K];
    priority_queue<ll, vector<ll>, cmp> pq;
    

    for (int i = 0; i < N; i++){
        cin >> M >> V;
        jew[i] = make_pair(M,V);

    }

    for (int i = 0; i < K; i++){
        cin >> bag[i];
    }

    sort(jew,jew + N);
    sort(bag,bag+ K);

    int idx = 0;
    ll ans = 0;

    for (int i = 0; i < K; i++){
        while (idx < N && jew[idx].first <= bag[i]){
            pq.push(jew[idx].second);
            idx++;
        }
        if (!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    
}