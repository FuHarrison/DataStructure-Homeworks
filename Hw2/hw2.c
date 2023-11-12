#include <stdio.h>
#include<stdbool.h>
#include<string.h>

#define QUEUESIZE 5

typedef struct{
    char id;
    int num;
}customer;

typedef struct{
    int front,rear;
    customer items[QUEUESIZE];
}queue;


void AddQ(queue *q,char i,int n){
    if(q->rear != QUEUESIZE-1){
        q->rear++;
        q->items[q->rear].id = i;
        q->items[q->rear].num = n;
    }
}

void DeleteQ(queue *q){
    if(q->front != q->rear+1){
        q->front++;
    }
}

bool isEmpty(queue *q){
    if(q->front == q->rear+1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(queue *q){
    if(q -> rear == QUEUESIZE-1){
        return true;
    }
    else{
        return false;
    }
}

bool check_id(queue *q,char id){
    for(int i = q->front;i <= q->rear;i++){
        if(id == q->items[i].id){
            return false;
        }
    }
    return true;
}

queue q;

int main(){
    q.front = 0;
    q.rear = -1;
    int input;
    do{
        scanf("%d",&input);
        if(input == 1){
            int id,num;
            scanf(" %c %d",&id,&num);
            if(check_id(&q,id)){
                AddQ(&q,id,num);
            }
        }
        else if(input == 2){
            int total = 0;
            for(int i = q.front;i <= q.rear;i++){
                total += q.items[i].num;
            }
            printf("%d\n",total);
        }
        else if(input == 3){
            printf("%c\n",q.items[q.front].id);
        }
        else if(input == 4){
            DeleteQ(&q);
        }
        else if(input == -1){
            break;
        }
        else{
            printf("error\n");
        }
    }while(input != -1);
}
