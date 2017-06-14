#include<bits/stdc++.h>
using namespace std;
#define INF (1 << 31) - 1
int V, E, X, Y;
int visited[19191], parent[12010];
stack<int>path;
struct node{
	node *left;
	node *right;
	int data;	
	node(){
		left = right = NULL;
	}
	node(int X){
		data = X;
		left = right = NULL;
	}
};
queue<node*>Q;
map<node*, int>dist;
vector<int>Lists[100];
vector<int>G[200];
void printTree(node *T){
	if(T == NULL)
		return;
	printTree(T -> left);
	cout << T -> data << endl;
	printTree(T -> right);
}
void converToList(node *T){
	dist[T] = 0;
	Lists[0].push_back(T->data);
	Q.push(T);
	int maxi = 0;
	while(!Q.empty()){
		node *u = Q.front(); Q.pop();
		if(u -> left != NULL){
			node *v = u -> left;
			if(dist.find(v) == dist.end()){
				dist[v] = dist[u] + 1;
				maxi = max(maxi, dist[v]);
				Lists[dist[v]].push_back(v -> data);
				Q.push(v);
			}
		}	
		if(u -> right != NULL){
			node *v = u -> right;
			if(dist.find(v) == dist.end()){
				dist[v] = dist[u] + 1;
				Lists[dist[v]].push_back(v -> data);
				Q.push(v);
				maxi = max(maxi, dist[v]);
			}
		}
	}
	for(int i = 0; i <= maxi; i++){
		for(int j = 0; j < Lists[i].size(); j++){
			cout << Lists[i][j]<< " ";
		}cout << endl;
	}
}
int isBinarySearchTree(node *T, int mini, int maxi){
	if(T == NULL)
		return 1;
	if(T -> data <= mini or T -> data > maxi)
		return 0;
	return isBinarySearchTree(T -> left, mini, T -> data) and 
	isBinarySearchTree(T -> right, T -> data, maxi);
}
node* getLCA(node *T, node *a, node *b){
	if(T == NULL)
		return NULL;
	if(T == a || T == b)
		return T;	
	node *X = getLCA(T -> left, a, b);
	node *Y = getLCA(T -> right, a, b);
	if(X != NULL && Y != NULL)
		return T;
	if(X == NULL and Y == NULL)
		return NULL;
	return (X == NULL ? Y : X);
}
int match(node *T1, node *T2){
	if(T2 == NULL && T1 == NULL)
		return 1;
	if(T1 == NULL || T2 == NULL)
		return 0; 
	return T1 -> data == T2 -> data and match(T1 -> left, T2 -> left) && match(T1 -> right, T2 -> right);
}
int isSubtree(node *T1, node *T2){
	if(T2 == NULL) return 1;
	if(T1 == NULL) return 0;
	if(T1 -> data == T2 -> data) {
		if(match(T1, T2))
			return 1;
	}
	return isSubtree(T1 -> left, T2) or isSubtree(T1 -> right, T2);
}

int isBalanced(node *root){
	if(root== NULL){
		return 0;
	}
	int leftH = isBalanced(root->left);
	if(leftH==-1){
		return -1;
	}
	int rightH = isBalanced(root->right);
	if(rightH==-1){
		return -1;
	}
	int diff = leftH-rightH;
	if(abs(diff) > 1){
		return -1;
	}
	return 1 + max(leftH, rightH);
}

int checkBalance(node *root){
	int result = isBalanced(root);
	if(result > 0){
		return 1;
	}else{
		return 0;
	}
}
void dfs(int u){
	visited[u] |= 1;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		parent[v] = u;
		if(!visited[v]){
			dfs(v);
		}
	}
}
void createBinarySearchTree(node *head, int value){
	if(value <= head -> data){
		if(head -> left == NULL)
			head -> left = new node(value);
		else
			createBinarySearchTree(head -> left, value);
	}else{
		if(head -> right == NULL)
			head -> right = new node(value);
		else
			createBinarySearchTree(head -> right, value);
	}
}
bool found(node *T, int X){
	if(T == NULL){
		return false;
	}
	path.push(T -> data);
	cout << "M "<< T -> data << endl;
	if(T -> data == X)
		return true;
	bool a = found(T -> left, X);
	bool b = found(T -> right, X);
	if(!(a | b))
		path.pop();
	return a | b;
}
void edit(node *T){
	T -> left = NULL;
	T -> right = NULL;
}
int count(node *T){
	if(T == NULL)
		return 0;
	return 1 + count(T-> left) + count(T->right);
}
bool isCompleteTree(node* T, int idx, int n){
	if(T == NULL)
		return true;
	if(idx >= n)
		return false;
	return isCompleteTree(T -> left, (idx << 1) + 1, n) and isCompleteTree(T -> right,  (idx << 1 ) + 2, n);
}
int main(){
	node *root = new node(1);
	root -> left = new node(3);
	root -> right = new node(11);
	root -> left -> left = new node(0);
	root -> right -> right = new node(12);
	root -> right -> left = new node(3);
	root -> right -> left -> left = new node(15);
	root -> right -> left -> right = new node(4);
	root -> right -> left -> right -> right = new node(7);
	root -> right -> left -> left -> left = new node(18);
	root -> right -> left -> left -> right = new node(2);
	node *R = new node(1);
	R -> left = new node(2);
	int n = count(R);
	cout << n << endl;
	cout << isCompleteTree(R, 0, n) << endl;

	/*
	node *B = new node(4);
	B -> left = new node(2);
	B -> right = new node(5);
	B -> left -> left = new node(1);
	B -> left -> right = new node(3);
	cout << isBinarySearchTree(B, -INF, INF) << endl;
	*/


	/*if(isSubtree(root, B)){
		cout << "B is subtree :)" << endl;
	}else{
		cout << "B is not subtree!"<< endl;
	}*/
	//int ans = isBinarySearchTree(root);
	//node *LCA = getLCA(root, root -> right -> left -> left -> right,  root -> left);
	//cout << LCA -> data << endl;
	/*node *root = new node(1);
	root -> left = new node(2);
	root -> left -> left = new node(4);
	root -> right = new node(3);
	root -> right -> right = new node(3);
	root -> right -> right -> left = new node(2);
	cout << isBalanced(root);*/
	/*node *root = new node(1);
	root -> left = new node(2);
	root -> left -> left = new node(3);
	root -> left -> left -> left = new node(5);
	root -> left -> right = new node(4);
	root -> right = new node(6);
	edit(root);
	printTree(root);

	node *sb = new node(5);
	//cout << subtree(root, sb) << endl;
*/
	//cout << isBinarySearchTree(R2)<< endl;
	return 0;
}