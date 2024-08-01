#include<bits/stdc++.h>


using namespace std;

int ay[4] = {-1,0,1,0}; //상좌하우
int ax[4] = {0,-1,0,1};

int A[51][5];

int r1,c1,r2,c2;

void make_map(){

    int cnt = 0;
    int num = 1;
    int y = 0;
    int x = 0;

    int rect_size = 0;

    int max_y = abs(r2-r1) + 1;
    int max_x = abs(c2-c1) + 1;

    while(cnt <= max_y*max_x){


        if ( (-rect_size <= y && rect_size >= y) &&
                 (-rect_size <= x && rect_size >= x) ){
            
            if (r2 >= y && c2 >= x 
                     && r1 <= y && c1 <= x){

                A[y-r1][x-c1] = num;
                cnt++;

                if (cnt >= max_y*max_x){
                    return;
                }
            }

        }



        int k = 0;

        while(k < 4){
            

            
            int my = y + ay[k];
            int mx = x + ax[k];

            if ( (-rect_size <= my && rect_size >= my) &&
                 (-rect_size <= mx && rect_size >= mx) ){

                    y = my;
                    x = mx;
                    num++;

                    if (r2 >= my && c2 >= mx 
                     && r1 <= my && c1 <= mx){
                        A[my-r1][mx-c1] = num;
                        cnt++;

                        if (cnt >= max_y*max_x){
                            return;
                        }

                    }

               
            }else{
                k++;
            }

            

        }

        num++;
        rect_size++;
        x += 1;


    }

    

}

int find_max_size(){
    int max_y = abs(r2-r1) + 1;
    int max_x = abs(c2-c1) + 1;

    int max_size = 1;

    for (int i = 0; i < max_y; i++){
        for (int j = 0; j < max_x; j++){
            int temp_size = to_string(A[i][j]).size();

            max_size = max(temp_size, max_size);
        }
        
    }

    return max_size;
}

void make_ans(int size){

    int max_y = abs(r2-r1) + 1;
    int max_x = abs(c2-c1) + 1;

    

    for (int i = 0; i < max_y; i++){
        for (int j = 0; j < max_x; j++){
            string temp = to_string(A[i][j]);
            int cnt = size - temp.size();
            for (int i = 0; i < cnt; i++){
                cout <<  " ";
            }
                
            

            cout << temp << " ";

        }

        cout << "\n";
        
    }

    

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> r1 >> c1 >> r2 >> c2;



    make_map();
    
    int max_size = find_max_size();

    //cout << max_size <<  "\n";

    make_ans(max_size);

   


    
    
    

}