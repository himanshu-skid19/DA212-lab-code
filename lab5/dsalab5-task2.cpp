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

		int IsEmpty(){
			if (top == NULL){
				return 0;
			}
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
				return 0;
			}
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

		int get_front(){
			return head->data;
		}
};

class stack_using_queues{
    queue q1, q2;
    public:

        void push(int data){
            q2.enqueue(data);

            while (q1.IsEmpty() != 0){
                q2.enqueue(q1.get_front());
                q1.dequeue();
            }

            queue q = q1;
            q1 = q2;
            q2 = q;
        }

        void pop(){
            if (q1.IsEmpty() == 0)
                return;
            q1.dequeue();
        }

        int get_top(){
            if (q1.IsEmpty() == 0)
                return -1;
            return q1.get_front();
        }

        void printstack(){
            q1.printqueue();
            return;
        }
};

class queue_using_stacks{
    stack s1, s2;
    public:
        void enqueue(int data){
            while (s1.IsEmpty() == 1){
                s2.push(s1.get_top());
                s1.pop();

            }

            s1.push(data);

            while (s2.IsEmpty() == 1){
                s1.push(s2.get_top());
                s2.pop();
            }
        }

        void dequeue(){
            if (s1.IsEmpty() == 0){
                cout << "The queue is empty\n";
                return;
            }

            s1.pop();
            return;
        }

        void printqueue(){
            s1.printstack();
        }

        int get_front(){
            if (s1.IsEmpty() == 0)
                return -1;
            return s1.get_top();
        }

};


int main(){
    // Showcase of stacks using 2 queues
    cout << "Stack Using 2 Queues\n";
    stack_using_queues s;
    s.push(1);
    s.push(2);
    cout << s.get_top() << "\n";
    s.printstack();
    s.push(3);
    s.push(4);
    s.printstack();
    s.pop();
    s.printstack();

    cout << "Queue using 2 Stacks\n";
    queue_using_stacks q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.get_front() << "\n";
    q.enqueue(3);
    q.enqueue(4);
    q.printqueue();
    q.dequeue();
    q.printqueue();


}
