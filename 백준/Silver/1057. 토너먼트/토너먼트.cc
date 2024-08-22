#include<bits/stdc++.h>


using namespace std;

int N;

int a, b;

int cal(int a){
    if (a%2 > 0){
        return a/2 + 1;
    }else{
        return a/2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    cin >> a >> b;

    int cnt = 1;

    while(cal(a) != cal(b)){

        a = cal(a);

        b = cal(b);

        cnt++;
    }

    cout << cnt;

}