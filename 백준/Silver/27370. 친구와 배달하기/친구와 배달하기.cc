#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int T;
int N;
int pa,pb;


vector<ll> v;
ll asum = 0;
ll bsum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--){
        

        cin >> N >> pa >> pb;

        asum = 0;
        bsum = 0;
        v.clear();

        ll n;
        for (int i = 0; i < N;i++){
            cin >> n;
            ll cal_a = 2*abs(pa-n);
            ll cal_b = 2*abs(pb-n);

            if (cal_a < cal_b) asum += cal_a;
            else if (cal_a > cal_b) bsum += cal_b;
            else{
                v.push_back(cal_b);
            }

        }

        //cout << asum << " " << bsum << "\n";

        sort(v.begin(),v.end());

        for (int i = 0; i < v.size(); i++){
            if (asum < bsum) asum += v[i];
            else{
                bsum += v[i];
            }
        }

        cout << asum+bsum << " " << abs(asum-bsum) << "\n";

        


    }





   


}