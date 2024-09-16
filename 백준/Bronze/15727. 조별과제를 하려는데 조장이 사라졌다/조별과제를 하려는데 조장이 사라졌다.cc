#include<bits/stdc++.h>

using namespace std;

int L;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> L;

    if (L % 5){
        cout << L / 5 + 1;
    }else{
        cout << L / 5;
    }



}