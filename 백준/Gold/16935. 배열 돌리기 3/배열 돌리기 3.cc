#include<bits/stdc++.h>


using namespace std;
typedef long long ll;

vector<vector<int>> v(110, vector<int>(110,0));

int N,M,R;

void reverseNM(){
    int temp = N;
    N = M;
    M = temp;
}


void rotate_90_left(vector<vector<int>> &key){

    reverseNM();

    vector<vector<int>> temp(N, vector<int>(M,0));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            temp[i][j] = key[j][N-i-1];
        }
    }

    key = temp;
}

void rotate_90_right(vector<vector<int>> &key) {

    reverseNM();

    vector<vector<int>> temp(N, vector<int>(M,0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[i][j] = key[M-j-1][i];
        }
    }

    key = temp;

}

void print_v(){


    for (int i =0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

}

void reverse_up_down(vector<vector<int>> &key){

    vector<vector<int>> temp(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            temp[i][j] = key[N-i-1][j];
        }
    }

    key = temp;

}

void reverse_left_right(vector<vector<int>> &key) {

    vector<vector<int>> temp(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            temp[i][j] = key[i][M-j-1];
        }
    }

    key = temp;

}

void div_rotate_unclock(vector<vector<int>> &key) {

    vector<vector<int>> temp(N, vector<int>(M,0));

    int cnt = 0;

    for (int y = 0; y <= N/2; y+= N/2) {
        for (int x = 0; x <= M/2; x+= M/2) {
            
            cnt++;

            for (int i = 0; i < N/2; i++){
                for (int j = 0; j < M/2; j++){
                    if (cnt == 1) temp[y+i][x+j] = key[i][M/2+j];
                    else if (cnt == 2) temp[y+i][x+j] = key[N/2+i][M/2+j];
                    else if (cnt == 3) temp[y+i][x+j] = key[i][j];
                    else{
                        temp[y+i][x+j] = key[N/2+i][j];
                    }
                }
            }


        }
    }


    key = temp;

}


void div_rotate_clock(vector<vector<int>> &key) {

    vector<vector<int>> temp(N, vector<int>(M,0));

    int cnt = 0;

    for (int y = 0; y <= N/2; y+= N/2) {
        for (int x = 0; x <= M/2; x+= M/2) {
            
            cnt++;

            for (int i = 0; i < N/2; i++){
                for (int j = 0; j < M/2; j++){
                    if (cnt == 1) temp[y+i][x+j] = key[N/2+i][j];
                    else if (cnt == 2) temp[y+i][x+j] = key[i][j];
                    else if (cnt == 3) temp[y+i][x+j] = key[N/2+i][M/2+j];
                    else{
                        temp[y+i][x+j] = key[i][M/2+j];
                    }
                }
            }


        }
    }


    key = temp;


}

void sol(){
    int order;

    while(R--){
        cin >> order;
        if (order == 1) {
            reverse_up_down(v);
        } else if (order == 2) {
            reverse_left_right(v);
        } else if (order == 3) {
            rotate_90_right(v);
        } else if (order == 4) {
            rotate_90_left(v);
        } else if (order == 5) {
            div_rotate_clock(v);
        } else {
            div_rotate_unclock(v);
        } 
    }
   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M >> R;
    
    for (int i = 0; i < N; i++){
        int num;
        for (int j = 0; j < M; j++) {
            cin >> num;
            v[i][j] = num;
        }
    }

    sol();

    print_v();
}