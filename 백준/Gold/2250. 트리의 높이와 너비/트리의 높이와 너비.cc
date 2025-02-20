#include<bits/stdc++.h>


using namespace std;

int N;

struct Node{
    int left, right;
};

vector<Node> Tree;

vector<vector<int>> Map;

int visited[10010];
int col = 1;

void input_fun() {
    cin >> N;
    Tree.resize(N+1, {});

    int n,l,r;
    for (int i = 0; i < N; i++) {
        cin >> n >> l >> r;

        Tree[n] = {l,r};

        if (l != -1) visited[l] = true;
        if (r != -1) visited[r] = true;

    }

}

int get_root() {

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            return i;
        }
    }

    return -1;
}

void inorder(int now,int level){

    if (now == -1){
        return;
    }

    inorder(Tree[now].left, level + 1);

    if (Map.size() <= level) Map.resize(level + 1);
    Map[level].push_back(col++);

    inorder(Tree[now].right, level + 1);

}


void get_max_length(){

    int max_length = -1;
    int level = 1;

    for (int i = Map.size()-1; i >= 1; i--) {
        
        sort(Map[i].begin(), Map[i].end());

        if (max_length <= Map[i][Map[i].size()-1] - Map[i][0] + 1) {
            max_length = Map[i][Map[i].size()-1] - Map[i][0] + 1;
            level = i;
        }

        

    }

    cout << level << " " << max_length;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input_fun();
    int root = get_root();

    inorder(root,1);
   
    get_max_length();
}