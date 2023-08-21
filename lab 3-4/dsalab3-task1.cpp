#include <iostream>
using namespace std;

class Node {
	public:
		Node *next;
		Node *prev;
		int data;
		
		Node(){
			data = NULL;
			next = NULL;
			prev = NULL;
		}
		
		Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
		} 
};

class linked_list {
	Node *head;
	public:
		linked_list() {head = NULL;}
		
		void InsertNode(int data, int pos){
			Node *new_node = new Node(data);
			if (head == NULL){
				cout << "linked list is empty so adding your node as head\n";
				head = new_node;
				return;
			}
			else if (head !=NULL && pos == 1){
				Node *temp = head;
				head = new_node;
				head->next = temp;
				return;
			}
			
			int iter = 2;
			Node *curr = head;
			while (curr != NULL && iter < pos){
				iter++;
				curr = curr->next;
			}
			Node *temp = curr;
			new_node->next = curr->next;
			temp->next = new_node;
			return;
			
			
			
		}
		
		void printlist() {
			Node *curr = head;
			
			if (head == NULL) {
				cout << "List is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->next; 
			}
			cout << "\n";
		}
		
		void delete_node(int pos){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			int len = 0;
			Node *curr = head;
			
			while (curr != NULL) {
				curr = curr->next;
				len++;
			}
			
			if (len < pos) {cout << "position out of range\n"; return;}
			
			Node *temp = head;
			if (pos == 1){
				head = head->next;
				delete temp;
				return;
			}
			
			int iter = 2;
			while (temp != NULL && iter < pos){
				temp = temp->next;
				iter++;
			}
			
			Node *temp1 = temp;
			temp = temp->next;
			temp1->next = temp->next;
			delete temp;
			
		}
		
		void search(int data){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			Node *curr = head;
			int iter = 1;
			while (curr != NULL && curr->data != data) {
				curr = curr->next;
				iter++;
			}
			if (curr == NULL) {cout << "Not found\n"; return;}
			
			cout << "element found at position " << iter << "\n";
			
		}
};

class doubly_linked_list {
	Node *head;
	Node *tail;
	public:
		doubly_linked_list() {head = NULL;}
		
		void InsertNode(int data, int pos){
			Node *new_node = new Node(data);
			if (head == NULL){
				cout << "linked list is empty so adding your node as head\n";
				head = new_node;
				tail = new_node;
				return;
			}
			else if (head !=NULL && pos == 1){
				Node *temp = head;
				head = new_node;
				head->next = temp;
				temp->prev = head;
				Node *curr = head;
				while (curr->next != NULL){
					curr = curr->next;
				}
				tail = curr;
				return;
			}
			
			int iter = 2;
			Node *curr = head;
			while (curr != NULL && iter < pos){
				iter++;
				curr = curr->next;
			}
			Node *temp = curr;
			new_node->next = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
			if (new_node->next != NULL) {
				new_node->next->prev = new_node;
			}
			while (curr->next != NULL){
				curr = curr->next;
			}
			tail = curr;
			return;
			
		
						
		}
		
		void printlist() {
			Node *curr = head;
			
			if (head == NULL) {
				cout << "List is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->next; 
			}
			cout << "\n";
		}
		
		void printlistReverse() {
			Node *curr = tail;
			
			if (tail == NULL) {
				cout << "List is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->prev;
			}
			cout << "\n";
		}
		
		void delete_node(int pos){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			int len = 0;
			Node *curr = head;
			
			while (curr != NULL) {
				curr = curr->next;
				len++;
			}
			
			if (len < pos) {cout << "position out of range\n"; return;}
			
			Node *temp = head;
			if (pos == 1){
				head = head->next;
				head->prev = NULL;
				delete temp;
				return;
			}
			
			int iter = 2;
			while (temp != NULL && iter < pos){
				temp = temp->next;
				iter++;
			}
			
			Node *temp1 = temp;
			temp = temp->next;
			temp1->next = temp->next;
			(temp->next)->prev = temp1;
			delete temp;
			
		}
		
