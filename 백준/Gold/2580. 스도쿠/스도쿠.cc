#include<bits/stdc++.h>


using namespace std;

int A[10][10];

int ans[10][10];

vector<pair<int,int>> v;

bool isend;

bool check(int y, int x, int val){

    for (int i = 0; i < 9; i++){
        if (A[i][x] == val) return false;
        if (A[y][i] == val) return false;
    }


    y = y / 3 * 3;
    x = x / 3 * 3;

    for (int i = y; i < y + 3; i++){
        for (int j = x; j < x + 3; j++){
            if (val == A[i][j]) return false;
        }
    }

    return true;

}

void dfs(int depth){
    if (isend) return;

    if (depth == v.size()){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
        isend = true;
        return;
    }

    
    int y = v[depth].first;
    int x = v[depth].second;
    for (int i = 1; i <= 9; i++){
        if (check(y,x,i)){
            A[y][x] = i;
            dfs(depth + 1);
            A[y][x] = 0;
            
        }
        
    }

    



}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> A[i][j];
            if (!A[i][j]) v.push_back({i,j});
        }
    }


    dfs(0);


    //cout << v.size();
}