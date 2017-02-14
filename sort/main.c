//
//  main.c
//  sort
//
//  Created by Vijetha Malla on 2/14/17.
//  Copyright © 2017 vy. All rights reserved.
//

#include <stdio.h>
int array[]={100,10,337,5,2,132};
void printarray(){
    int i;
    for(i=0; i<6; i++) printf("%d ",array[i]);
    printf("\n");
}
void swap(int *a,int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void sort(int *array, int size){
    
    int i,j;
    for(j=size;j>0;j--) {
        //sort one element
    	for(i=0;i<j-1;i++){
        	if(array[i] > array[i+1])
            	swap(&array[i],&array[i+1]);
    	}
    }
}
void insert(int *array, int x,int pos,int sorted) {
    memcpy(array+pos+1,array+pos,(sorted-pos)*sizeof(int));
    array[pos] = x;
}
void merge_sort(int *array, int size){
    int i=0,j=0,sorted=1;
    for(j=sorted;j<size;j++) {
        int aj=array[j];
        //mergesort one element
        int ai;
        for(i=0,ai=array[i];i<sorted;i++,ai=array[i]){
            if(aj<ai){//insert the element;
                insert(array,aj,i,sorted);
                break;
            }
        }
        sorted++;
    }
    
}
int main(){
    printarray();
    //sort(&array[0], 6);
    merge_sort(&array[0], 6);
    printarray();
}
