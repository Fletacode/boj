#include<bits/stdc++.h>


using namespace std;


int p,m;

queue<pair<string, int> > q;

vector<pair<pair<string,int> , int > > A[310];

int rec_room_size = 0;

int find_room(int level){

    for (int i = 0; i <= rec_room_size; i++){

        if (!A[i].empty() &&
            (level <= A[i][0].second + 10 &&
            level >= A[i][0].second - 10) &&
            A[i].size() < m ){
                return i;
        }

    }

    return -1;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> p >> m;

    int l;
    string n;
    for (int i = 0; i < p; i++){
        cin >> l >> n;
        q.push({n,l});
    }

    
    int level = q.front().second;
    string name = q.front().first;

    A[0].push_back({{name,level},level});
    q.pop();

    while(!q.empty()){
        level = q.front().second;
        name = q.front().first;

        q.pop();


        int find_room_idx = find_room(level);


        if (find_room_idx == -1){
            rec_room_size += 1;
            A[rec_room_size].push_back({{name,level}, level});
        }
        else{
            int room_level = A[find_room_idx][0].first.second;
            A[find_room_idx].push_back({{name,level}, room_level});
        }


    }

    for (int i = 0; i <= rec_room_size; i++){
       
        
        if (A[i].size() == m) cout << "Started!\n";
        else{
            cout << "Waiting!\n";
        }

        sort(A[i].begin(), A[i].end());

        for (pair<pair<string,int>,int> p : A[i]){
            cout << p.first.second << " " << p.first.first << "\n";
        }

    }

    

}