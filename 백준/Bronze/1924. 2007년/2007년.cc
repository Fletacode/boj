#include<bits/stdc++.h>

using namespace std;

int m,d;

int A[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
string day[8] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main(){
    cin >> m >> d;
    int sum_days = 0;
    for (int i = 1; i < m; i++) sum_days += A[i];

    sum_days += d;

    cout << day[sum_days% 7];
    

    
}