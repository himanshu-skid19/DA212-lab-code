#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H


void insertion_sort(int *A, int n);
void test_insertion_sort();
void bubble_sort(int *A, int n);
void test_bubble_sort();
void bucket_sort(int *A, int n);
void test_bucket_sort();
void merge(int *A, int p, int q, int r);
void merge_sort(int *A, int p, int r);
void test_merge_sort();
int partition(int *A, int p, int r);
void quicksort(int *A, int p, int r);
void test_quicksort();
void counting_sort(int *A, int n, int exp);
void radix_sort(int *A, int n);
void test_radix_sort();
void selection_sort(int *A, int n);
void test_selection_sort();

#endif
