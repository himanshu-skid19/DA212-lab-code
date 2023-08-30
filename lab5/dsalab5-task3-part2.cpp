#include <iostream>
using namespace std;
/* This is a simple example of queue at a food place like McDonalds. Here i have defined a node with two string elements which is the name of the customer, and the second data is the food he is ordering. You are the cashier and you task is to enter the customer's name and the food that they want to order and then that entry would be added to the queue. You can then dequeue whenever someone's food is ready.  */

class Node {
	public:
		Node *next;
		string name;
        string food;

		Node(){
			name = "";
            food = "";
			next = NULL;

		}

		Node(string name, string food) {
		this->name = name;
        this->food = food;
		this->next = NULL;
		}
};


class queue {
	Node *head;
	Node *tail;
	public:
		queue() {head = NULL; tail == NULL;}

		void IsEmpty(){
			if (head == NULL){
				printf("The queue is empty\n");
				return;
			}
			printf("The queue is not empty\n");
			return;
		}

		void enqueue(string name, string food){
			Node *new_node = new Node(name, food);
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
				cout << curr->name << " "<<curr->food << " ";
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

		void viewHead(){
            if (head == NULL) {
				cout << "queue is empty\n";
				return;
			}
            cout << head->name << " " << head->food << "\n";
        }
};

int main(void){
    queue q;
    int choice;
    cout << "Welcome to McDonalds!! What do you want to do??\n";
    while (choice != 5){
		cout << "Press 1 to place an Order\n";
		cout << "Press 2 to Dequeue an Order\n";
		cout << "Press 3 to view the queue \n";
		cout << "Press 4 to view the order at the front of the queue\n";
        cout << "Press 5 to exit the program\n";
		cin >> choice;

        switch(choice){
            case 1:
            {string name;
                string food;
                cout << "Enter the name of the customer: \n";
                cin >> name;
                cout << "Enter the food item they want to order: (do not use any whitespace) \n";
                cin >> food;
                q.enqueue(name, food);
                break;}
            case 2:
                q.dequeue();
                break;

            case 3:
                q.printqueue();
                break;

            case 4:
                q.viewHead();
                break;
            case 5:
                break;

        }
    }
}
