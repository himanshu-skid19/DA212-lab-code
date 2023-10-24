#include <time.h>
#include <iostream>
#include <chrono>
#include "selection_sort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

void selection_sort(int *A, int n){
	for (int i = 0; i < n; i++){
		int min = 100000000;
		int j=i;
		int idx=0;
		for (j = i; j < n; j++){
			if (A[j] <= min){
				min = A[j];
				idx = j;
			}
		}
		int temp = A[idx];
		A[idx] = A[i];
		A[i] = temp;
	}
}


void test_selection_sort(){
	int n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;


		auto start = high_resolution_clock::now();
		selection_sort(list, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by insertion_sort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";

		n = n*10;


	}
}



