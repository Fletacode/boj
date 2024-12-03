#include<iostream>

#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;


int main()
{
	int N;
	cin >> N;

	while(N != 1){
		int i = 2;
		while (N >= i){
			if (N%i == 0){
				cout << i <<"\n";
				N = N/i;
				break;
			}
			i++;
		}
	}
	

}
