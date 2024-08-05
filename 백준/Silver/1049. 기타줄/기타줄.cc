#include<bits/stdc++.h>


using namespace std;


int N,M;

vector<int> v1;
vector<int> v2;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int a,b;

    while(M--){
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 1e9;

    if (N % 6 == 0){
        ans = min((N / 6) * v1[0], N * v2[0] );
        ans = min(ans, (N / 6) * v1[0] + (N % 6) * v2[0]);
    }else{
        ans = min( (N / 6 + 1) * v1[0] , N  * v2[0] );
        ans = min(ans , (N / 6) * v1[0]  + (N%6)  * v2[0] );
    }

   

    cout << ans;
    

}