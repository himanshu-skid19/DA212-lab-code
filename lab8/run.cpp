#include <iostream>
#include "sorting_algos.h"
#include "stl_sort.h"


using namespace std;

void run(){

    cout << "WARNING: It might take a very long time for a specific algorithm to sort an array so be on a lookout for that.\n";
    int input = -1;
    while (input != 9){
		cout << "Enter 1 to test on my implementation of insertion sort \n";
		cout << "Enter 2 to test on my implementation of selection sort \n";
		cout << "Enter 3 to test on my implementation of bubble sort \n";
		cout << "Enter 4 to test on my implementation of bucket sort \n";
		cout << "Enter 5 to test on my implementation of radix sort \n";
		cout << "Enter 6 to test on my implementation of merge sort \n";
		cout << "Enter 7 to test on my implementation of quicksort \n";
		cout << "Enter 8 to test on STL's implementation of sorting'\n";
		cout << "Enter 9 to exit the program\n";

		cin >> input;
		switch (input){
			case 1:
				test_insertion_sort();
				break;
			case 2:
				test_selection_sort();
				break;
			case 3:
				test_bubble_sort();
				break;
			case 4:
				test_bucket_sort();
				break;
			case 5:
				test_radix_sort();
				break;
			case 6:
				test_merge_sort();
				break;
			case 7:
				test_quicksort();
				break;
			case 8:
                test_sorting();
				break;

		}

    }
}
