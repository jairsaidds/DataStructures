#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L(p) 2*p
#define R(p) (2*p) + 1
#define endl '\n'
ll A[4 * 200000], lazy[4 * 200000], st[4 * 200000];
void inline build(ll p, ll l, ll r){
	lazy[p] = 0 ;
	if(l == r){
		st[p] = A[l];
	}else{
		ll m = (l + r) >> 1;
		build(L(p), l , m);
		build(R(p), m + 1 , r);
		st[p] = min(st[L(p)], st[R(p)]);
	}
}
void inline propagate(ll p, ll l, ll r){
	st[p] += lazy[p];
	if(l != r){
		lazy[L(p)] += lazy[p];
		lazy[R(p)] += lazy[p];
	}
	lazy[p] = 0;
}
void inline update(ll p, ll l, ll r, ll a, ll b, ll v){
	if(lazy[p] != 0){
		propagate(p, l, r);
	}
	if(r < a or l > b)
		return;
	if(l >= a and r <= b){
		st[p] += v;
		if(l != r){
			lazy[L(p)] += v;
			lazy[R(p)] += v;
		}
		return;
	}
	ll m = ( l + r ) >> 1;
	update(L(p), l, m, a, b, v);
	update(R(p), m + 1, r , a, b, v);
	st[p] = min(st[L(p)], st[R(p)]);
}
ll query(ll p, ll l, ll r, ll a, ll b){
	if(lazy[p] != 0){
		propagate(p, l, r);
	}
	if(r < a || l > b)
		return (1LL << 60);
	if(l >= a and r <= b){
		return st[p];
	}
	ll m = (l + r) >> 1;
	ll dx = query(L(p), l, m, a, b);
	ll dy = query(R(p), m + 1, r , a, b);
	return min(dx, dy);
}
ll N, M;
string in;
vector<ll> aux;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	build(1, 0, N -1);
	cin >> M;
	cin.ignore();
	for(int i = 0; i < M; i++){
		getline( cin, in );
	 	istringstream iss( in );
	 	aux.clear();
	 	ll xx, a, b, c;
	 	while( iss >> xx )
	 		aux.push_back(xx);
	 	if(aux.size() == 2){
	 		a = aux[0], b = aux[1];
	 		if(a > b){
	 			ll aa = query(1, 0, N - 1, a , N -1);
	 			ll bb = query(1, 0, N - 1, 0 , b);
	 			cout << min(aa, bb)<<endl;
	 		}else{
	 			cout << query(1, 0, N - 1, a , b)<<endl;
	 		}
	 	}else{
	 		a = aux[0], b = aux[1], c = aux[2];
	 		if(a > b){
	 			update(1, 0, N - 1, a , N -1, c);
	 			update(1, 0, N - 1, 0 , b, c);
	 		}else{
	 			update(1, 0, N - 1, a , b, c);
	 		}
	 	}
 	}
	return 0;
}