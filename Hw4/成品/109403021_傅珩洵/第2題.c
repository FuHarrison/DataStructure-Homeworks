#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAX 100000

void swap(int *x,int *y);
void bubbleSort(int arr[],int length);
void quickSort(int arr[],int length);
void quickSort_recursion(int arr[],int low,int high);
int  partition(int arr[],int low,int high);

int main(){
    int n = 0;
    while(n != -1 && n <= MAX){
        scanf("%d",&n);
        if(n == -1 || n > MAX){
            break;
        }

        int arr1[n];
        int arr2[n];
        for(int i = 0;i < n;i++){
            scanf("%d",&arr1[i]);
        }
        for(int i = 0;i < n;i++){
            arr2[i] = arr1[i];
        }

        struct timeval startB,endB,startQ,endQ;

        gettimeofday(&startB, NULL);
        bubbleSort(arr1,n);
        gettimeofday(&endB, NULL); 

        gettimeofday(&startQ, NULL); 
        quickSort(arr2,n);
        gettimeofday(&endQ, NULL); 

        double bubbleSort_time = (endB.tv_sec - startB.tv_sec) + (endB.tv_usec - startB.tv_usec) / 1000000.0;
        double quickSort_time = (endQ.tv_sec - startQ.tv_sec) + (endQ.tv_usec - startQ.tv_usec) / 1000000.0;

        for(int i = 0;i < n;i++){
            printf("%d ",arr2[i]);
        }
        printf("\n");
        printf("bubble sort: %.8f sec\n", bubbleSort_time);
        printf("quick sort: %.8f sec\n", quickSort_time);

    }
    
    return 0;
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[],int length){
    for(int i = 0;i < length-1;i++){
        for(int j = 0;j < length-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void quickSort(int arr[],int length){
    quickSort_recursion(arr,0,length - 1);
}

void quickSort_recursion(int arr[],int low,int high){
    if(low < high){
        int pivot_index = partition(arr,low,high);
        quickSort_recursion(arr,low,pivot_index-1);
        quickSort_recursion(arr,pivot_index+1,high);
    }
}

int partition(int arr[],int low,int high){
    int pivot_value = arr[high];
    
    int i = low;
    
    for(int j = low;j < high;j++){
        if(arr[j] <= pivot_value){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[high]);
    
    return i;
}