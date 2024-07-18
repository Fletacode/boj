#include<bits/stdc++.h>


using namespace std;


int t;
int x,y,x2,y2,n;

vector<pair< int, pair<int,int> > > v;

int solution(){

    int ans = 0;

    for (int i = 0; i < v.size(); i++){
        int x3 = v[i].second.first;
        int y3 = v[i].second.second;
        int r = v[i].first;
        double l1 = sqrt(pow(x- x3,2) + pow(y- y3,2));
        double l2 = sqrt(pow(x2- x3,2) + pow(y2- y3,2));

        if (l1 < r && l2 < r) continue;
        else if (l1 < r || l2 < r) ans++;



    }


    return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){
        v.clear();
        cin >> x >> y >> x2 >> y2;
        cin >> n;

        int x3,y3,r;
        for (int i = 0; i < n; i++){
            cin >> x3 >> y3>> r;
            v.push_back({r,{x3,y3}});
        }

        cout << solution() << "\n";

    }
    

}