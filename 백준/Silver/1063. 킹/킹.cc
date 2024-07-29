#include<bits/stdc++.h>


using namespace std;

string king;
string stone;

int ky,kx;
int sy,sx;

int N;

map<string, pair<int,int>> m;

int changeAlphatoNum(char c){

    return c - 64;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    m["R"] = {0,1}; // y,x
    m["L"] = {0,-1};
    m["B"] = {-1,0};
    m["T"] = {1,0};
    m["RT"] = {1,1};
    m["LT"] = {1,-1};
    m["RB"] = {-1,1};
    m["LB"] = {-1,-1};

    cin >> king >> stone;

    ky = king[1] - '0';
    kx = changeAlphatoNum(king[0]);

    //cout << ky << kx << "\n";

    sy = stone[1] - '0';
    sx = changeAlphatoNum(stone[0]);

    cin >> N;

    string input;
    for (int i = 0; i < N; i++){
        cin >> input;

        int mky = ky + m[input].first;
        int mkx = kx + m[input].second;
        
        if (mky <= 0 || mky > 8 || mkx <= 0 || mkx > 8) continue;
        

        if (mkx == sx && mky == sy){
            int msy = sy + m[input].first;
            int msx = sx + m[input].second;

            if (! (msy <= 0 || msy > 8 || msx <= 0 || msx > 8) ){
                ky = mky;
                kx = mkx;
                sy = msy;
                sx = msx;
            }
            
        } else{
            ky = mky;
            kx = mkx;
        }
       
    }  

    

    string ans_king = "";

    ans_king += (char) (kx + 64);
    ans_king += to_string(ky);

    string ans_stone = "";

    ans_stone += (char) (sx + 64);
    ans_stone += to_string(sy);

    cout << ans_king << "\n";
    cout << ans_stone;

}
