#include<bits/stdc++.h>

using namespace std;

int N;

vector<int> v;
int ans = 1e9;

int dp[5010][5010];

void init(){
    for (int i = 0; i < 5010; i++) {
        for (int j = 0; j < 5010; j++) {
            dp[i][j] = 1e9;
        }
    }
}

int go(int i, int j){

    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != 1e9){
        return dp[i][j];
    }

    int ret = 1e9;

    if (v[i] != v[j]){
        ret = min(ret, go(i + 1, j) + 1 );
        ret = min(ret, go(i, j - 1) + 1 );
    } else {
        ret = min(ret, go( i + 1, j - 1));
    }

    return dp[i][j] = ret;
}

int main(){
    cin >> N;

    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }

    init();
    
    cout << go(0, v.size() - 1);
}