#include<bits/stdc++.h>


using namespace std;

int N;
int s,e;
int end_point;
struct Circle{
    int num, x,r;
};

vector<Circle> input_v;

bool visited[200010];

bool compare(Circle c1, Circle c2) {
    if (c1.r < c2.r) return true;
    else {
        return false;
    }
}

void input(){
    cin >> N;

    int num,x,r;
    for (int i = 0; i < N; i++) {
        cin >> num >> x >> r;
        input_v.push_back({num,x,r});
    }
    cin >> s >> e;

    input_v.push_back({0,0,(int)1e9});

}

int find_idx(int st_num){

    for (int i = 0; i < input_v.size(); i++){
        if (input_v[i].num == st_num) return i;
    }

}

double get_distance(Circle c1, Circle c2){
    return sqrt(pow(c1.x - c2.x, 2));
}

bool check_inner(Circle c1, Circle c2){
    double d = get_distance(c1,c2);
    if (d < abs(c1.r - c2.r)){
        return true;
    } else {
        return false;
    }
}

vector<Circle> bfs(int st_num) {

    queue<int> q;
    vector<Circle> ans;

    int st_idx = find_idx(st_num);
    q.push(st_idx);
    visited[st_idx] = true;
    ans.push_back(input_v[st_idx]);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = now + 1; i < input_v.size(); i++) {
            if (check_inner(input_v[now], input_v[i])) {
                if (!visited[i]) {
                    q.push(i);
                    ans.push_back(input_v[i]);
                    visited[i] = true;
                } else {
                    end_point = input_v[i].num;
                    ans.push_back(input_v[i]);
                    return ans;
                }
                break;
            }
        }
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    sort(input_v.begin(), input_v.end(), compare);

    vector<Circle> ans;

    vector<Circle> a = bfs(s);
    vector<Circle> b = bfs(e);
    // for (Circle i : a) cout << i.num << " ";
    // cout << "\n";
    // for (Circle i : b) cout << i.num << " ";

   

    for (int i = 0; i < a.size(); i++) {
        if (end_point == a[i].num) break;
        ans.push_back(a[i]);
    }

    for (int i = b.size()-1; i >= 0; i--) {
        ans.push_back(b[i]);
    }


    cout << ans.size() << "\n";
    for (int i  =0; i < ans.size(); i++) {
        cout << ans[i].num << " ";
    }

}