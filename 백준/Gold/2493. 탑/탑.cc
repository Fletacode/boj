#include<bits/stdc++.h>

using namespace std;

int N;

stack<pair<int,int>> st; //idx val

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int num;
    for (int i = 1; i <= N; i++){
        cin >> num;

        if (st.empty()){
            st.push({i,num});
            cout << "0 ";
        }else{
            while(!st.empty()){
                if (num <= st.top().second){
                    cout << st.top().first << " ";
                    break;
                }else{
                    st.pop();
                }
            }
            if (st.empty()) cout << "0 ";
            st.push({i,num});
        }
       



    }



}