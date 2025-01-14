#include<bits/stdc++.h>

using namespace std;

int N;

int A[1000010];
int status[1000010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    int ans = 0;

    for (int i = 0; i < N; i++){
        int now = A[i];
        if (status[now] == 0){
            ans += 1;
            status[now-1]++;
        } else {
            status[now]--;
            status[now-1]++;
        }
    }

    cout << ans;
}