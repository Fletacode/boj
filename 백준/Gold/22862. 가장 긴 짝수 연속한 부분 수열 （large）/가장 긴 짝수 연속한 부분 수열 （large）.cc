#include<bits/stdc++.h>

using namespace std;

int N,K;

int A[1000010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    int num;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    int hal = 0;
    int zan = 0;
    int ans = 0;

    int i = 0;
    int j = 1;

    if (A[0] % 2 == 0) zan++;
    else{
        hal++;
    }


    while(j < N){
        if (A[j] % 2 == 0){
            zan++;
        }else{
            hal++;
        }
           
        while(hal > K && i < j){
            if (A[i] % 2 != 0) hal--;
            else{
                zan--;
            }
            i++;
            
        }
    
        j++;
        
        ans = max(ans,zan);
    }

    ans = max(ans,zan);

    cout << ans;

    

   

    



}