#include<bits/stdc++.h>

using namespace std;

int n,k;

int coins[101];
int DP[10010];

int main(){
    cin >> n >> k;  

   

    for (int i = 1; i <= n; i++){
        cin >> coins[i];
        
    }
    DP[0] = 1;
    
    
    for (int i = 1; i <= n; i++){
        for (int j = coins[i]; j <= k; j++){
            
            DP[j] +=  DP[j- coins[i]];
            
        }
    }

    //for (int i = 1; i <= k; i++) cout << DP[i] << " ";

    cout << DP[k];
    

}