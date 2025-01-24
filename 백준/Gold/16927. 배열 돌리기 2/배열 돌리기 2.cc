#include<bits/stdc++.h>


using namespace std;
typedef long long ll;

int N,M,R;
int Map[310][310];

deque<int> A[310];

int ay[4] = { 0,1, 0,-1};
int ax[4] = { 1,0,-1, 0};

void go(){

    int n = N;
    int m = M;

    for (int i = 1; i <= min(N,M) / 2; i++){
        int y = i;
        int x = i;
        A[i].push_back(Map[y][x]);

        for (int j = 0; j < 4; j++){

            while(true){
                y += ay[j];
                x += ax[j];

                if (x > m || x <= i-1 || y > n || y <= i-1){
                    y -= ay[j];
                    x -= ax[j];
                    break;
                } 

                A[i].push_back(Map[y][x]);
            }    

        }

        A[i].pop_back();
        n-=1;
        m-=1;
    }

}

void roll(){

    for (int i = 1; i <= min(N,M) / 2; i++){

        int cnt = R % A[i].size();

        while(cnt--){
            int temp = A[i].front();
            A[i].pop_front();
            A[i].push_back(temp);
        }

    }

}

void get_ans(){
    int n = N;
    int m = M;

    for (int i = 1; i <= min(N,M) / 2; i++){
        int y = i;
        int x = i;
        int cnt = 0;
        Map[y][x] =  A[i][cnt++];
        //cout << Map[y][x] << " ";

        for (int j = 0; j < 4; j++){

            while(true){
                y += ay[j];
                x += ax[j];

                if (x > m || x <= i-1 || y > n || y <= i-1){
                    y -= ay[j];
                    x -= ax[j];
                    break;
                } 

                //A[i].push_back(Map[y][x]);
                if (cnt >= A[i].size()) break;
                Map[y][x] = A[i][cnt++];
                //cout << Map[y][x] << " ";
            } 
              

        }

        
        n-=1;
        m-=1;
        //cout << "\n";
    }
}

void print_ans(){

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cout <<  Map[i][j] << " ";
        }
        cout << "\n";
    }
    
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> R;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin >> Map[i][j];
        }
    }


    go();
    roll();

    /*
    for (int i : A[1]){
        //cout << i << " ";
    }
    */

    get_ans();
    print_ans();
    
    

}