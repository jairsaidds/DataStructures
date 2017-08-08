#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[101010], p[101010], b[101010], N, A[101010], m[101010], f[101010], solve[101010];
ll find(ll u){
	return u == f[u] ? u : f[u] = find(f[u]);
}
void join(ll u , ll v){
	ll du = find(u);
	ll dv = find(v);
	if(du != dv){
		if(r[du] > r[dv])
			swap(du, dv);
		if(r[du] == r[dv])
			++r[dv];
		f[du] = dv;
		m[dv] += m[du];
	}
}
int main(){
	cin >> N;
	for(int i = 0 ; i < N; i++)
		cin >> A[i];
	for(int i = 0 ; i < N; i++){
		f[i] = i, r[i] = 0, b[i] = 1, m[i] = A[i];
		cin >> p[i];
		--p[i];
	}
	solve[N - 1] = 0;
	b[p[N - 1]] = 0;
	ll maxi = m[p[N - 1]];
	for(int i = N - 2 ; i >= 0 ; i--){
		if(p[i] + 1 <= N - 1 && !b[p[i] + 1])
			join(p[i] , p[i] + 1);
		if(p[i] - 1 >=0 &&  !b[p[i] - 1]) 
			join(p[i] , p[i] - 1);
		b[p[i]] &= 0;
		solve[i] = maxi;
		maxi = max(maxi , m[find(p[i])]);
	}
	for(int i = 0; i < N; i++){
		cout << solve[i] << endl;
	}

}