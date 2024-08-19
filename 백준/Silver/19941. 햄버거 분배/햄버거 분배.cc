#include<bits/stdc++.h>


using namespace std;

int N,K;

string input;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    cin >> input;

    int ans = 0;

    for (int i = 0; i < input.size(); i++){
        if (input[i] != 'P') continue;

        for (int j = i-K; j <= i+K; j++){
            if (j > N || j < 0) continue;

            if (input[j] == 'H'){
                input[j] = '-';
                ans++;
                break;
            }

            if (input[j] == 'H'){
                input[j] = '-';
                ans++;
                break;
            }

        }
    }

    cout << ans;

    //cout << input;
   


}