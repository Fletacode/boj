#include<bits/stdc++.h>


using namespace std;


int A[10][10];

int ans[10][10];

string str;

vector<pair<int,int>> v;

bool flag = false;

void print_ans() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}


bool row_col_check(int y, int x, int num){
    int temp_y = y;

    while(temp_y > 0) {
        temp_y--;
        if (num == ans[temp_y][x]) return false;
    }

    int temp_x = x;

    while(temp_x > 0) {
        temp_x--;
        if (num == ans[y][temp_x]) return false;
    }

    temp_y = y;
    temp_x = x;

    while(temp_y < 8) {
        temp_y++;
        if (num == ans[temp_y][x]) return false;
    }

    while(temp_x < 8) {
        temp_x++;
        if (num == ans[y][temp_x]) return false;
    }

    return true;

}

bool bound_check(int y, int x,int num) {
    int oy = y;
    int ox = x;
    
    y = (y / 3) * 3;
    x = (x / 3) * 3;

    for (int i = y; i < y+3; i++){
        for (int j = x; j < x+3; j++){
            if (oy == i && ox == j) continue;

            if (num == ans[i][j]) return false;
        }
    }

    return true;
}

bool check(int y,int x,int num){

    if (row_col_check(y,x,num) && bound_check(y,x,num)){
        return true;
    } else{
        return false;
    }

}


void go(int v_idx){

    if (flag) return;

    if (v_idx >= v.size()) {
        flag = true;
        print_ans();
        return;
    }

    int y = v[v_idx].first;
    int x = v[v_idx].second;

    for (int i = 1; i <= 9; i++){
        if (check(y,x,i)){
            ans[y][x] = i;
            go(v_idx + 1);
            ans[y][x] = 0;
        }
    }

}





int main(){

    for (int i = 0; i < 9; i++){
        cin >> str;
        for (int j = 0; j < 9; j++) {
            A[i][j] = str[j] - '0';
            ans[i][j] = A[i][j];
            if (A[i][j] == 0) {
                v.push_back({i,j});
            }
        }
    }

    go(0);

}