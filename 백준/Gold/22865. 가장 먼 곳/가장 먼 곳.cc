#include<bits/stdc++.h>

using namespace std;

int N,M;

int ABC[3];

int ans[3][100010];

vector<pair<int,int>> Path[100010]; //now next val

int visited[100010];

bool compare(pair<int,int> p1, pair<int,int> p2) {

    if (p1.first > p2.first){
        return true;
    } else {
        if (p1.first == p2.first){
            if (p1.second < p2.second){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

}


int get_ans(){

    vector<pair<int,int>> v;

    for (int i = 1; i <= N; i++){
        if (ABC[0] == i || ABC[1] == i || ABC[2] == i) continue;
       int min_val = 1e9;
        for (int j = 0; j < 3; j++){
            
            min_val = min(ans[j][i],min_val);

        }
        v.push_back({min_val,i});
    }

    sort(v.begin(), v.end(), compare);

    return v[0].second;
}


void print_visited(){

    for (int i =0; i <= N; i++){
        cout << visited[i] << " ";
    }
    cout << "\n";

}


void diestr(int st){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0,st});

    visited[st] = 0;

    while(!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();
        int now =p.second;
        int val = p.first;

        for (int i = 0; i < Path[now].size(); i++) {
            int next = Path[now][i].second;
            int val = Path[now][i].first;

            if (visited[now] + val < visited[next]){
                visited[next] = visited[now] + val;
                pq.push({val,next});
            }
        }

    }
}

void write_ans(int idx){

    for (int i = 1; i <= N; i++) {
        ans[idx][i] = visited[i];
    }

}


void init() {
    for (int i = 0; i < 100010; i++) {
        visited[i] = 1e9;
    }
}

void input_fun(){

    cin >> N;
    cin >> ABC[0] >> ABC[1] >> ABC[2];

    cin >> M;
    int st,end,val;
    for (int i = 0; i < M; i++) {
        cin >> st >> end >> val;

        Path[st].push_back({val,end});
        Path[end].push_back({val,st});
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input_fun();

    for (int i =0; i < 3; i++){
        init();
        diestr(ABC[i]);
        //print_visited();
        write_ans(i);
    }

    cout << get_ans();

}