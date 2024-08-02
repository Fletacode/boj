#include<bits/stdc++.h>


using namespace std;

int N,K;

deque<double> v1;
deque<double> v2;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

    cin >> N >> K;

    double num;

    for (int i = 0; i < N; i++){
        cin >> num;
        v1.push_back(num);
        v2.push_back(num); 
    }

    

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < K; i++){
        v1.pop_back();
        v1.pop_front();
        v2.pop_back();
        v2.pop_front();
    }

    double fnum = v2[0];
    double bnum = v2[v2.size()-1];

    for (int i = 0; i < K; i++){
        v2.push_back(bnum);
        v2.push_front(fnum);
    }


    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int i = 0; i < v1.size(); i++){
        sum1 += v1[i];
        
    }

    for (int i = 0; i < v2.size(); i++){
        sum2 += v2[i];
    }

    sum1 += 1e-6;
    sum2 += 1e-6;

    double ans1 = sum1 / v1.size() / 1.0;
    double ans2 = sum2 / v2.size() / 1.0;

    printf("%.2lf\n", ans1);

    printf("%.2lf", ans2);








}