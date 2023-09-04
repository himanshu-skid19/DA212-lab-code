#include <iostream>
#include <chrono>
#include <stack>
#include <queue>

using namespace std;
using namespace std::chrono;


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

class Stack {
	Node *top;
	public:
		Stack() {top = NULL;}

		int IsEmpty(){
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

class Queue {
	Node *head;
	Node *tail;
	public:
		Queue() {head = NULL; tail == NULL;}

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
    Stack s1;
	 int n = 1;
	 cout << "Perfomance of my Implementation of Stacks: \n";
	 cout << "\n";
	 while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 s1.push(0);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by my function to push " << n <<" elements in stack is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}

	n = 1;
	cout << "\n";
	while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 s1.pop();
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by my function to pop " << n <<" elements in stack is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}


	stack<int> s2;
	cout << "\n";
	cout << "Perfomance of the STL function: \n";
	cout << "\n";
	n = 1;
	 while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 s2.push(0);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by STL function to push " << n <<" elements in stack is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}

	n = 1;
	cout << "\n";
	while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 s2.pop();
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by STL function to pop " << n <<" elements in stack is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}



	Queue q1;
	cout << "\n";
	cout << "Perfomance of my Queue Implementation: \n";
	cout << "\n";
	n = 1;
	 while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 q1.enqueue(0);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by my function to enqueue " << n <<" elements is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}

	n = 1;
	cout << "\n";
	while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 q1.dequeue();
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by my function to dequeue " << n <<" elements is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}

	queue<int> q2;
	cout << "\n";
	cout << "Perfomance of the STL Queue Implementation: \n";
	cout << "\n";
	n = 1;
	 while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 q2.push(0);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by STL function to enqueue " << n <<" elements is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}

	n = 1;
	cout << "\n";
	while (n <= 100000){
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 q2.pop();
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by STL function to dequeue " << n <<" elements is: "
         << duration.count() << " nanoseconds" << endl;
		n = n*10;
	}

}
