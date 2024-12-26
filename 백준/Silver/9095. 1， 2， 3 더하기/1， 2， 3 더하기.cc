#include <iostream>
using namespace std;

int N;
int ans;

void DFS(int num){
    if (num == N) {
        ans++;
        return;
    }else if (num > N) return;
    for (int i = 1; i <= 3; i++){
        DFS(num+i);
    }
} 


int main(){
    
    int T;

    cin >> T;
    
    


    while (T--){
        cin >> N;
        ans = 0;
        DFS(1);
        DFS(2);
        DFS(3);
        cout << ans << "\n";
    }

    
    return 0;
}
