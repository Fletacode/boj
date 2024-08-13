#include<bits/stdc++.h>

using namespace std;


int N,K;

vector<int> v;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

    cin >> N >> K;

    int num;
    for (int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }

    double ans = 1e9;

    for (int i = 0; i < N; i++){
       
        int c = 0;
        while(i+c+K <= N){
            double sum = 0.0;

            //printf("%d %d\n",i,c);
           
            

            for (int j = 0; j < K+c; j++){
                sum += v[i+j];
            }
            //printf("%d\n", sum);
            double m = sum / (K+c);

            //m += 1e-7;

            //printf("%.18lf\n", m);
            double bunsua = 0.0;

            for (int j = 0; j < K+c; j++){
                bunsua += pow((v[i+j] - m),2.0);
            }
    
            bunsua /= (K+c);
            //bunsua += 1e-7;

            //printf("%.18lf\n", bunsua);

            ans = min(ans,sqrt(bunsua));
            c++;
        }
        

    }


    printf("%.18lf", ans);

}