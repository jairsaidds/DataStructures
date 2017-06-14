#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll A[1000000], st[1000000], lazy[1000000];
void build(ll p, ll l, ll r){
	lazy[p] = 0;
	if(l == r)
		st[p] = A[r];
	else{
		ll m = (l + r) >> 1;
		build(p << 1, l, m);
		build(p << 1 | 1, m + 1, r);
		st[p] = st[p << 1] + st[p << 1 | 1];
	}
}
void propagate(ll p, ll l, ll r){
	st[p] = st[p] + (r - l + 1) * lazy[p];
	if(l != r){
		lazy[p << 1] = lazy[p];
		lazy[p << 1|1] = lazy[p];
	}
	lazy[p] = 0;
}
void update(ll p , ll l, ll r, ll a, ll b, ll v){
	if(lazy[p] != 0){
		propagate(p , l , r);
	}
	if(r < a or l > b)
		return;
	if(l >= a and r <= b){
		st[p] = st[p] + (r - l + 1) * v;
		if(l != r){
			lazy[p << 1] = lazy[p << 1] + v;
			lazy[p << 1|1] = lazy[p << 1|1] + v;
		}
		return;
	}
	ll m = (l + r) >> 1;
	update(p << 1, l , m , a , b , v);
	update(p << 1|1, m + 1 , r, a , b , v);
	st[p] = st[p << 1] + st[p << 1 | 1];
}
ll query(ll p, ll l , ll r, ll a, ll b){
	if(lazy[p] != 0)
		propagate(p , l, r);
	if(r < a or l > b)
		return -1;
	if(l >= a and r <= b)
		return st[p];
	ll m = (l + r) >> 1;
	ll dx = query( p << 1, l , m , a, b);
	ll dy = query( p << 1 | 1, m + 1 , r , a, b);
	if(dx == -1)
		return dy;
	if(dy == -1)
		return dx;
	return (dx + dy);
}
int main(){
	ll N, Q, T, x, y, v;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	build(1,0,N-1);
	cin >> Q;
	for(int i = 0; i < Q; i ++){
		cin >> T;
		if(T == 1){
			cin >> x >> y >> v;
			update(1, 0 , N - 1, x, y, v);
		}else{
			cin >> x >> y;
			cout << query(1, 0, N - 1, x, y)<<endl;
		}
	}
	return 0;
}