#include <iostream>
using namespace std;

class Node {
	public:
		Node *next;
		int data;

		Node(){
			data = NULL;
			next = NULL;

		}

		Node(int data) {
		this->data = data;
		this->next = NULL;
		}
};

class stack {
	Node *top;
	public:
		stack() {top = NULL;}

		void IsEmpty(){
			if (top == NULL){
				return 0;
			}
			printf("The stack is not empty\n");
			return 1;
		}

		void push(int data){
			Node *new_node = new Node(data);
			if (new_node == NULL) {cout << "Stack is full\n";}
			if (top == NULL){
				top = new_node;
				return;
			}
			Node *temp = top;
			top = new_node;
			top->next = temp;
			return;

		}

		void printstack() {
			Node *curr = top;

			if (top == NULL) {
				cout << "Stack is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << "\n";
		}

		void pop(){
			if (top == NULL) {cout << "The stack is empty\n"; return;}
			Node *temp = top;
			top = top->next;
			delete temp;
			return;
		}

		int get_top(){
			return top->data;
		}
};

class queue {
	Node *head;
	Node *tail;
	public:
		queue() {head = NULL; tail == NULL;}

		bool IsEmpty(){
			if (head == NULL){
				printf("The queue is empty\n");
				return 0;
			}
			printf("The queue is not empty\n");
			return 1;
		}

		void enqueue(int data){
			Node *new_node = new Node(data);
			if (head == NULL){
				head = new_node;
				return;
			}
			Node *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new_node;
			tail = new_node;
			return;

		}

		void printqueue() {
			Node *curr = head;

			if (head == NULL) {
				cout << "queue is empty\n";
				return;
			}
			while (curr != NULL) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << "\n";
		}

		void dequeue(){
			if (head == NULL) {cout << "The queue is empty\n"; return;}
			Node *temp = head;
			head = head->next;
			delete temp;
			return;
		}

		int front(){
			if (head == NULL){
				printf("Queue is empty\n");
				return 0;
			}
			return head->data;
		}
};

int main(void){
	// stack s;
 //
	// s.IsEmpty();
	// s.push(3);
	// s.push(4);
	// s.push(5);
	// s.push(6);
	// s.printstack();
	// s.pop();
	// s.pop();
	// s.printstack();

	queue q;

	q.IsEmpty();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.printqueue();

	q.dequeue();
	q.dequeue();
	q.printqueue();
	cout << q.front() << '\n';

}
