// GIVEN LIST {7 8 1} = 187 and {5 5 3} = 3 5 5 that represent numbers sum them up.
#include <iostream>
#include <vector>
using namespace std;
struct node{
	int data;
	node* next;
	node(){
		next = NULL;
	}
	node(int x){
		data = x;
		next = NULL;
	}
};
struct List{
	node *head;
	List(){
		head = NULL;
	}
	void insertNode(node *X){
		node *tmp = head;
		if(tmp == NULL){
			head = X;
		}else{
			while(tmp -> next != NULL){
				tmp = tmp -> next;
			}
			tmp->next = X;
		}
	}
	void displayList(){
		node *tmp = head;
		while(tmp != NULL){
			cout << tmp -> data << " ";
			tmp = tmp -> next;
		}
		cout << endl;
	}
	int getNumber(){
		vector<int> numbers;
		node *tmp = head;
		while(tmp != NULL){
			numbers.push_back(tmp -> data);
			tmp = tmp -> next;
		}
		int ans = 0;
		for(int i = numbers.size() - 1; i >= 0; i--)
			ans = ans * 10 + numbers[i];
		return ans;
	}
};
List generateList(int K){
	vector<int> numbers;
	while(K){
		numbers.push_back(K % 10);
		K/=10;
	}
	reverse(numbers.begin(), numbers.end());
	List f;
	for(int i = numbers.size() - 1 ; i >= 0; i--){
		node *insert = new node(numbers[i]);
		f.insertNode(insert);
	}
	return f;
}
int main(){
	List l1;
	node *a = new node(7);
	node *b = new node(1);
	node *c = new node(6);
	l1.insertNode(a);
	l1.insertNode(b);
	l1.insertNode(c);
	List l2;
	node *d = new node(5);
	node *e = new node(9);
	node *f = new node(2);
	l2.insertNode(d);
	l2.insertNode(e);
	l2.insertNode(f);
	
	int dx = l1.getNumber();
	int dy = l2.getNumber();

	int result = dx + dy;
	List new_list = generateList(result);

	new_list.displayList();
	return 0;
}