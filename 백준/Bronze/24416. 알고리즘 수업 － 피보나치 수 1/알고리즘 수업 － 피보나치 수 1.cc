#include<bits/stdc++.h>


using namespace std;

int N;

int fibo_cnt = 0;

int fibo(int n) {

	

	if (n == 1 || n == 2) return 1;

	fibo_cnt++;

	return (fibo(n - 1) + fibo(n - 2));

}

void fiboDP() {

}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;

	fibo(N);

	cout << fibo_cnt + 1 << " " << N - 2;


	


}