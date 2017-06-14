#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p[10000], r[10000], N, Q, x, y, h[10000];
char o;
ll find(ll x){
	if(x == p[x])
		return x;
	return (p[x] = find(p[x]));
}
ll sameSet(ll x, ll y){
	return find(x) == find(y);
}
ll getNumberNodes(ll x){
	return h[find(x)];
}
void join(ll x, ll y){
	if(!sameSet(x,y)){
		ll dx = find(x);
		ll dy = find(y);
		if(r[dx] > r[dy]){
			// NOW representative of Y belongs TO X
			p[dy] = dx;
			// WE ADD THEM ALL the nodes from representative of Y to the Rep X.
			h[dx] += h[dy];
		}
		else{
			// the inverse of above.
			p[dx] = dy;
			h[dy] += h[dx];
			if(r[dx] == r[dy])
				r[dy]++;
		}
		N--;
	}
}
int main(){
	cin >> N;
	for(int i = 0 ; i <= N; i++)
		p[i] = i, r[i] = 0, h[i] = 1;
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> o;
		if(o == 'J'){
			cin >> x >> y;
			join(x, y);
		}
		if(o == 'F'){
			cin >> x;
			cout << find(x);
		}
		if(o == 'M'){
			cout << N << endl;
		}
		if(o == 'C'){
			cin >> x;
			cout << getNumberNodes(x)<<endl;
		}
	}
	return 0;
		
}