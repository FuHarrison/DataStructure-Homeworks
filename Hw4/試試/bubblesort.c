#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int length);

int main(){
    int length = 0;
    scanf("%d",&length);
    int arr[length];
    for(int i = 0;i < length;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,length);
    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[],int length){
    for(int i = 0;i < length-1;i++){
        for(int j = 0;j < length-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}