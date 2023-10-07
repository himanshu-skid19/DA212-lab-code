#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    string task;
    int priority;
};

class priority_queue {
	private:
        int heap_size;
        Node **A;
		int head;
        int MAX;
	public:
		priority_queue(int MAX){
            this->heap_size= 0;
            this->MAX = MAX;
            this->A = new Node *[MAX];
            for (int i = 0; i<MAX; i++){
                A[i] = nullptr;
            }
			this->head = -1;
		}

		void enqueue(string task, int priority){
			if (head == MAX-1){
				cout << "heap is full\n";
				return;
			}
            head = head+1;
            Node *data = new Node;
            data->task = task;
            data->priority = priority;
			A[head] = data;
            heap_size++;
			max_heap();
		}

		void print_heap(){
			for (int i = 0; i < heap_size;i++){
				cout << A[i]->priority << "->" << A[i]->task << "\n";
			}
			cout << "\n";
		}

		void max_heapify(int i){
			int l = 2*i + 1;
			int r = 2*i + 2;
			int largest = i;
			if ((l <= heap_size-1) && ((A[l]->priority) > (A[i]->priority))){
				largest = l;
			}
			else largest = i;

			if ((r <= heap_size-1) && ((A[r]->priority) > (A[largest]->priority))){
				largest = r;
			}
			if (largest != i){
				Node *temp = A[i];
				A[i] = A[largest];
				A[largest] = temp;
				max_heapify(largest);
			}
		}

		void build_max_heap(int n){
			for (int i = n/2; i >= 0; i--){
				max_heapify(i);
			}
		}

		void max_heap(){
			build_max_heap(heap_size);
		}


		int get_index_of_data(int data){
			for (int i = 0; i < heap_size; i++){
				if (A[i]->priority == data){
					return i;
				}
			}
			return -1;
		}

		void search(int data){
			int i = get_index_of_data(data);
			if (i != -1){
				cout << A[i]->task<<"\n";
				return;
			}
			cout << "task not found \n";
			return;
        }

		void dequeue(){
			int iter = 0;

			while (iter < heap_size){
				A[iter] = A[iter+1];
				iter++;
			}
			heap_size--;
			head--;
			max_heap();
		}

		void get_max(){
			cout << A[0]->task << "\n";
		}

        void clear(){
            int x = heap_size;
            for (int i = 1; i<x; i++){
                dequeue();
                heap_size--;
                head--;
            }
        }
        void isEmpty(){
            if (head == -1){
                cout << "Priority Queue is empty\n";
                return;
            }
            cout << "Priority Queue is not empty\n";
            return;
        }
};

int main(void){
	cout << "Welcome to this program that demostrates a priority queues using max_heap, how many nodes do you want your heap to have? \n";
    int num;
    cin >> num;
	priority_queue q(num);

    int input;
	while (input != 8){
		cout << "Enter 1 to enqueue an element to the priority_queue\n";
		cout << "Enter 2 to dequeue an element from the priority queue\n";
		cout << "Enter 3 to get the element with highest priority\n";
		cout << "Enter 4 to clear the queue\n";
		cout << "Enter 5 to print the priority queue\n";
		cout << "Enter 6 to check if the queue is empty\n";
		cout << "Enter 7 to search for an element\n";
		cout << "Enter 8 to exit the program\n";
		cout << "What do you want to do? \n";
		cin >> input;
		switch (input){
			case 1:
            {
				int priority;
                string s;
				cout << "Enter the priority of the node: \n";
				cin >> priority;
                cin.ignore();
                cout << "Enter the task: \n";
                getline(cin, s);
				q.enqueue(s, priority);
				break;
            }
			case 2:
            {
                q.dequeue();
				break;
            }
			case 3:
                q.get_max();
				break;
			case 4:
                q.clear();
				break;
			case 5:
				q.print_heap();
				break;
			case 6:
				q.isEmpty();
				break;
			case 7:
                int pq;
                cout << "Enter the Priority of the element you want to search for: ";
                cin >> pq;
				q.search(pq);
				break;
		}
	}
}
