#include <time.h>
#include <chrono>
#include "insertion_sort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

void insertion_sort(int *A, int n){
	for (int i = 1; i < n+1; i++){
		int key = A[i];
		int j = i-1;
		while (j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;

		}
		A[j+1] = key;
	}
}

void test_insertion_sort(){
	int n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;
		auto start = high_resolution_clock::now();
		insertion_sort(list, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by insertion_sort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";
		cout << "\n";
		n = n*10;


	}
}

