#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;
int put[1001000];
struct node{
	int data;
	node *next;
	node(){
		next = NULL;
	}
	node(int X){
		next = NULL;
		data = X;
	}
};   
struct List{
	node *head;
	List(){
		head = NULL;
	}
	void insertNode(node * X){
		node *tmp = head;
		if(head == NULL){
			head = X; 
		}else{
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp -> next = X;
		}
	}
	void deleteNode(int f){
		node *c, *p;
		c = p = head;
		if(c -> data == f){
			head = head -> next;
			delete c;
		}else{
			c = c -> next;
			while(c != NULL){
				if(c -> data == f){
					p -> next = c -> next;
					delete c;
				}
				p = c;
				c = c -> next;
			}
		}
	}
	void deleteGivenNode(node *f){
		node *c, *p;
		c = p = head;
		if(head == f){
			head = head -> next;
			delete c;
		}else{
			while(c != NULL){
				if(c == f){			
					p -> next = c -> next;
					delete c;
					break;
				}
				p = c;
				c = c -> next;
			}
		}
	}
	void printList(){
		node *tmp = new node;
		tmp = head;
		if(tmp == NULL){
			cout << "No elements in the list"<<endl;
		}
		while(tmp != NULL){
			cout << tmp->data << " ";
			tmp = tmp -> next;
		}
		cout << endl;
	}
	int countElements(){
		int ans = 0;
		node *temp = head;
		while(temp != NULL){
			ans ++;
			temp = temp -> next;
		}
		return ans;
	}
	int hasCycle(){
		//HASHING
		map<node *, int> mapa;
		node *tmp = head;
		while(tmp != NULL){
			if(mapa.find(tmp) == mapa.end()){
				mapa[tmp] = 1;
			}else{
				return 1;
			}
			tmp = tmp -> next;
		}
		return 0;
	}
	node* getFirstCycle(){
		node *slow, *fast;
		node *meeting_point;
		meeting_point = NULL;
		slow = fast = head;
		while(slow != NULL && fast != NULL && (fast -> next) != NULL ){
			slow = slow -> next;
			fast = fast -> next -> next;
			if(slow == fast){
				meeting_point = slow;
				break;
			}
		}
		if(meeting_point == NULL){
			return meeting_point;
		}
		slow = head;
		while(1){
			slow = slow -> next;
			fast = fast -> next;
			if(slow == fast)
				return slow;
		}
	}
	int getCycleLength(node *start){
		node *tmp = start;
		int ans = 1;
		tmp = tmp -> next;
		while(tmp != start){
			++ans;
			tmp = tmp -> next;
		}
		return ans;
	}
	void editNode(int pos, int value){
		node *tmp = head;
		for(int i = 0; i < pos - 1; i++){
			tmp = tmp -> next;
		}
		tmp -> data = value;
	}
	void rremoveDuplicates(){
	    node *ptr1, *ptr2, *dup;
	    ptr1 = head;
	    while (ptr1 != NULL && ptr1->next != NULL){
	        ptr2 = ptr1;
	        while (ptr2->next != NULL){
	            if (ptr1->data == ptr2->next->data){
	                dup = ptr2->next;
	                ptr2->next = ptr2->next->next;
	                delete(dup);
	            }
	            else 
	                ptr2 = ptr2->next;
	        }
	        ptr1 = ptr1->next;
	    }
	}
	void removeKTHNode(node *kth){
		node *N = kth -> next;
		kth -> data = N -> data;
		kth -> next = N -> next;
		delete kth -> next;
	}
};

void removeDuplicates(node *start){
    unordered_set<int> myset;
    node *curr = start;
    node *prev = NULL;
    while (curr != NULL){
        if (myset.find(curr->data) != myset.end()){
           prev->next = curr->next;
           delete (curr);
        }
        else{
           myset.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}
List removeDuplicates(List X){
	List new_list;
	node *tmp = X.head;
	while(tmp != NULL){
		if(!put[tmp -> data]){
			node *toAdd = new node(tmp ->data);
			++put[tmp->data];
			new_list.insertNode(toAdd);
		}
		tmp = tmp -> next;
	}
	return new_list;
}
int getKTH(List a , int K){
	node *head = a.head;
	node *c, *p;
	c = p = head;
	for(int i = 0 ; i < K; i++)
		c = c -> next;
	while(c != NULL){
		c = c -> next;
		p = p -> next;
	}
	return p -> data;
}

int main(){
	node *a = new node(1);
	node *b = new node(7);
	node *c = new node(5);
	node *d = new	 node(4);
	node *e = new node(1);
	node *f = new node(5);
	
	/*node *f = new node(7);
	node *g = new node(7);*/

	List mylist;
	mylist.insertNode(a);
	mylist.insertNode(b);
	mylist.insertNode(c);
	mylist.deleteNode(1);
	mylist.printList();
	mylist.deleteGivenNode(c);
	mylist.printList();
	//cout << getLength(mylist) << endl;
	mylist.insertNode(d);
	mylist.insertNode(e);
	mylist.insertNode(f);
	mylist.printList();
	mylist.removeKTHNode(d);
	mylist.printList();
	/*cout << getKTH(mylist,2)<< endl;
	List withoutDuplicates = removeDuplicates(mylist);
	withoutDuplicates.printList();
	mylist.printList();
	mylist.editNode(4, 5);
	mylist.printList();*/
}