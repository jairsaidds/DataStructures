#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L(X) (X * 2)
#define R(X) ((X * 2) + 1)
struct node{
	ll ans;
	ll o; 
	ll c;
}A[4000000];
string in;
void build(ll p, ll l, ll r){
	A[p].ans = A[p].o = A[p].c = 0;
	if(l == r){
		if(in[l] == '(')
			A[p].o = 1;
		else
			A[p].c = 1;
 	}else{
 		ll m = (l + r) >> 1;
 		build(L(p), l , m);
 		build(R(p), m + 1, r);
 		ll dx = min(A[L(p)].o, A[R(p)].c);
 		A[p].ans = A[L(p)].ans + A[R(p)].ans + dx;
 		A[p].o = A[L(p)].o + A[R(p)].o - dx;
 		A[p].c = A[L(p)].c + A[R(p)].c - dx;
 	}
}
node F(ll p, ll l, ll r, ll a, ll b){
	if(r < a || l > b){
		node x;
		x.o = x.c = 0;
		x.ans = -1;
		return x;
	}
	if(l >= a && r <= b){
		node y;
		y.ans = A[p].ans;
		y.o   = A[p].o;
		y.c   = A[p].c;
		return y;
	}
	ll m = (l + r) >> 1;
	node i = F(L(p), l , m, a , b);
	node d = F(R(p), m + 1, r, a , b);
	if(i.ans == -1) return d;
	if(d.ans == -1) return i;
	node chido;
	ll dy = min(i.o, d.c);
	chido.ans = i.ans + d.ans + dy;
	chido.o   = i.o   + d.o   - dy;
	chido.c   = i.c   + d.c   - dy;
	return chido;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> in;
	build(1, 0, in.size() - 1);
	ll X, l , r;
	cin >> X;
	for(int i = 0; i < X; i++){
		cin >> l >> r;
		l--;
		r--;
		cout << F(1, 0, in.size() - 1, l, r).ans * 2 << endl;
	}
	return 0;
}