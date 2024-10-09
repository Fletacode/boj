#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int N;

int col[16];

int ans = 0;

bool check(int col_index){

    for (int i = 1; i < col_index; i++){
        //같은 행이거나 대각선에 있으면 안됌
        if (col[col_index] == col[i] || col_index - i == abs( col[col_index] - col[i]) ){
            return false;
        }
    }
    return true;

}


void nq (int col_index){
    if (col_index == N+1){
        ans++;
        return;
    }

    for (int row = 1; row <= N; row++){
        col[col_index] = row;
        if (check(col_index)){
            nq(col_index + 1);
        }
    }

}



int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    nq(1);

    cout << ans;
    

}