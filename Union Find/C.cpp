#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[10101], r[10101], N, x, ans;
ll find(ll u){
	return u == parent[u] ? u : (parent[u] = find(parent[u]));
}
ll same(ll u, ll v){
	return find(u) == find(v);
}
void join(ll u, ll v){
	if(!same(u, v)){
		--ans;
		ll x = find(u);
		ll y = find(v);
		if(r[x] > r[y]) swap(x, y);
		parent[x] = y;
		if(r[x] == r[y]) ++r[y];
	}
}
int main(){
	cin >> N;
	ans = N;
	for(int i = 1; i <= N; i++) parent[i] = i, r[i] = 0;
	for(int i = 1; i <= N; i++){
		cin >> x;
		join(x, i);
	}
	cout << ans << endl;
	return 0;
	
}