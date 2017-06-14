#include<iostream>
#define MAXN 100000
#define ll long long 
using namespace std;
int tree[MAXN], N, Q, x, y;
void up(ll idx, ll v){
	for( ;idx <= N;idx += (idx & -idx))
		tree[idx] += v;
}
ll down(ll idx){
	ll ans = 0;
	for( ; idx > 0 ; idx -= (idx & -idx))
		ans += tree[idx];
	return ans;
}
int main(){
	cin >> N;
	for(int i = 0; i <= N; i++)
		tree[i] = 0;
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> x >> y;
		up(x, 1), up(y + 1, - 1);
	}
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> x;
		cout << "Intersections:_ "<< x << " " << down(x) << endl;
	}
	return 0;
}