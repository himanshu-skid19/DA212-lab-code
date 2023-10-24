#include <time.h>
#include <iostream>
#include <chrono>
#include "bucket_sort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;


void bucket_sort(int *A, int n){
	int max = A[0];
	for (int i = 1; i < n; i++){
		if (A[i] > max){
			max = A[i];
		}
	}
	int B[max];
	for (int i = 0; i <= max; i++){
		B[i] = 0;
	}
	for (int i = 0; i<n; i++){
		B[A[i]]++;
	}
	int i = 0;
	int j = 0;
	while (i <= max){
		while (B[i] > 0){
			A[j++] = i;
			B[i]--;
		}
		i++;
	}

}

void test_bucket_sort(){
	size_t n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;


		auto start = high_resolution_clock::now();
		bucket_sort(list, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by merge_sort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";
		cout << "\n";
		delete[] list;
		n = n*10;


	}
}

