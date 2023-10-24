#include <time.h>
#include <iostream>
#include <chrono>
#include "quicksort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

int partition(int *A, int p, int r){
	int x = A[r];
	int i = p - 1;
	for (int j = p; j<r; j++){
		if (A[j] <= x){
			i = i + 1;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}

	}
	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	return i+1;
}

void quicksort(int *A, int p, int r){
	if (p < r){
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

void test_quicksort(){
	int n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;

		auto start = high_resolution_clock::now();
		quicksort(list, 0, n-1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by quicksort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";
		cout << "\n";
		n = n*10;


	}
}
