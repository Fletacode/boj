#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<pair<ll,ll> > v;

vector<pair<ll,ll> > input;

bool visited[11];

int N;

ll ans = 1e10;

ll cal(){
    if (v.empty()) return 1e10;

    ll a = 1;
    for (int i = 0; i < v.size(); i++){
        a *= v[i].first;
    }
    ll b = 0;
    for (int i = 0; i < v.size(); i++){
        b += v[i].second;
    }
    return abs(a-b);
}

void choice(int depth){

    ans = min(ans, cal());

    /*
    for (int i = 0; i < N; i++){
        cout << visited[i] << " ";
    }
    cout << "\n";
    */

    if (depth >= N) return;

    

    for (int i = 0; i < N; i++){
        if (visited[i]) continue;

        visited[i] = true;
        v.push_back({input[i].first,input[i].second});
        choice(depth + 1);
        v.pop_back();
        visited[i] = false;
    }

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    ll a,b;

    for (int i = 0; i < N; i++){
        cin >> a >> b;
        input.push_back({a,b});
    }

    choice(0);

    cout << ans;

}

