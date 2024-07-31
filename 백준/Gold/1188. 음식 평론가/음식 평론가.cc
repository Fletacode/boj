#include<bits/stdc++.h>

using namespace std;

int N,M;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b,a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;


    if (N == 1){
        cout << M-1;
    }else{
        
        cout << max(M - gcd(M,N),0);
    }
    
}