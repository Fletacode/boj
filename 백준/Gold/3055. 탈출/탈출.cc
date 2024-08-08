#include<bits/stdc++.h>


using namespace std;

int R,C;

char Map[55][55];

int visited[55][55];

bool visited_w[55][55];

vector<pair<int,int>> waters;

vector<pair<int,int>> dochs;

int ay[4] = {-1, 1, 0, 0}; //상하좌우
int ax[4] = { 0, 0,-1, 1};

bool flag = false;

void water_move(){

    vector<pair<int,int>> temp;

    for (pair<int,int> p : waters){
        int y = p.first;
        int x = p.second;

        for (int i = 0; i < 4; i++){
            int my = y + ay[i];
            int mx = x + ax[i];

            if (my < 0 || my >= R || mx < 0 || mx >= C) continue;
            if (visited_w[my][mx]) continue;
            //if (Map[my][mx] == 'S' || Map[my][mx] == 'X'
            //|| Map[my][mx] == 'D') continue;

            if (Map[my][mx] == '.'){
                temp.push_back({my,mx});
                visited_w[my][mx] = true;
                Map[my][mx] = '*';
            }
            

        }

    }

    
    waters.clear();
    waters = temp;
}

void doch_move(int minute){

    vector<pair<int,int>> temp;

    for (pair<int,int> p : dochs){
        int y = p.first;
        int x = p.second;

        for (int i = 0; i < 4; i++){
            int my = y + ay[i];
            int mx = x + ax[i];

            if (my < 0 || my >= R || mx < 0 || mx >= C) continue;
            if (visited[my][mx]) continue;
            if (Map[my][mx] == 'S' || Map[my][mx] == 'X' 
                || Map[my][mx] == '*') continue;
            
            if (Map[my][mx] == 'D'){
                flag = true;
                visited[my][mx] = minute;
                dochs.clear(); temp.clear();
                waters.clear();
                return;
            } 

            if (Map[my][mx] == '.'){
                temp.push_back({my,mx});
                visited[my][mx] = minute;
                Map[my][mx] = 'S';
            }
            

        }

    }

    
    dochs.clear();
    dochs = temp;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    
    pair<int,int> biber;

    for (int i = 0; i < R; i++){
        string s;
        cin >> s;
        for (int j  =0; j < C; j++){
            if (s[j] == '*'){
                waters.push_back({i,j});
                visited_w[i][j] = true;
            } 
            if (s[j] == 'S') dochs.push_back({i,j});

            if (s[j] == 'D') biber = {i,j};

            Map[i][j] = s[j];
        }
    }

    int minute = 1;
    while(!flag && !dochs.empty()){
        //cout << waters.size() << " " << dochs.size()<< "\n";
        water_move();
        doch_move(minute++);
        
    }

    if (flag){
        cout << visited[biber.first][biber.second];
    }else{
        cout << "KAKTUS";
    }






}