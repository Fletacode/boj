#include<bits/stdc++.h>

using namespace std;

int V,E;

vector<int> arr[10010];
int discovered[10010];
bool isArticulation[10010];

int cnt = 0;

int sol(int now, bool isroot) {

    discovered[now] = cnt++;

    int ret = discovered[now];

    int children = 0;
    for (int i = 0; i < arr[now].size(); i++) {
        int next = arr[now][i];
        
        if (discovered[next] == -1){
            children++;
            int subtree = sol(next,false);
            
            if (!isroot && subtree >= discovered[now]){ 
                isArticulation[now] = true;
            }

            ret = min(ret, subtree);

        } else{
            ret = min(ret, discovered[next]);            
        }
    }

    

    if (isroot && children >= 2){
        isArticulation[now] = true;
    }

    return ret;
}



void init(){
    for (int i = 0; i <= V; i++){
        discovered[i] = -1;
    }
    cnt = 0;
}

void input_fun(){
    cin >> V >> E;
     int a,b;
    for (int i = 0; i < E; i++){
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    input_fun();
    init();

    for (int i = 1; i <= V; i++){
        if (discovered[i] == -1){
            sol(i,true);
        }
    }

    vector<int> ans;

    for (int i = 1; i <= V; i++){
        //cout << isArticulation[i] << " ";
        if (isArticulation[i]){
            ans.push_back(i);
        }   
    }

    cout << ans.size() << "\n";

    for (int i : ans){
        cout << i << " ";
    }

}