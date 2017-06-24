#include<bits/stdc++.h>
using namespace std;
#define ll long long
double st[10000];
double A[10000];
ll N, Q;
void up(ll i, double v){
	while(i <= N)
		st[i]+=v, i+=(i&-i);
	return;
}
double down(ll p){
	double ans = 0;
	while(p)
		ans+=st[p],p-=(p & -p);
	return ans;
}
double down(ll a, ll b){
	return down(b) - (a == 1 ? 0 : down(a - 1));
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i] , up( i + 1, A[i]);
	cout << down(N) << endl;
	cout << down(2, 3) << endl;
}
