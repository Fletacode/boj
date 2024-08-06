#include<bits/stdc++.h>


using namespace std;

int T;


int ay[4] = {1,  0, -1,  0}; //상좌하우
int ax[4] = {0, -1,  0,  1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    string s;

    while(T--){
        cin >> s;
        int total_move_y = 0;
        int total_move_x = 0;
        int width_plus = 0;
        int height_plus = 0;
        int width_ma = 0;
        int height_ma = 0;

        int d = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'F'){
                total_move_y += ay[d];
                total_move_x += ax[d];

                if (d == 0 || d == 3){
                    height_plus = max(height_plus, total_move_y);
                    width_plus = max(width_plus, total_move_x);
                }else{
                    height_ma = min(height_ma, total_move_y);
                    width_ma = min(width_ma, total_move_x);
                }
                
            }else if (s[i] == 'B'){
                total_move_y -= ay[d];
                total_move_x -= ax[d];

                if (d == 0 || d == 3){
                    height_ma = min(height_ma, total_move_y);
                    width_ma = min(width_ma, total_move_x);
                }else{
                    height_plus = max(height_plus, total_move_y);
                    width_plus = max(width_plus, total_move_x);
                }
                
            }else if (s[i] == 'L'){
                
                d = (d+1) % 4;
            }else{
                
                if (d - 1 < 0){
                    d = 3;
                }else{
                    d -= 1;
                }
            }
        }

        //cout << width_plus << " " << height_ma << "\n";
        cout << abs(width_plus - width_ma)  * abs(height_plus - height_ma) << "\n";

        
    }


}