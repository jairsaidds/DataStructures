#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ft[1010101], N, A[1010101], X, Y, V, Q;
char T;
ll down(ll idx){
	ll ans = 0;
	while(idx){
		ans += ft[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
void up(ll idx, ll v){
	while(idx <= N){
		ft[idx] += v;
		idx += (idx & -idx);
	}
}
void up(ll a, ll b, ll v){
	up(a, v);
	up(b + 1, -v);
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		up( i + 1, i + 1,  A[i]);
	}
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> T;
		if(T == 'Q'){
			cin >> X;
			cout << down(X) << endl;
		}else{
			cin >> X >> Y >> V;
			up(X, Y, V);
		}
	}
	return 0;
}