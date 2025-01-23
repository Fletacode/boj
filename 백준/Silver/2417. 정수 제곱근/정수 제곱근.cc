#include<bits/stdc++.h>


using namespace std;

long long N;

int main(){

    cin >> N;
    long long q = sqrt(N);

    if (q*q < N){
        q++;
    }

    cout << q; 

}