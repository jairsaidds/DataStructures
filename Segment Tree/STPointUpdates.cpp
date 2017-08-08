#include<bits/stdc++.h>
using namespace std;
long long int st[1010101], N, A[10101010], Q, T, x, y, v;
void build(int p, int l, int r){
	if(l == r){
		st[p] = A[l];
	}else{
		int m = l + (r - l) / 2;
		build(p << 1, l, m);
		build(p << 1 | 1, m + 1, r);
		st[p] = st[p << 1] + st[p << 1 | 1];
	}
}
long long int query(int p, int l, int r, int i, int j){
	if(r < i or l > j)
		return -1;
	if(l >= i and r <= j)
		return st[p];
	int m = l + (r - l) / 2;
	long long int a = query(p << 1, l , m, i , j);
	long long int b = query(p << 1 | 1, m + 1, r, i , j);
	if(a == -1) return b;
	if(b == -1) return a;
	return a + b;
}
void update(int p, int l, int r, int idx, int v){
	if(l == r and l == idx){
		st[p] = v;
	}else{
		if(l > idx or r < idx)
			return;
		int m = l + (r - l) / 2;
		update(p << 1, l, m, idx, v);
		update(p << 1 | 1, m + 1, r, idx, v);
		st[p] = st[p << 1] + st[p << 1 | 1];		
	}
}
void updateRange(int p, int l, int r, int i, int j, int v){
	cout << "Visito" << endl;
	if(r < i or j < l)
		return;	
	if(r == l){
		st[p] = v;
		return;
	}
	int m = l + (r - l) / 2;
	updateRange(p << 1, l , m, i, j, v);
	updateRange(p << 1 | 1, m + 1, r, i, j, v);
	st[p] = st[p << 1] + st[p << 1 | 1];
}
int main(){	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	build(1, 0, N - 1);
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> T;
		if(T == 1){
			cin >> x >> y;
			cout << query(1, 0, N - 1, x, y) << endl;			
		}else{
			if(T == 2){
				cin >> x >> y;
				update(1, 0, N - 1, x, y);
			}else{
				cin >> x >> y >> v;
				updateRange(1, 0, N - 1, x, y, v);
			}	
		}		
	}
	return 0;
}
