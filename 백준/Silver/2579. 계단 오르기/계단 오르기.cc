#include <iostream>
#include<climits>
#include<cmath>
using namespace std;





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int N;
    cin >> N;
    
    int A[300];
    int D[300];
    for (int i =0; i < N; i++){
        cin >> A[i];
    }

    if (N >= 2){
        D[0] = A[0];
        D[1] = A[0] + A[1];
        D[2] = max(A[0]+A[2],A[1]+A[2]);
        for (int i = 3; i < N; i++){
            D[i] = max(D[i-2]+A[i], D[i-3]+A[i-1] + A[i]);
        }
        cout << D[N-1];
    }else{
        if (N == 0) cout <<A[0];
        else{
            cout << A[0] + A[1];
        }
    }



  

	
}