#include<bits/stdc++.h>


using namespace std;


string input;

bool isSqe(){
    int x_cnt = 0;
    int o_cnt = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (input[(3*i)+j] == 'X') x_cnt++;
            if (input[(3*i)+j] == 'O') o_cnt++;
            
            //if (input[(3*i)+j] == '.') return false;
        }
    }

    if (x_cnt == o_cnt + 1) return true;
    else{
        return false;
    }
}

bool isWidthBingo(int y, char target){
    
    for (int i = 0; i < 3; i++){
        if (input[(3*y)+i] != target) return false;
    }
    return true;
}

bool isHeightBingo(int x, char target){
    
    for (int i = 0; i < 3; i++){
        if (input[(3*i)+x] != target) return false;
    }
    return true;
}

//대각선 왼 > 오
bool isTriRightBingo(char target){
    if (input[0] == target &&
    input[4] == target &&
    input[8] == target){
        return true;
    }

    return false;

}

//대각선 오 > 왼
bool isTriLeftBingo(char target){
    if (input[2] == target &&
    input[4] == target &&
    input[6] == target){
        return true;
    }
    return false;
}

pair<int,int> calBingo(){
    int x_cnt = 0;
    int o_cnt = 0;
    for (int i =0; i < 3; i++){
        if (isWidthBingo(i,'X')) x_cnt++;
        if (isWidthBingo(i,'O')) o_cnt++;
        if (isHeightBingo(i, 'O')) o_cnt++;
        if (isHeightBingo(i, 'X')) x_cnt++;

        

    }

    if (isTriLeftBingo('X')) x_cnt++;
    if (isTriLeftBingo('O')) o_cnt++;

    if (isTriRightBingo('O')) o_cnt++;
    if (isTriRightBingo('X')) x_cnt++;


    return {x_cnt,o_cnt};

}

bool checkBingo(int x_cnt,int o_cnt){
    

    if ((x_cnt == 1 && o_cnt == 0)
     ||(x_cnt == 0 && o_cnt == 1) ){
        return true;
     }else{
        return false;
     }
}

bool isFull(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (input[(3*i)+j] == '.') return false;
            
            //if (input[(3*i)+j] == '.') return false;
        }
    }

    return true;
}

pair<int,int> calCnt(){

    int x_cnt = 0;
    int o_cnt = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (input[(3*i)+j] == 'O') o_cnt++;
            if (input[(3*i)+j] == 'X') x_cnt++;
            
            //if (input[(3*i)+j] == '.') return false;
        }
    }

    return {x_cnt,o_cnt};
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    while(true){
        cin >> input;
        if ( input == "end") return 0;

        pair<int,int> p = calBingo();    
        int x_bcnt = p.first;
        int o_bcnt = p.second;

        pair<int,int> p2 = calCnt();
        int x_cnt = p2.first;
        int o_cnt = p2.second;


        if (isFull()){
            
            //x 승리
            if (isSqe() && !o_bcnt){
                cout << "valid\n";
                continue;
            }else{
                cout << "invalid\n";
                continue;
            }

            
        }else{

            if (checkBingo(x_bcnt, o_bcnt) ){
                if (o_bcnt > x_bcnt
                   && o_cnt == x_cnt){
                   cout << "valid\n";
                    continue;
                }else if (o_bcnt > x_bcnt
                 && o_cnt < x_cnt){
                    cout << "invalid\n";
                    continue;
                }else{
                    if (x_cnt - o_cnt == 1){
                        cout << "valid\n";
                        continue;
                    }else{
                        cout << "invalid\n";
                        continue;
                    }
                }
            }else{
                cout << "invalid\n";
                continue;
            }
        }

        


    }
    


}
