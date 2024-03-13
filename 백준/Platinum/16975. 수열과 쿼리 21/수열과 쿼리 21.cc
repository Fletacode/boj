#include<bits/stdc++.h>

#define SIZE 262144
using namespace std;

typedef long long ll;

ll N,M;
ll tree[SIZE + 10];
ll arr[SIZE + 10];
ll lazy[SIZE + 10];

ll init(int node, int st, int end) {

	if (st == end) {
		return tree[node] = arr[st];
	}

	ll mid = (st + end) / 2;

	return tree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void propaganda(int node, int st, int end) {
	if (lazy[node] != 0) {

		if (st != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		tree[node] += (end - st + 1) * lazy[node];
		lazy[node] = 0;
	}
	
}


void update(int node, int st, int end,int left,int right,int diff) {
	propaganda(node, st, end);

	if (right < st || end < left) return;
	if (left <= st && right >= end) {
		lazy[node] += diff;
		propaganda(node, st, end);
		return;
	}
	
	ll mid = (st + end) / 2;
	update(node * 2, st, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	
	

}

ll find_query(int node, int st, int end, int left, int right) {
	propaganda(node, st, end);

	if (right < st || end < left) return 0;
	if (left <= st && right >= end) {
		
		return tree[node];
	}

	ll mid = (st + end) / 2;

	return find_query(node * 2, st, mid, left, right) +
		find_query(node * 2 + 1, mid + 1, end, left, right);


}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(1, 0, N-1);

	
	cin >> M;
	int num,a,b,k;
	while (M--) {
		cin >> num;
		if (num == 1) {
			cin >> a >> b >> k;
			update(1, 0, N - 1, a - 1, b - 1, k);
		}
		else {
			cin >> k;
			cout << find_query(1, 0, N - 1, k - 1, k - 1) << "\n";
		}
	}
	

}