#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647

struct Edge{
    int u,v,w;
};

int compare_function(const void *a,const void* b);
int kruskal(int** arr,int n);
int prim(int** arr,int n);

int main(){
    int n = 0;
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){
            break;
        }

        int** arr = malloc(sizeof(int*) * n);
        for (int i = 0; i < n; i++) {
            arr[i] = malloc(sizeof(int) * n);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                scanf("%d",&arr[i][j]);
            }
        }

        int costByKruskal = kruskal(arr,n);
        int costByPrim = prim(arr,n);
        printf("Prim minimun cost: %d\n",costByPrim);
        printf("Kruskal minimun cost: %d\n",costByKruskal);
    }

    return 0;
}

int compare_function(const void *a,const void* b){
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int kruskal(int** arr,int n){
    struct Edge edges[n*n];
    int edgeIdex = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] > 0){
                edges[edgeIdex].u = i;
                edges[edgeIdex].v = j;
                edges[edgeIdex].w = arr[i][j];
                edgeIdex++;
            }
        }
    }

    qsort(edges,edgeIdex,sizeof(struct Edge),compare_function);

    int* parent = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int cost = 0;
    for (int i = 0; i < edgeIdex; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        while (u != parent[u]) u = parent[u];
        while (v != parent[v]) v = parent[v];

        if (u == v) continue;

        parent[v] = u;
        cost += w; 
    }

    free(parent);

    return cost;
}

int prim(int** arr,int n){
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
        
    return cost;
}