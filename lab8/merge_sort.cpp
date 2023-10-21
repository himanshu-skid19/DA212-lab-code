#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>

#define N9 1000000000
#define N8 100000000
#define N7 10000000
#define N6 1000000

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

void test_sorting(){
    int n = 10;
	while (n <= 1000000000){
        std::vector<int> list;
		size_t i;
		srand(time(NULL));
		for(i=0; i<n; i++)
            list.push_back(rand()%1000);
		auto start = high_resolution_clock::now();
        sort(list.begin(), list.end());
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop-start);


		cout << "Time taken by STL sorting algorithm to sort an array of length " << n << " is given by " << duration.count()*1e-9 << " seconds "<< "\n";
		cout << "\n";
		n = n*10;


	}

}

int main(void){
    cout << "WARNING: It might take a very long time for a specific algorithm to sort an array so be on a lookout for that.\n";
    int input = -1;
    while (input != 3){
		cout << "Enter 1 to test on my implementation of merge_sort \n";
		cout << "Enter 2 to test on STL's implementation of sorting'\n";
		cout << "Enter 3 to exit the program\n";

		cin >> input;
		switch (input){
			case 1:
				test_merge_sort();
				break;
			case 2:
                test_sorting();
				break;

		}
	}


}
