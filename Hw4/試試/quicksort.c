#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x,int *y);
void quickSort(int arr[],int length);
void quickSort_recursion(int arr[],int low,int high);
int  partition(int arr[],int low,int high);

int main(){
    int length = 0;
    scanf("%d",&length);
    int arr[length];
    for(int i = 0;i < length;i++){
        scanf("%d",&arr[i]);
    }

    quickSort(arr,length);
    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
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



