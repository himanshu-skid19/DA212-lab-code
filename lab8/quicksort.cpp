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
		cout << "Enter 1 to test on my implementation of quicksort \n";
		cout << "Enter 2 to test on STL's implementation of sorting'\n";
		cout << "Enter 3 to exit the program\n";

		cin >> input;
		switch (input){
			case 1:
				test_quicksort();
				break;
			case 2:
                test_sorting();
				break;

		}
	}


}
