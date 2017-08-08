#include<bits/stdc++.h>
using namespace std;
#define ll int
ll p[503030], t, N, Q, x, y, nxt[505050];
inline ll find(ll u){
	return u == p[u] ? p[u] : p[u] = find(p[u]);
}

inline void join(int u, int v){
	if(find(u) != find(v)){
		int du = find(u);
		int dv = find(v);
		p[du] = dv; 
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
		p[i] = i, nxt[i] = i + 1;
	for(int i = 0; i < Q; i++){
		cin >> t;
		cin >> x >> y;
		if(t == 1){
			join(x , y);
		}
		if(t == 2){
			ll next;
			for(int j = x ; j < y; j = next){
				join(j, y);
				next = nxt[j];
				nxt[j] = nxt[y];
			}
		}
		if(t == 3){
			if(find(x) == find(y))
				cout << "YES" << endl;
			else
				cout << "NO" << endl; 
		}
	}
	return 0;
}