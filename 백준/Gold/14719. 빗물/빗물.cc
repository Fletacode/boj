#include<bits/stdc++.h>


using namespace std;


int H,W;

int A[510];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin >> H >> W;


    for (int i = 0; i < W; i++){
        cin >> A[i];
    }

    int ans = 0;

    for (int i = 1; i < W-1; i++){
        int max_val_left = 0;
        int max_val_right = 0;
        for (int j = i-1; j >= 0; j--){
            max_val_left = max(max_val_left,A[j]);
        }

        for (int k = i+1; k < W; k++){
            max_val_right = max(max_val_right, A[k]);
        }

        ans += max(min(max_val_left, max_val_right) - A[i], 0);

    }


    cout << ans;





}