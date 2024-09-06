#include<bits/stdc++.h>

using namespace std;

int N,M;

vector< pair<int, pair<int,int> > > v;

int parent[1010];


int find(int a){
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}


bool same_parent(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if (parent[fa] == parent[fb]){
        return true;
    }else{
        return false;
    }
}


void uni(int a,int b){
    int fa = find(a);
    int fb = find(b);
    parent[fb] = fa;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M;


    int a,b,c;
    for (int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(),v.end());

    /*
    for (int i = 0; i < v.size(); i++){
        cout << v[i].second.first << " " << v[i].second.second << "\n";
    }
    */

    for (int i = 1; i <= 1000; i++) parent[i] = i;

    int ans = 0;

    for (int i = 0; i < v.size(); i++){
        
        if (!same_parent(v[i].second.first,v[i].second.second)){
            uni(v[i].second.first,v[i].second.second);
            //cout << v[i].second.first << " " << v[i].second.second << "\n";
            ans += v[i].first;
        }
    }

    

    cout << ans;

}