#include<bits/stdc++.h>

using namespace std;

int n1,n2,n3,n4,n5;
int main(){
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    
    int ans = 0;
    
    ans += pow(n1,2);
    ans += pow(n2,2);
    ans += pow(n3,2);
    ans += pow(n4,2);
    ans += pow(n5,2);
      
    cout << ans % 10;
    
}