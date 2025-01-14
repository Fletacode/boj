#include<bits/stdc++.h>

using namespace std;

string str1,str2;

int dp[4010][4010];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str1 >> str2;

    if (str1.size() < str2.size()){
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }

    int ans = 0;

    for (int i = 1; i <= str1.size(); i++){
        for (int j = 1; j <= str2.size(); j++){
            if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            } 
        }
    }

    cout << ans;


}