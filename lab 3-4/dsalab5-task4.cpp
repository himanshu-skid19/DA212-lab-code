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

    auto start1 = high_resolution_clock::now();
    s1.push(1);
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop1 - start1);
    cout << duration.count() << endl;
    cout << "Time taken by my function to insert in stack is: "
         << duration.count() << " nanoseconds" << endl;

    stack<int> s2;

    auto start2 = high_resolution_clock::now();
    s2.push(1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << duration2.count() << endl;
    cout << "Time taken by the STL function to insert in stack: "
         << duration2.count() << " nanoseconds" << endl;

	Queue q1;

    auto start3 = high_resolution_clock::now();
    q1.enqueue(1);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
    cout << duration3.count() << endl;
    cout << "Time taken by my function to insert in queue is: "
         << duration3.count() << " nanoseconds" << endl;

    queue<int> q2;
    auto start4 = high_resolution_clock::now();
    q2.push(1);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
    cout << duration4.count() << endl;
    cout << "Time taken by the STL function to insert in single linked list is: "
         << duration4.count() << " nanoseconds" << endl;



}
