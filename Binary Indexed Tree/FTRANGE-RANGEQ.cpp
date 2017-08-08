#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N, X, Y, V, Q, A[101010];
vector<ll>ft1, ft2;
string T;
void up(vector<ll>&ft, ll idx, ll v){
	while(idx <= N){
		ft[idx] += v;
		idx += (idx & -idx);
	}
}
void up(ll a, ll b, ll v){
	up(ft1, a , v);
	up(ft1, b + 1, -v);
	up(ft2, a, v * (a - 1));
	up(ft2, b + 1, -v * b);
}

ll down(vector<ll>&ft, ll idx){
	ll ans = 0;
	while(idx){
		ans += ft[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
ll down(ll idx){
	return down(ft1, idx) * idx - down(ft2, idx);
}
ll down(ll a, ll b){
	return down(b) - down(a - 1);
}
int main(){
	cin >> N;
	ft1.assign(N + 1, 0);
	ft2.assign(N + 1, 0);
	for(int i = 0; i < N; i++){
		cin >> A[i];
		up( i + 1,  i + 1, A[i]);
	}
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> T;
		if(T == "RU"){
			cin  >> X >> Y >> V;
			up(X, Y, V);
		}
		if(T == "RQ"){
			cin >> X >> Y;
			cout << down(X, Y) << endl;
		}
	}
	return 0;
}