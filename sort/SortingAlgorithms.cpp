//
//  SortingAlgorithms.cpp
//  articles
//
//  Created by Vijetha Malla on 2/28/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
using namespace std;
int arr[10] = {7,4,6,3,9,0,1,5,2,8};
int arr1[10] = {7,4,6,3,9,0,1,8,2,5};

void
Merge(int *a, int *b, int low, int mid, int high) {
    int l1, l2, i;
    for(l1 = low, l2 = mid + 1, i = low; 	// start from beginning of both the arrays(l1 & l2) and i from beginning for first array.
        l1 <= mid && l2 <= high; 			// exit loop on end of either of the arrays.
        i++) {
        if(a[l1] <= a[l2]) b[i] = a[l1++]; 	// copy the element from first array and increment l1.
        else b[i] = a[l2++];				// copy the element from second array and increment l2.
    }
    while(l1 <= mid) b[i++] = a[l1++]; 		// first half has more elements.
    while(l2 <= high) b[i++] = a[l2++];		// second hafl has more element.
	for(i = low; i <= high; i++) a[i] = b[i]; //copy the result over to original array between low and high
}

void
MergeSort(int *arr, int b, int e) {
    int sz = (e-b+1)*sizeof(int);
    int R[sz];
    
    if(b>=e) return;
    
    int m = (b+e)/2;
    MergeSort(arr,   b, m);
    MergeSort(arr, m+1, e);
    Merge(&arr[0],&R[0],b,m,e);
}
int
Partition(int low, int high) {
    int i = low-1;
    int pivot = arr1[high]; // select array's right most value as pivot and try to place it the correct place.
                            // move all elements less than pivot to the left of the array.
    						// move all elements greater than pivot to the right of the array.
    						// move the pivot to its right full place.
    						// return the current pivot to be used as new pivot in next recursion.
    for(int j = low; j<=high-1;j++ ){
        if(arr1[j] < pivot){
            i = i+1;
            swap(arr1[i],arr1[j]);
        }
    }
    swap(arr1[i+1],arr1[high]);
    return i+1;
}

void
QuickSort(int low, int high) {
    if(low >= high) return;
    int p = Partition(low, high);
    QuickSort(low, p-1);
    QuickSort(p+1, high);
}

int main() {
    
    MergeSort(&arr[0],0,9);

    QuickSort(0,9);
//
//    int *HS = HeapSort(&arr[0],10);
    return 0;
}

//int *
//InsertionSort(int *arr, int size) {
//    int *R = (int *)malloc(size*sizeof(int));
//    //start with [0] as sorted and [1] as unsorted. Pick first element from unsorted
//    // list and put it in the right place of the sorted list. Do it till the unsorted hits end of list.
//    int sorted = 0;
//    int unsorted = 1;
//    R[0] = arr[sorted];
//    while(unsorted < size) {
//        for(int i = 0 ; i <= sorted; i++) {
//
//        }
//    }
//
//}
//

//
//int *
//HeapSort(int *arr, int size) {
//    int *R = (int *)malloc(size*sizeof(int));
//    return R;
//}
