#include <iostream>
#include<algorithm>


using namespace std;

int INDEX[100001];
int inorder[100001];
int postorder[100001];

void getpre(int ins,int ine,int ps ,int pe){

	if (ins > ine || ps > pe){
		return;
	}

	int root_index = INDEX[postorder[pe]];
	int left = root_index - ins;
	int right = ine - root_index;

	cout << inorder[root_index] << " ";

	getpre(ins,root_index-1,ps,ps + left -1);
	getpre(root_index+1,ine, ps + left, pe -1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int N;
	cin >> N;

	//배열들 업뎃
	for (int i = 1; i <= N; i++){
		cin >> inorder[i];
		INDEX[inorder[i]] = i;
	}
	for (int i = 1; i <= N; i++){
		cin >> postorder[i];
	}


	getpre(1,N,1,N);
	




}
	
	

	
	
	
	




	

