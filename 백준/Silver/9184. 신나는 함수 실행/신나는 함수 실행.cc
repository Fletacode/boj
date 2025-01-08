#include<bits/stdc++.h>

using namespace std;

int a,b,c;

int dp[21][21][21];

int go(int a,int b, int c){

    if (a <= 0 || b <= 0 || c <= 0) return 1;

    else if (a > 20 || b > 20 || c > 20){
        return dp[20][20][20] = go(20,20,20);
    }

    else if (dp[a][b][c] != 0){
        return dp[a][b][c];
    }

    else if (a < b && b < c){
        return dp[a][b][c] = 
        go(a,b,c-1) + go(a,b-1,c-1) - go(a,b-1, c);
    }

    else{
        return dp[a][b][c] = 
        go(a-1,b,c) + go(a-1,b-1,c) + go(a-1,b,c-1) - go(a-1,b-1,c-1);
    }

}

void print_ans(int a,int b,int c,int ans){

    cout << "w(" + to_string(a) + ", " + to_string(b) +", " + to_string(c) + ") = " + to_string(ans) << "\n";

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true){
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) return 0;

        int ans =  go(a,b,c);

        print_ans(a,b,c,ans);

    }

}

