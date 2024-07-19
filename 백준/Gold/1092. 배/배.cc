#include<bits/stdc++.h>


using namespace std;


int N,M;

vector<int> crain;

vector<int> boxs;

bool visited[10010];

int main(){

    cin >> N;
    
    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        crain.push_back(num);
    }

    cin >> M;

    for (int i = 0; i < M; i++){
        cin >> num;
        boxs.push_back(num);
    }


    sort(crain.begin(), crain.end(), greater<>());

    sort(boxs.begin(),boxs.end(), greater<>());

    //for (int i = 0; i < N; i++) cout << crain[i] << " ";
    //cout << "\n";
    //for (int j = 0; j < M; j++) cout << boxs[j] << " ";

    if (crain[0] < boxs[0]){
        cout << -1;
        return 0;
    }


    int i = 0;
    int ans = 0;
    
    while(i < boxs.size()){
        
        for (int j = 0; j < N; j++){
            if (visited[i]) {
                i++; j--;
                continue;
            }
            if (crain[j] >= boxs[i]){
                visited[i] = true;
                i++;
                if (i >= boxs.size()) break;
            }else{

                for (int k = i+1; k < boxs.size(); k++){
                    if (visited[k]) continue;
                    if (crain[j] >= boxs[k]){
                        visited[k] = true;
                        break;
                    }
                }

            }
        }

        ans++;

        
    }

    cout << ans;
  
        
    


}