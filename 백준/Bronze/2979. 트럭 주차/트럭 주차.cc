#include<bits/stdc++.h>

using namespace std;

int M[4];
int A[101];


int main(){

	for (int i = 1; i <= 3; i++){
		cin >> M[i];
	}

	int s,e;

	for (int i = 1; i <= 3; i++){
		cin >> s >> e;
		for (int j = s; j < e; j++){
			A[j]++;
		}
	}

	int sum = 0;

	for (int i = 1; i <=100; i++){
		sum += M[A[i]] * A[i];
	}

	cout << sum;
}