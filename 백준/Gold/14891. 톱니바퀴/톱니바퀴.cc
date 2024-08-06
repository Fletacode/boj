#include<bits/stdc++.h>


using namespace std;

deque<int> v[4];
int K;

int check[4]; //0 안돌림 1 시계 -1 반시계


void check_roll(int idx, int dir){

    memset(check, 0, sizeof(check));

    check[idx] = dir;

    int dir_temp = dir;
    for (int i = idx; i < 3; i++){
        if (v[i][2] != v[i+1][6]){
            check[i+1] = dir_temp * -1;
            dir_temp *= -1;
        }else{
            break;
        }
    }
    

    dir_temp = dir;
    for (int i = idx; i > 0; i--){
        if (v[i][6] != v[i-1][2]){
            check[i-1] = dir_temp * -1;
            dir_temp *= -1;
        }else{
            break;
        }
    }

}

void roll(){

    for (int i = 0; i < 4; i++){
        if (check[i] == 1){
            v[i].push_front(v[i].back());
            v[i].pop_back();
        }else if (check[i] == -1){
            v[i].push_back(v[i].front());
            v[i].pop_front();
        }
    }

}

int cal_ans(){

    int ans = 0;
    int score = 1;

    for (int i = 0; i < 4; i++){
        if (v[i][0]){
            ans += score;
        }
        score *= 2;
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string input;
    for (int i = 0; i < 4; i++){
        cin >> input;
        for (int j = 0; j < input.size(); j++){
            v[i].push_back(input[j] - '0');
        }
    }

    cin >> K;

    int idx,dir;
    while(K--){
        cin >>  idx >> dir;
        check_roll(idx - 1, dir);
        roll();
    }

    cout << cal_ans();


}