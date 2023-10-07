#include <iostream>
using namespace std;

class heap {
	private:
		int heap_size;
		int *A;
		int head;
		int MAX;
	public:
		heap(int MAX){
			this->MAX = MAX;
			A = new int[MAX];
			this->head = -1;
			this->heap_size = 0;
		}
		
		void insert(int data){
			if (head == MAX-1){
				cout << "heap is full\n";
				return;
			}
			head = head+1;
			A[head] = data;
			heap_size++;
			max_heap();
		}
		
		void print_heap(){
			for (int i = 0; i < heap_size; i++){
				cout << A[i] << " ";
			}
			cout << "\n";
		}
		
		void max_heapify(int i){
			int l = 2*i + 1;
			int r = 2*i + 2;
			int largest = i;
			if ((l <= heap_size-1) && (A[l] > A[i])){
				largest = l;
			}
			else largest = i;
			
			if ((r <= heap_size-1) && (A[r] > A[largest])){
				largest = r;
			}
			if (largest != i){
				int temp = A[i];
				A[i] = A[largest];
				A[largest] = temp;
				max_heapify(largest);
			}
		}
		
		void build_max_heap(int n){
			for (int i = n/2-1; i >= 0; i--){
				max_heapify(i);
			}
		}
		
		void max_heap(){
			build_max_heap(heap_size);
		}


		int get_index_of_data(int data){
			for (int i = 0; i < heap_size; i++){
				if (A[i] == data){
					return i;
				}
			}
			return -1;
		}

		void search(int data){
			int i = get_index_of_data(data);
			if (i != -1){
				cout << "Element found at position " << i << "\n";
				return;
			}
			cout << "element not found \n";
			return;

		}
		void delete_node(int data){
			int iter = 0;
			if (get_index_of_data(data) == -1){
				cout << "Element not in heap\n";
				return;
			}
			while (A[iter] != data){
				iter++;
			}

			while (iter < heap_size){
				A[iter] = A[iter+1];
				iter++;
			}
			heap_size--;
			head--;
			max_heap();
		}

		void get_root(){
			cout << A[0] << "\n";
		}

		void heapsort(){
			int x = heap_size;
			for (int i = heap_size-1; i > 0; i--){
				int temp = A[0];
				A[0] = A[i];
				A[i] = temp;
				heap_size--;
				max_heap();
			}
			heap_size = x;
		}
};

int main(void){
	cout << "Welcome to this program, how many nodes do you want your heap to have? \n";
    int num;
    cin >> num;
	heap heap(num);

    int input;
	while (input != 8){
		cout << "Enter 1 to add a node to the heap\n";
		cout << "Enter 2 to enforce max heap property manually\n";
		cout << "Enter 3 to delete a node from the heap\n";
		cout << "Enter 4 to search for an element in the heap\n";
		cout << "Enter 5 to print root of the heap\n";
		cout << "Enter 6 to print the heap\n";
		cout << "Enter 7 to perform heapsort on this heap\n";
		cout << "Enter 8 to exit the program\n";
		cout << "What do you want to do? \n";
		cin >> input;
		switch (input){
			case 1:
				int val;
				cout << "Enter the value of the node: \n";
				cin >> val;
				heap.insert(val);
				break;
			case 2:
				heap.max_heap();
				break;
			case 3:
				int key;
				cout << "Enter the value of the node you want to delete: \n";
				cin >> key;;
				heap.delete_node(key);
				break;
			case 4:
				int x;
                cout << "Enter the value of the first vertex: \n";
				cin >> x;
				heap.search(x);
				break;
			case 5:
				heap.get_root();
				break;
			case 6:
				heap.print_heap();
				break;
			case 7:
				heap.heapsort();
				break;
		}
	}

}
