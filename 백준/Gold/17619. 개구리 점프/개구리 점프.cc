#include<bits/stdc++.h>


using namespace std;

int N, Q;

vector<pair<pair<int,int>,int> > v;

int parent[100010];

int find(int a){
    if (a != parent[a]) return parent[a] = find(parent[a]);
    else{
        return a;
    }
}

void uni(int a,int b){
    int find_a = find(a);
    int find_b = find(b);


    parent[find_b] = find_a;

}


void find_wood(){

    int now = v[0].second;
    int e = v[0].first.second;

    for (int i = 1; i < v.size(); i++){
        if (e >= v[i].first.first){
            if (e < v[i].first.second){
                uni(now,v[i].second);
                e = v[i].first.second;
                now = v[i].second;
            }else{
                uni(now,v[i].second);
            }
            
        }else{
            now = v[i].second;
            e = v[i].first.second;
        }

        
    }

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N >> Q;

    for (int i = 1; i <= N; i++) parent[i] = i;

    int x1,x2,y;
    for (int i = 0; i < N; i++){
        cin >> x1 >> x2 >> y;
        v.push_back({{x1,x2},i+1});
    }

    sort(v.begin(),v.end());

    find_wood();

    int a,b;
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        if (parent[a] != parent[b]) cout << "0\n";
        else{
            cout << "1\n";
        }
    }

    //for (int i = 1; i <= N; i++) cout << parent[i] << " ";

}