#include<bits/stdc++.h>


using namespace std;

int N,M,K;

struct ball{
    int r; 
    int c;
    int m;
    int s;
    int d;
};

vector<ball> MAP[55][55];

vector<ball> balls;

int ay[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
int ax[8] = {0, 1, 1, 1, 0, -1, -1, -1};



void order(){

    for (int i =1; i <= N; i++){
        for (int j = 1; j <= N; j++){
           
           MAP[i][j].clear();

        }       
    }

    for (ball b : balls){
        int my = b.r;
        int mx = b.c;

        
        my += ay[b.d] * b.s;
        mx += ax[b.d] * b.s;
        

        //cout << my << " " << mx << "\n";

      
        while (my > N){
            my -= N;
        }
        while (mx > N){
            mx -= N;
        }
        while (my <= 0){
            my += N;
        }
        while (mx <= 0){       
            mx += N;
        }

        MAP[my][mx].push_back({my,mx,b.m,b.s,b.d});
        
        

    }

    

    

}

int check_dir(int y,int x){

    bool alleven = true;
    bool allodd = true;

    

    for (ball b : MAP[y][x]){
        if (b.d % 2 == 0){
            allodd = false;
        }
        if (b.d %2 != 0){
            alleven = false;
        }
    }

    if (allodd || alleven) return 0;

    return 1;

} 


vector<ball> make_ball(int y, int x){

    


    vector<ball> v;

    int sum_m = 0;
    int sum_s = 0;


    for (ball b : MAP[y][x]){
        sum_m += b.m;
        sum_s += b.s;
        
    }

    sum_m /= 5;
    sum_s /= MAP[y][x].size();

    //cout << MAP[y][x].size() << "\n";
    //cout << sum_s << "\n";

    if (sum_m <= 0){
        v.clear();
        return v;
    }

    int isdir = check_dir(y,x);

    for (int i = 0; i < 4; i++){
        v.push_back({y,x,sum_m,sum_s, isdir});
        isdir += 2;
    }

    return v;
}   

void find_ball(){

    



    for (int i =1; i <= N; i++){
        for (int j = 1; j <= N; j++){
           
           if (MAP[i][j].size() >= 2){
                vector<ball> v = make_ball(i,j);

                //cout << "v.size(): " << v.size() << "\n";

                for (ball b : v){
                    balls.push_back(b);
                    //cout << b.m << " ";
                } 
                //cout << "\n";
                

           }else if (MAP[i][j].size() == 1){
                balls.push_back(MAP[i][j][0]);
           }

           
        }

       
    }

}

int cal_ans(){

    int ans = 0;

    //cout << "balls size: " << balls.size() << "\n";

    for (ball b : balls){
        //cout << b.m << " ";
        //cout << b.r << " " << b.c << " " << b.m << " " << b.s << " " << b.d;
        //cout << "\n";
        ans += b.m;
    }
    


    return ans;
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;


    int r,c,m,s,d;
    for (int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        balls.push_back({r,c,m,s,d});
    }

    
    for (int i = 0; i < K; i++){
        
        order();
        /*
        cout << "---------------------------\n";

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cout << MAP[i][j].size() << " ";
            }
            cout << "\n";
        }
    
        cout << "++++++++++++++++++++++++++++\n";
        */
        balls.clear();
        find_ball();
        /*
        cout << "---------------------\n";
        for (ball b : balls){
            //cout << b.m << " ";
            cout << b.r << " " << b.c << " " << b.m << " " << b.s << " " << b.d;
            cout << "\n";
        
        }
        cout << "---------------------";
        cout << "\n";
        */
    }

  
    
    

    cout << cal_ans();




    /*
    for (int i =1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (MAP[i][j].size()){
                cout << MAP[i][j].size() << " ";
                //cout << MAP[i][j][0].m << " ";
            }else{
                cout << "0" << " ";
            }
        }

        cout << "\n";
    }
    */

}