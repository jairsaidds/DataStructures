#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll st[5024000], A[5024000], N, T, M, X;
char lazy[5024000];
string in;
const ll INF = 1LL<<60;
void build(ll p, ll L, ll R){
	lazy[p] = 'X';
	st[p]   =  0;
	if(L == R)
		st[p] = A[L];
	else{
		build( (2 * p), L, (L + R) >> 1);
		build( (2 * p) + 1, ((L + R) >> 1) + 1, R);
		ll dx = st[2 * p], dy = st[2 * p + 1];
		st[p] = dx + dy;
	}
}
void changeState(ll p){
	if(lazy[p] == 'I'){
		lazy[p] = 'X';
		return;
	}
	if(lazy[p] == 'E'){
		lazy[p] = 'F';
		return;
	}
	if(lazy[p] == 'F'){
		lazy[p] = 'E';
		return;
	}
	if(lazy[p] == 'X'){
		lazy[p] = 'I';	
		return;
	}
}
void propagate(ll p ,ll  R,ll  L){
	if(lazy[p] == 'E'){
		st[p] = 0;
	}
	if(lazy[p] == 'F'){
		st[p] = (R - L + 1);
	}
	if(lazy[p] == 'I'){
		st[p] = R - L + 1 - st[p];
	}
	if(L != R){
		if(lazy[p] == 'I'){
			changeState(p*2);
			changeState((p*2)+ 1);
		}else{
			lazy[ (p*2) + 1 ] = lazy[p];
			lazy[ p*2 ] = lazy[p];
		}
	}
	lazy[p] = 'X';
}
ll Q(ll p, ll L, ll R, ll i, ll j){
	if(lazy[p] != 'X'){
		propagate(p, R, L);
	}
	if( R < i || L > j) return 0;
	if( L >= i && R <=j) return st[p];
	ll a = Q(p * 2, L , (L + R) >> 1, i , j);
	ll b = Q(p * 2 + 1, ((L + R) >> 1) + 1, R, i , j);
	/*if(a == -1) return b;
	if(b == -1) return a;*/
	return (a + b);
}

void U(ll p, ll L, ll R, ll a, ll b, char v){
	// we update the node
	if(lazy[p] != 'X'){
		propagate(p, R, L);
	}
	if(L > b || R < a) return;
	if(L >= a && R <= b){
		// we update segment cause it belongs to general solution.
		if(v == 'E'){
			st[p] = 0;
		}
		if(v == 'F'){
			st[p] = (R - L + 1);
		}
		if(v == 'I'){
			ll len = R - L + 1;
			st[p] = len - st[p];
		}
		if(L != R){
			if(v == 'I'){
				changeState((2*p)+1);
				changeState(2*p);
			}else{
				lazy[2*p] = v;
				lazy[(2*p)+1] = v;
			}
		}
		return;
	}
	ll m = (L + R) >> 1;
	U(p*2, L, m, a , b, v);
	U(p*2 + 1, m + 1, R, a , b, v);
	st[p] = st[2*p]+ st[(2*p) + 1];
}
int main(){
	cin >> T;
	ll idx, Qu;
	for(ll i = 1; i <= T; i++){
		cout << "Case "<<i<<":"<<endl;
		cin >> M;
		in ="";
		idx = 0;
		X = 0;
		memset(A, sizeof(A),0);
		for(ll j = 0 ; j < M; j++){
			cin >> X;
			cin >> in;
			for(ll k = 0; k < X; k++){
				for(ll r = 0; r < in.size(); r++){
					if(in[r] == '0')
						A[idx++] = 0;
					else
						A[idx++] = 1;
				}
			}
		}
		cin >> Qu;
		char s;
		ll l, r;
		build(1, 0, idx - 1);
		ll ask = 0;
		for(ll j = 0; j < Qu; j++){
			cin >> s;
			cin >> l >> r;
			if(s == 'S'){
				cout <<"Q"<<++ask<<": "<< Q(1, 0, idx - 1, l , r) <<endl;
			}
			if(s == 'E'){
				U(1, 0, idx - 1, l, r, 'E');
			}
			if(s == 'F'){
				U(1, 0, idx - 1, l, r, 'F');
			}
			if(s == 'I'){
				U(1, 0, idx - 1, l, r, 'I');
			}
		}	
	}
	return 0;
}