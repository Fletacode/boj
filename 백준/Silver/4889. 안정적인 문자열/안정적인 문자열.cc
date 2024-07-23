#include<bits/stdc++.h>

using namespace std;

string str;

stack<char> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt = 1;

    while(true){
        cin >> str;
        if (str[0] == '-') break;

        int ans = 0;

        for (int i = 0; i < str.size(); i++){
            if (st.empty()) {
                if (str[i] == '}'){
                    ans++;
                    st.push('{');
                }else{
                    st.push(str[i]);
                }
            }
            else{
                if (st.top() == '{'){
                    if (str[i] == '}'){
                        st.pop();
                    }else{
                        st.push(str[i]);
                    }
                }else{
                    ans++;
                    st.push(str[i]);
                }
            }

        }


        //cout << st.size() << "\n";

        ans += st.size() / 2;

        cout << cnt <<"." << " " << ans << "\n";
        cnt++;

        while(!st.empty()) st.pop();

    }

}