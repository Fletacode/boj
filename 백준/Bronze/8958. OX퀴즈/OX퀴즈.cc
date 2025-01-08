#include<bits/stdc++.h>

using namespace std;

int T;
string str;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> T;

    while(T--){
        cin >> str;

        int cnt = 0;
        int total = 0;
        bool flag = false;
        for (int i = 0; i < str.size(); i++){
            if (str[i] == 'O' && flag){
                cnt++;
                total += cnt;
            } else if (str[i] == 'O' && !flag){
                cnt = 1;
                total += cnt;
                flag = true;
            }  else if (str[i] == 'X'){
                cnt = 0;
                flag = false;
            }
        }

        //total += cnt;

        cout << total << "\n";
    }

}

