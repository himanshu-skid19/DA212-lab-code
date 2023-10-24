#include <iostream>
#include "selection_sort.h"
#include "sorting.h"


using namespace std;

void run(){

    cout << "WARNING: It might take a very long time for a specific algorithm to sort an array so be on a lookout for that.\n";
    int input = -1;
    while (input != 3){
		cout << "Enter 1 to test on my implementation of selection sort \n";
		cout << "Enter 2 to test on STL's implementation of sorting'\n";
		cout << "Enter 3 to exit the program\n";

		cin >> input;
		switch (input){
			case 1:
				test_selection_sort();
				break;
			case 2:
                test_sorting();
				break;

		}

    }
}
