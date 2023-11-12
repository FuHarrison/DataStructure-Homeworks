#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int u,v,w;
};

int compare_function(const void *a,const void* b){
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main(){
    int n = 0;
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){
            break;
        }

        struct Edge edges[n*n];
        int edgeIdex = 0;
        int arr[n][n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                scanf("%d",&arr[i][j]);
                if(arr[i][j] > 0){
                    edges[edgeIdex].u = i;
                    edges[edgeIdex].v = j;
                    edges[edgeIdex].w = arr[i][j];
                    edgeIdex++;
                }
            }
        }

        qsort(edges,edgeIdex,sizeof(struct Edge),compare_function);

        // 初始化并查集
        int* parent = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // 遍歷每一條邊，並嘗試加入
        int cost = 0;
        for (int i = 0; i < edgeIdex; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            // 查找 u 和 v 的根節點
            while (u != parent[u]) u = parent[u];
            while (v != parent[v]) v = parent[v];

            // 若 u 和 v 屬於同一個集合，則該邊無法加入
            if (u == v) continue;

            // 否則，將 v 加入到 u 的集合中
            parent[v] = u;
            cost += w;  // 累加邊的權值
        }
        printf("Minimum spanning tree cost: %d\n", cost);

        free(parent);  // 釋放并查集的動態分配的內存
    }
        return 0;
}


