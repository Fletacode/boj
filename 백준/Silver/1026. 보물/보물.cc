#include<bits/stdc++.h>

using namespace std;

int N;

vector<int> a;
vector<int> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        a.push_back(num);
    }


    for (int i = 0; i < N; i++){
        cin >> num;
        b.push_back(num);
    }    

    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(), b.end());

    int ans = 0;

    for (int i = 0; i < N; i++){
        ans += a[i] * b[i];
    }

    cout << ans;



}