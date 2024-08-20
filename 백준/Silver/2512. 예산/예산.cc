#include<bits/stdc++.h>

using namespace std;

int N,M;

vector<int> v;

int sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int num;


    for (int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    cin >> M;

    sort(v.begin(), v.end());

    if (sum < M){
        cout << v.back();
        return 0;
    }
    
    int ans = M / N;

    for (int i = 0; i < v.size()-1; i++){
        M -= v[i];
        N--;
        //cout << M << " " << N << " " << M / N << "\n";
        ans = max({ans, M / N});
    }

    cout << ans;
    


}