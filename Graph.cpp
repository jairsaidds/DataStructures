#include<vector>
#include<iostream>
#include<map>
using namespace std;
struct Graph{
	vector<vector<int> >G;
	map<int, int> mapping;
	int N;
	Graph(){

	}
	Graph(int n){
		N = n;
		cout << n << endl;
		G.resize(n);
	}
	void connect(int u, int v){
		G[u].push_back(v);
	}
	void dfs(int u){
		mapping[u] |= 1;
		for(int i = 0 ; i < G[u].size(); i++){
			int v = G[u][i];
			if(mapping.find(v) == mapping.end()){
				dfs(v);
			}
		}
	}
	void route(int u, int v){
		mapping.clear();
		dfs(u);
		if(mapping.find(v) == mapping.end()){
			cout << "There is no path from "<<u << " to "<< v << endl;
		}else{
			cout << "There is a path betweeen from u to v" << endl;
		}
	}
};
int main(){
	Graph myGraph(5 + 1);
	myGraph.connect(1, 2);
	myGraph.connect(2, 3);
	myGraph.connect(4, 5);
	myGraph.route(1, 3);
	myGraph.route(3, 1);
	myGraph.route(1, 4);
	myGraph.route(4, 5);
	myGraph.route(5, 4);

	

	return 0;
}