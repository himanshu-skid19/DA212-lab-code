#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>


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

	struct chain{
		int data;
		chain* next;
	};
	chain **head;
    public:
        hash_table() {m = 0; table = nullptr; head = nullptr;}
        void initialize(int length){
            m = length;
            table = new int[m];
			head = new chain*[m];
            for (int i = 0; i < m; i++) {
                table[i] = -1;
				head[i] = nullptr;

			}
		}
        int hash(int k){
            return k % m;
        }

        void insert(int k){
            int index = hash(k);
			if (table[index] == -1){
				if (index >= 0 && index < m) {
                table[index] = k;
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

        int search(int k){
           int index = hash(k);
			if (table[index] == k) {
				return index;
			} else {
				chain* curr = head[index];
				while (curr != nullptr) {
					if (curr->data == k) {
						return index;
					}
					curr = curr->next;
					}
			}

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
            cout <<  i << ": " << table[i] << " ";

            chain* curr = head[i];
            while (curr != nullptr) {
                cout << "-> " << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
        }
};

int main(void){

	int n = 1;
	cout << "Perfomance of my Implementation of Hash Table: \n";
	cout << "\n";
	while (n <= 100000){
		hash_table h;
		h.initialize(n);
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 h.insert(i);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by my function to insert " << n <<" elements in my hash table is: "
         << duration.count() << " nanoseconds" << endl;

		auto start2 = high_resolution_clock::now();
		h.search(0);
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
		cout << "Time taken by my function to search for an element in a  " << n <<" element hash table is: "
         << duration2.count() << " nanoseconds" << endl;

		auto start1 = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 h.delete_element(i);
		}
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
		cout << "Time taken by my function to delete " << n <<" elements in my hash table is: "
         << duration1.count() << " nanoseconds" << endl;

		 cout << "\n";

		n = n*10;
	}

	n = 1;
	cout << "\n";
	while (n <= 100000){
		unordered_map<int, int> umap;
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 umap[i] = i;
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by STL unordered_map to insert " << n <<" elements is: "
         << duration.count() << " nanoseconds" << endl;

		auto start1 = high_resolution_clock::now();
		umap.find(0);
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
		cout << "Time taken by my function to search for an element in a  " << n <<" element hash table is: "
         << duration1.count() << " nanoseconds" << endl;

		auto start2 = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 umap.erase(i);
		}
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
		cout << "Time taken by STL unordered_map to delete " << n <<" elements is: "
         << duration2.count() << " nanoseconds" << endl;
		n = n*10;
		cout << "\n";
	}



}
