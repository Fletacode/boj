#include<bits/stdc++.h>

using namespace std;

int N;

vector<pair<int,int>> v;

vector<int> vMinS;
vector<int> vMaxS;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int a,b;
    for (int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back({a-b,a+b});
        vMinS.push_back(a-b);
        vMaxS.push_back(a+b);
    }

    sort(vMinS.begin(), vMinS.end());
    sort(vMaxS.begin(), vMaxS.end());


    for (int i = 0; i < v.size(); i++){

        int min_v = v[i].first;
        int max_v = v[i].second;

        int min_idx = lower_bound(vMaxS.begin(), vMaxS.end(), min_v) - vMaxS.begin();

        int max_idx = upper_bound(vMinS.begin(), vMinS.end(), max_v) - vMinS.begin();


        cout << min_idx + 1 << " " << max_idx<< "\n";

    }
    

}   