#include<bits/stdc++.h>


using namespace std;

int N;

string answer;

int main(){
    
    cin >> N;

    for (int i = 1;  i <= N; i++){
        cout << "? " << i << "\n";
        
        fflush;
        cin >> answer;
        if (answer == "Y"){
            cout << "! " << i << "\n";
            break;
        }else{
            i = 1;
        }
    }

}