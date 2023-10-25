#include <time.h>
#include <chrono>
#include "sorting_algos.h"
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


void counting_sort(int *A, int n, int exp) {
    int B[n];
    int C[10] = {0};

    for (int i = 0; i < n; i++) {
        C[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        C[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}



void radix_sort(int *A, int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    for (int i = 1; max / i > 0; i *= 10) {
        counting_sort(A, n, i);
    }
}

void test_radix_sort(){
	int n = 10;
	while (n <= 1000000000){
		int* list = new int[n];
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
			list[i] = rand()%1000;

		auto start = high_resolution_clock::now();
		radix_sort(list, 10);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by radix sort algorithm to sort a array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";
		cout << "\n";
		n = n*10;


	}
}



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


