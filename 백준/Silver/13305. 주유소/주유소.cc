#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;
ll dis[100010];
ll val[100010];

ll DP[100010];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i < N; i++){
        cin  >> dis[i];
    }
    for (int i = 0; i < N; i++){
        cin >> val[i];
    }

    DP[1] = dis[1] * val[0];

    for (int i = 2; i < N; i++){
        DP[i] = min(DP[i-1] + (val[i-1] * dis[i]),
                    DP[i-1] + (val[i-2] * dis[i]) );
    }

    cout << DP[N-1];

}