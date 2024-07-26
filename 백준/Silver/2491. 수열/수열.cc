#include<bits/stdc++.h>

using namespace std;

int N;
int A[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int ans = 1;
    
    //가장 긴 부분 수열
    int ans_l = 1;
    for (int i = 1; i < N; i++){
        if (A[i] < A[i-1]) ans_l = 1;
        else{
            ans_l++;
        }
        ans = max(ans, ans_l);
    }

    int ans_s = 1;
    for (int i = 1; i < N; i++){
        if (A[i] > A[i-1]) ans_s = 1;
        else{
            ans_s++;
        }
        ans = max(ans,ans_s);
    }

    cout << ans;

}