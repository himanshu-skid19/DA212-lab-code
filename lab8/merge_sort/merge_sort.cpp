#include <time.h>
#include <iostream>
#include <chrono>
#include "merge_sort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;


void merge(int *A, int p, int q, int r){
	int n_l = q - p + 1;
	int n_r = r - q;
	int L[n_l];
	int R[n_r];
	for (int i = 0; i < n_l; i++){
		L[i] = A[p+i];
	}

	for (int j = 0; j < n_r; j++){
		R[j] = A[q+j+1];
	}

	int i = 0;
	int j = 0;
	int k = p;

	while ((i < n_l) && (j < n_r)){
		if (L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n_l){
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < n_r){
		A[k] = R[j];
		j++;
		k++;
	}

}

void merge_sort(int *A, int p, int r){
	if (p >= r){
		return;
	}
	int q = (p+r)/2;
	merge_sort(A, p, q);
	merge_sort(A, q+1, r);
	merge(A, p,q,r);
}




void test_merge_sort(){
	int n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;
		auto start = high_resolution_clock::now();
		merge_sort(list, 0, n-1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by my merge_sort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";
		cout << "\n";
		n = n*10;


	}
}
