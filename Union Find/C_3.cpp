#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p[401010], x, y, N, M, w, a[401010];
ll get(ll u){
	return u == p[u] ? u : p[u] = get(p[u]);
}
void join(ll u, ll v){
	ll du = get(u);
	ll dv = get(v);
	if(dv != du)
		p[du] = dv;
}
int main(){
	cin >> N >> M;
	for(int i = 1; i <= N + 1; i++)
		p[i] = i;
	for(int i = 0; i < M; i++){
		cin >> x >> y >> w;
		for(int j = get(x); j <= y; j = get(j + 1)){
			if(j != w){
				a[j] = w;
				join(j, j + 1);
			}
		}
	}
	for(int i = 1; i <= N; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}