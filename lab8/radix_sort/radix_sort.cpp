#include <time.h>
#include <iostream>
#include <chrono>
#include "radix_sort.h"
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;


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


