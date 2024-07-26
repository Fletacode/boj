#include<bits/stdc++.h>


using namespace std;

int N,M;

string s;

int A[55][55];



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < 51; i++){
        for (int j = 0; j < 51; j++){
            A[i][j] = -1;
        }
       
    }


    for (int i = 0; i < N; i++){
        cin >> s;
        for (int j = 0; j < M; j++){
            A[i][j] = s[j] - '0';
           
        }
       
    }

    int ans = 1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            

            for (int k = j+1; k < M; k++){
                if (A[i][k] == A[i][j]){
                    int size = k - j;
                    if (size+i < N && size + j < M){
                        if (A[i][j] == A[i+size][j+size]
                            && A[i+size][j] == A[i][j]){
                            size++;
                            ans = max(ans, size*size);
                        }
                    }
                }
            }

            
            
            
        }
    }


    cout << ans;

    

}