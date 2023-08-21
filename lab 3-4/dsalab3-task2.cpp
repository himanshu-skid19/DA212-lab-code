#include <iostream>
#include <string.h>

//Welcome to this program!! You are a space explorer who is starting his journey from Earth to explore the stars. You have made this program for the purpose of noting down 
// objects of interest. You plan to explore the galaxy and eventually return to earth. But being alone in space for so long can sometimes make you see things that arent there!! which is why there 
//might be some entries you made that are false which you might want to delete or maybe you missed some OOI and noticed it in your spacehip's logs, which is when you might wanna insert that in your 
// linked list. For this purpose, we shall be using a circular linked list to implement this since you will eventually return to Earth.

using namespace std;

class Node {
	public:
		Node *next;
		Node *prev;
		string date;
		string OOI;
		
		Node(){
			next = NULL;
			prev = NULL;
		}
		
		Node(string date, string OOI) {
		this->date = date;
		this->OOI = OOI;
		this->next = NULL;
		this->prev = NULL;
		} 
};

class circular_linked_list {
	Node *head;
	Node *tail;
	public:
		circular_linked_list() {head = NULL; tail = NULL;}
		
		void InsertNode(string date, string OOI, int pos){
			Node *new_node = new Node(date, OOI);
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
				cout << curr->date << " " << curr->OOI << " \n";
				return;
			}
			
			do {
				cout << curr->date <<" "<< curr->OOI << " \n";
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
		
		void search(string OOI){
			if (head == NULL) {cout << "list is empty\n"; return;}
			
			Node *curr = head;
			if (head->OOI == OOI){
				cout << "element found at position 1 \n";
				return;
			}
			
			int iter = 1;
			do {
				curr = curr->next;
				iter++;
			}
			while (curr != head && curr->OOI != OOI);
			if (curr == head) {cout << "Not found\n"; return;}
			
			cout << "element found at position " << iter << "\n";
			
		}
};

int main(void){
	circular_linked_list log;
	int input;

	cout << "Greetings!! Welcome to the Starship Enceladus logs. The time is 23:00 on 21 Aug 2077 and we have just left Earth. As we proceed further into our journey, you will encounter objects of interest that you are supposed to fill in to this log. All the instructions to use the log are given below \n";
	while (input != 4){
		cout << "Enter 1 to Insert a new entry:\n";
		cout << "Enter 2 to display the log\n";
		cout << "Enter 3 to delete an entry in the log\n";
		cout << "Enter 4 to search for an entry in the log\n";
		cout << "What do you want to do? \n";
		cin >> input;

		string date, OOI;
		switch (input){
			case 1:
				cin.ignore();
				cout << "Enter the date in the format 1 Jan 1999: \n";
				getline(cin, date);

				cout << "Enter the name of the object of interest: \n";
				getline(cin, OOI);
				log.InsertNode(date, OOI, 1);
				break;
			case 2:
				log.printlist();
				break;
			case 3:
				int pos;
				cout << "Enter the log entry number you want to delete: \n";
				cin >> pos;
				log.delete_node(pos);
				break;
		}
	}

}

