#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class heap {
	private:
		int heap_size;
		int *A;
		int head;
		int MAX;
	public:
		heap(int heap_size){
			this->heap_size = heap_size;
			A = new int[heap_size];
			head = 0;
			MAX = heap_size;
		}

		void insert(int data){
			if (head == heap_size){
				cout << "heap is full\n";
				return;
			}

			A[head] = data;
			head = head+1;
			max_heap();
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
	int n = 1;
	cout << "Perfomance of my Implementation of Heap: \n";
	cout << "\n";
	while (n <= 100000){
		heap h(n);
		auto start = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 h.insert(i);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by my function to insert " << n <<" elements in my heap is: "
         << duration.count() << " nanoseconds" << endl;

		auto start2 = high_resolution_clock::now();
		h.heapsort();
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
		cout << "Time taken by my function to sort a " << n <<" element heap is: "
         << duration2.count() << " nanoseconds" << endl;

		auto start1 = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
			 h.delete_node(i);
		}
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
		cout << "Time taken by my function to delete " << n <<" elements in my heap is: "
         << duration1.count() << " nanoseconds" << endl;

		 cout << "\n";

		n = n*10;
	}



    n = 1;
	cout << "\n";
	while (n <= 100000){
		vector<int> heap_stl{};

		auto start = high_resolution_clock::now();
		for (int i = 1; i <= n; i++) {
            heap_stl.push_back(i);
        }
        make_heap(heap_stl.begin(), heap_stl.end());

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by STL heap to insert " << n <<" elements is: "
         << duration.count() << " nanoseconds" << endl;

		auto start1 = high_resolution_clock::now();
		sort_heap(heap_stl.begin(), heap_stl.end());
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
		cout << "Time taken by STL to sort a  " << n <<" element heap is: "
         << duration1.count() << " nanoseconds" << endl;

		auto start2 = high_resolution_clock::now();
		 for (int i = 0; i < n; i++){
            heap_stl.pop_back();
		}
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
		cout << "Time taken by STL heap to delete " << n <<" elements is: "
         << duration2.count() << " nanoseconds" << endl;
		n = n*10;
		cout << "\n";
	}


}
