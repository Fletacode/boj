#include <iostream>

#include <string>
using namespace std;

string ips;
string bs;






int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin >> ips >> bs;
	
    string t = "";
 

    for (int i = 0; i < ips.size(); i++){

        t += ips[i];

        if (t.size() >= bs.size()){

            

            bool isbomb = true;
            int cnt = bs.size();
            int idx = t.size() - 1;

            while (cnt--){ //폭파 문자열 확인
                if (t[idx--] != bs[cnt]) isbomb = false;
            }
            
            if (isbomb){
                cnt = bs.size(); //문자열이 폭파문자열과 같으면
                while (cnt--) t.pop_back(); 
            }
            
            
        }

        
            
        
    }

    if (t.size() == 0) cout << "FRULA";
    else{
         for (int i = 0; i < t.size(); i++){
            cout << t[i];
        }
    }


   
   


   



	return 0;
}