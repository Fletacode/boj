#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll N,S;

ll A[22];

bool visited[22];

int ans = 0;

void choice(int depth, int sum,int st,int end){

    if (depth >= end){
        //cout << sum << "\n";
        if (sum == S) ans++;
        return;
    }


    for (int i = st; i < N; i++){

        sum += A[i];
        choice(depth + 1, sum,i+1,end);
        sum -= A[i];
      
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++){
        choice(0,0,0,i);
    }
    

    cout << ans;

    
}