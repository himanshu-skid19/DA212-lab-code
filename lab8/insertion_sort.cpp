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
		cout << "Enter 1 to test on my implementation of insertion sort \n";
		cout << "Enter 2 to test on STL's implementation of sorting'\n";
		cout << "Enter 3 to exit the program\n";

		cin >> input;
		switch (input){
			case 1:
				test_insertion_sort();
				break;
			case 2:
                test_sorting();
				break;

		}
	}


}
