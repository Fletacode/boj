#include<bits/stdc++.h>


using namespace std;


int N;

int S[50];
int P[50];



int now[50];

void rolling(){

    int temp[50];

    for (int i = 0; i < N; i++){
        temp[S[i]] = now[i];
    }

    for (int i = 0; i < N; i++){
        now[i] = temp[i];
    }
}

bool infinity_check(){
    for (int i = 0; i < N; i++){
        if (now[i] != i) return true; //무한대 반복 아님
    }

    //for (int i = 0; i < N; i++) cout << now[i] << " ";
    //cout << "\n";
    return false;
}

bool ans_check(){

    int temp[50];

    for (int i = 0; i < N; i++){
        temp[now[i]] =  i % 3;
    }

    for (int i = 0; i < N; i++){
        if (P[i] != temp[i]) return false;
    }

    return true;
}




int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    cin >> N;
   
    for (int i = 0; i < N; i++){
        cin >> P[i];
       
        now[i] = i;
    }


    for (int i = 0; i < N; i++){
        cin >> S[i];
    }

    int ans = 0;

    if (ans_check()){
        cout << ans;
        return 0;
    }


    while(true){
        
        ans++;
        rolling();
        /*
        if (ans == 59){
            for (int i = 0; i < N; i++){
                cout << now[i] << " ";
            }
            cout << "\n";
        }
        */

        if (ans_check()){
            cout << ans;
            return 0;
        }

        if (!infinity_check()){
            cout << -1;
            return 0;
        }

    }


}