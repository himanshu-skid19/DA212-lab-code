#include <time.h>
#include <iostream>
#include <chrono>
#include "bubble_sort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

void bubble_sort(int *A, int n){
	for (int i = 0; i < n; i++){
		for (int j = n; j>i; j--){
			if (A[j] < A[j-1]){
				int temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
			}
		}
	}
}


void test_bubble_sort(){
	int n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;


		auto start = high_resolution_clock::now();
		bubble_sort(list, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by insertion_sort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";

		n = n*10;


	}
}

void debug(){
	int n = 10;
	int* list = new int[n];
	size_t i;
	srand(time(NULL));
	for(i=0; i<n; i++)
		list[i] = rand()%1000;

	for(i=0; i<n; i++)
		cout << list[i] << ", ";

	cout << endl;

	bubble_sort(list, 10);

	for(i=0; i<n; i++)
		cout << list[i] << ", ";
	cout << endl;

}



