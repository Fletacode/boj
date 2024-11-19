#include<bits/stdc++.h>


using namespace std;

int N;

int parent[300010];




int find(int a){
    if (parent[a] != a){
        return parent[a] = find(parent[a]);
    } else{
        return a;
    }
}

void uni (int a, int b){
    int find_a = find(a);
    int find_b = find(b);
    
    parent[find_b] = find_a;
    
}

bool is_same_parent(int a,int b){
    int find_a = find(a);
    int find_b = find(b);
    if (find_a != find_b) return false;
    return true;
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        parent[i] = i;
    }
    
    
    for (int i = 0; i < N-2; i++){
        int a,b;
        cin >> a >> b;
        if (!is_same_parent(a,b)){
            uni(a,b);
        }
    }

    
    for (int i = 1; i < N; i++){
        if (!is_same_parent(i,i+1)){
            cout << i << ' ' << i+1;
            break;
        }
    }
    
    
    
    
}