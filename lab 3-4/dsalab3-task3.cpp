#include <iostream>
#include <chrono>
#include <list>
#include <forward_list>

using namespace std;
using namespace std::chrono;

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


int main(void){
    doubly_linked_list list1;

    auto start1 = high_resolution_clock::now();
    list1.InsertNode(2,1);
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cout << duration.count() << endl;
    cout << "Time taken by my function to insert in doubly linked list is: "
         << duration.count() << " microseconds" << endl;

    list<int> list2;
    list<int>::iterator it = list2.begin();
    advance(it, 0);

    auto start2 = high_resolution_clock::now();
    list2.insert(it, 2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << duration2.count() << endl;
    cout << "Time taken by the STL function to insert in doubly linked list is: "
         << duration2.count() << " microseconds" << endl;

    linked_list list3;

    auto start3 = high_resolution_clock::now();
    list3.InsertNode(2,1);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << duration3.count() << endl;
    cout << "Time taken by my function to insert in single linked list is: "
         << duration3.count() << " microseconds" << endl;

    forward_list<int> list4;
    forward_list<int>::iterator it2 = list4.begin();
    advance(it2, 0);

    auto start4 = high_resolution_clock::now();
    list4.push_front( 2);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << duration4.count() << endl;
    cout << "Time taken by the STL function to insert in single linked list is: "
         << duration4.count() << " microseconds" << endl;

}
