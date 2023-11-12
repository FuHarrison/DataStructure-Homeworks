#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void bubbleSort(int arr[],int length);

int main(){
    int length = 0;
    scanf("%d",&length);
    int arr[length];
    for(int i = 0;i < length;i++){
        scanf("%d",&arr[i]);
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);  // 取得當前時刻的時間戳
    bubbleSort(arr,length);
    gettimeofday(&end, NULL);  // 再次取得當前時刻的時間戳
    double bubbleSort_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
   


    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("bubble sort: %.8f sec\n", bubbleSort_time);
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