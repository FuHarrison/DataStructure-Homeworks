#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647

int main(){
    int n = 0;
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){
            break;
        }

        int arr[n][n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                scanf("%d",&arr[i][j]);
            }
        }

        int cost = 0;

        int mst[n];
        for(int i = 0; i < n;i++){
            mst[i] = 0;
        }

        mst[0] = 1;

        for(int i = 1;i < n;i++){
            int min_w = INF;
            int u = -1;
            int v = -1;
            for(int j = 0;j < n;j++){
                if(mst[j]){
                    for(int k = 0;k < n;k++){
                        if(!mst[k] && arr[j][k]>0 && arr[j][k]<min_w){
                            min_w = arr[j][k];
                            u = j;
                            v = k;
                        }
                    }
                }
            }

            mst[v] = 1;
            cost += min_w;
        }
        printf("Minimum spanning tree cost: %d\n", cost);
    }
        return 0;
}