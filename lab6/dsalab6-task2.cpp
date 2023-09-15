#include <iostream>
#include <string.h>

// Hello, This program is simple password manager that securely stores your password and verifies later if your password is valid or not. Note, the password must only contain numbers. Since this is a password storing application, an application can have more than one stored password but the validity depends on the application itself and does not concern the password manager*//

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


class hash_table {
    int m;
    int *table;
    string *name;

	struct chain{
		int data;
		chain* next;
	};
	chain **head;
    public:
        hash_table() {m = 0; table = nullptr; head = nullptr; name = nullptr;}
        void initialize(int length){
            m = length;
            table = new int[m];
			head = new chain*[m];
            name = new string[m];
            for (int i = 0; i < m; i++) {
                table[i] = -1;
				head[i] = nullptr;
                name[i] = "";
			}
		}
        int hash(int k){
            return k % m;
        }

        void insert(string app, int k){
            int index = hash(k);
			if (table[index] == -1){
				if (index >= 0 && index < m) {
                table[index] = k;
                name[index] = app;
				}
				else {
                cout << "Index out of bounds\n";
				}
			}
			else {
				if (head[index] == nullptr) {
					head[index] = new chain; // Create a new chain node
					head[index]->data = k;
					head[index]->next = nullptr;
				}
				else {
					chain* newNode = new chain;
					newNode->data = k;
					newNode->next = head[index];
					head[index] = newNode;
				}
			}
		}

        void search(string app){
            for (int i = 0; i < m; i++){
                if (name[i] == app){
                    cout << table[i] << "\n";
                    return;
                }
            }
            cout << "Not found\n";


        }

		void delete_element(int k){
			int index = hash(k);
			if (table[index] == k) {
				table[index] = -1;
				return;
			} else {				chain* curr = head[index];
				chain* prev = nullptr;
				while (curr != nullptr) {
					if (curr->data == k) {
						if (prev == nullptr) {

							head[index] = curr->next;
						} else {
							prev->next = curr->next;
						}
						delete curr;
						return;
					}
					prev = curr;
					curr = curr->next;
				}
			}
			cout << "Element not found\n";
		}

        void printtable(){
            for (int i = 0; i < m; i++) {
            cout << name[i]<<" : " << table[i] << " ";

            chain* curr = head[i];
            while (curr != nullptr) {
                cout << "-> " << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
        }
};

using namespace std;

int main(void){
    hash_table h;

	int input;
	while (input != 6){
        cout << "Welcome to your Password Manager\n";
		cout << "Enter 1 to initialize password manager\n";
		cout << "Enter 2 to insert into the hash table\n";
		cout << "Enter 3 to delete an element in the hash table\n";
		cout << "Enter 4 to search for an entry in the hash table\n";
		cout << "Enter 5 to print the hash table\n";
		cout << "Enter 6 to exit the program\n";
		cout << "What do you want to do? \n";
		cin >> input;
		switch (input){
			case 1:
				int length;
				cout << "Enter how many password you would like to store: \n";
				cin >> length;
				h.initialize(length);
				break;
            case 2:{
				string app;
                int password;
				cout << "Enter the Name of the website/app: \n";
				cin >> app;
                cout << "Enter the password: (Note that the password should contain numbers only)\n";
                cin >> password;
				h.insert(app, password);
				break;
            }
			case 3:
				int key;
				cout << "Enter the password you want to remove: \n";
				cin >> key;;
				h.delete_element(key);
				break;
			case 4:{
				string element_;
				cout << "Enter the name of the app/website: \n";
				cin >> element_;
				h.search(element_);
				break;
            }
			case 5:
				h.printtable();
				break;
		}
	}
}
