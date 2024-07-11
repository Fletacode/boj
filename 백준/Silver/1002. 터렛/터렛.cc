#include<bits/stdc++.h>

typedef long long ll;

using namespace std;




ll t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie();


    cin >> t;

    while(t--){
        int x1,y1,x2,y2,r1,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double y_v =  pow(y2-y1,2);
        double x_v = pow(x2-x1,2);
        double d = sqrt( y_v+ x_v );
        

        if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1 << "\n"; //겹칠떄
        else{
            // 하나만
            if (r2+r1 == d ||  d == abs(r2-r1)) cout << 1 << "\n";
            else if (d > abs(r2-r1) && d < r1+r2) cout << 2 << "\n";
            else{
                cout << 0 << "\n";
            }
        }


    }


}