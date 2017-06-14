  #include<iostream>
#include<vector>
using namespace std;
struct node{
	node *next;
	int data;
	node(){
		next = NULL;
		cout << "what";
	}
	node(int X){
		data = X;
		next = NULL;
	}
};
struct Stack{
	node *head;
	Stack(){
		head = NULL;
	}
	void push(node *x){
		node *tmp;
		if(head == NULL){
			head = x;
		}else{
			tmp = head;
			head = x;
			head -> next = tmp;
		}
	}
	void pop(){
		head = head -> next;
	}
	int top(){
		return head->data;
	}
	void printStack(){
		node *tmp;
		tmp = head;
		while(tmp != NULL){
			cout << tmp -> data << " ";
			tmp = tmp -> next;
		}
		cout << endl;
	}
	int getSize(){
		int ans = 0;
		node *tmp;
		tmp = head;
		while(tmp != NULL){
			ans ++;
			tmp = tmp -> next;
		}
		return ans;
	}
	int isEmpty(){
		return head == NULL;
	}
};
struct StackSet{
	int maximum;
	int insertIn;
	vector<Stack>myset;
	StackSet(){
		Stack st;
		myset.push_back(st);
		insertIn = 0;
	}
	StackSet(int f){
		Stack st;
		myset.push_back(st);
		f = maximum;
		insertIn = 0;
	}
	int sizeOfStack(int idx){
		return myset[idx].getSize();
	}
	void push(int idx){
		if(sizeOfStack(insertIn) == maximum){
			insertIn++;
			Stack st;
			myset.push_back(st);
		}
		myset[insertIn].push(new node(idx));
	}
	void pop(){
		if(sizeOfStack(insertIn) == 0){
			if(insertIn == 0){
				cout << "VACIA" << endl;
			}else{
				insertIn--;
				myset[insertIn].pop();
			}
		}
	}
};
Stack sortStack(Stack toSort){	
	Stack ans;
	while(toSort.getSize() > 0){
		int u = toSort.top(), v;
		toSort.pop();
		while(ans.getSize() > 0 and (v = ans.top()) > u){
			toSort.push( new node(v));
			ans.pop();
		}
		ans.push(new node(u));
	}
	return ans;
}
int main(){
	Stack st;
	node *a = new node(90);
	node *b = new node(-8);
	node *c = new node(7);
	node *d = new node(-6);
	node *e = new node(5);
	node *f = new node(14);
	node *g = new node(-3);
	node *h = new node(2);
	node *i = new node(1);
	node *j = new node(-8);
	st.push(a);
	st.push(b);
	st.push(c);
	st.push(d);
	st.push(e);
	st.push(f);
	st.push(g);
	st.push(h);
	st.push(i);
	st.push(j);
	Stack ordered = sortStack(st);
	ordered.printStack();
	
	
	return 0;
}