		void search(int data){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			Node *curr = head;
			int iter = 1;
			while (curr != NULL && curr->data != data) {
				curr = curr->next;
				iter++;
			}
			if (curr == NULL) {cout << "Not found\n"; return;}
			
			cout << "element found at position " << iter << "\n";
			
		}
};

class circular_linked_list {
	Node *head;
	Node *tail;
	public:
		circular_linked_list() {head = NULL; tail = NULL;}
		
		void InsertNode(int data, int pos){
			Node *new_node = new Node(data);
			if (head == NULL){
				cout << "linked list is empty so adding your node as head\n";
				head = new_node;
				tail = new_node;
				return;
			}
			else if (head !=NULL && pos == 1){
				Node *temp = head;
				head = new_node;
				head->next = temp;
				tail->next = head; 
				return;
			}
		
			int iter = 2;
			Node *curr = head;
			while (curr->next != head && iter < pos) {
				iter++;
				curr = curr->next;
			} 
			Node *temp = curr;
			new_node->next = curr->next;
			curr->next = new_node;
			while (curr != head){
				curr = curr->next;
			}
			tail = curr;
			return;
			
			
			
		}
		
		void printlist() {
			Node *curr = head;
			
			if (head == NULL) {
				cout << "List is empty\n";
				return;
			}
			
			if (head->next == NULL){
				cout << curr->data << " ";
				return;
			}
			
			do {
				cout << curr->data << " ";
				curr = curr->next; 
			}
			while (curr != head);
			cout << "\n";
		}
		
		void delete_node(int pos){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			int len = 0;
			Node *curr = head;
			do {
				curr = curr->next;
				len++;
			}
			while (curr != head);
			
			if (len < pos) {cout << "position out of range\n"; return;}
			
			Node *temp = head;
			if (pos == 1){
				head = head->next;
				delete temp;
				return;
			}
			
			int iter = 2;
			do {
				temp = temp->next;
				iter++;
			}
			while (temp != NULL && iter < pos);
			
			Node *temp1 = temp;
			temp = temp->next;
			temp1->next = temp->next;
			delete temp;
			
		}
		
		void search(int data){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			Node *curr = head;
			if (head->data == data){
				cout << "element found at position 1 \n";
				return;
			}
			
			int iter = 1;
			do {
				curr = curr->next;
				iter++;
			}
			while (curr != head && curr->data != data);
			if (curr == head) {cout << "Not found\n"; return;}
			
			cout << "element found at position " << iter << "\n";
			
		}
};

int main() {

	//Implementation of the various functions in linked list
	linked_list list1;
	
	list1.InsertNode(2,1);
	list1.InsertNode(4,1);
	list1.InsertNode(5,1);
	list1.InsertNode(6,2);
	list1.InsertNode(7,3);
	list1.InsertNode(9,4);
	list1.printlist();
	list1.delete_node(3);
	
	list1.printlist();
	
	list1.search(6);
	list1.search(7);
	list1.search(9);
	list1.search(5);
	
	//Implementation of the various functions in doubly linked list
	doubly_linked_list list2;
	
	list2.InsertNode(2,1);
	list2.InsertNode(4,1);
	list2.InsertNode(5,1);
	list2.InsertNode(6,2);
	list2.InsertNode(7,3);
	list2.InsertNode(9,4);
	list2.printlist();
	list2.printlistReverse();
	list2.delete_node(3);
	list2.printlist();
	list2.printlistReverse();
	list2.search(6);
	list2.search(7);
	list2.search(9);
	list2.search(5);
	
	//Implementation of the various functions in circular linked list
	circular_linked_list list3;
	
	list3.InsertNode(2,1);
	list3.InsertNode(4,1);
	list3.InsertNode(5,1);
	list3.InsertNode(6,2);
	list3.InsertNode(7,3);
	list3.InsertNode(9,4);
	list3.printlist();
	list3.delete_node(3);
	list3.printlist();
	list3.search(6);
	list3.search(7);
	list3.search(9);
	list3.search(5);
	

	return 0;	
}
