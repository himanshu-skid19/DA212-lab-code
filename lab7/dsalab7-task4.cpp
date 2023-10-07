#include <iostream>
using namespace std;

class heap {
	private:
		int heap_size;
		int *A;
		int head;
	public:
		heap(int heap_size){
			this->heap_size = heap_size;
			A = new int[heap_size];
			head = 0;
		}
		
		void insert(int data){
			if (head == heap_size){
				cout << "heap is full\n";
				return;
			}
			
			A[head] = data;
			head = head+1;
		}
		
		void print_heap(){
			for (int i = 0; i < head; i++){
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
		
		void delete_node(int data){
			int iter = 0;
			while (A[iter] != data]){
				iter++;
			}
			while (iter < heap_size){
				A[iter] = A[iter+1];
				
			}
		}
};

int main(void){
	heap h(10);
	h.insert(1);
	h.insert(14);
	h.insert(7);
	h.insert(10);
	h.insert(8);
	h.insert(4);
	h.insert(9);
	h.insert(16);
	h.insert(3);
	h.insert(2);
	h.print_heap();
	h.max_heap();
	h.print_heap();
}
