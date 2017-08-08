#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[505050], p[505050], N, M, x, y, marked[300], MM, ans, many[300], z;
ll find(ll u){
	return u == p[u] ? u : p[u] = find(p[u]);
}
void join(ll u , ll v){
	ll du = find(u);
	ll dv = find(v);
	if(du != dv){
		if(r[du] > r[dv])
			swap(du, dv);
		if(r[du] == r[dv])
			++r[dv];
		p[du] = dv;
		ans--;
	}
}
int main(){
	cin >> N >> M;
	ans = N;
	for(int i = 1; i <= N; i++)
		p[i] = i,  r[i] = 0;
	for(int i = 1; i <= M; i++)
		marked[i] = -1, many[i] = 0;
	for(int i = 1; i <= N; i++){
		cin >> MM;
		for(int j = 0; j < MM; j++){
			cin >> x;
			if(marked[x] == -1)
				marked[x] = i, many[i]++;
			join(marked[x], i);
		}
	}
	for(int i = 1; i <= N; i++){
		if(find(i) == i){
			if(many[i] == 0)
				z++;
		}
	}
	if(z != N)
		ans--;
	cout << ans << endl;

	
	return 0;
}
