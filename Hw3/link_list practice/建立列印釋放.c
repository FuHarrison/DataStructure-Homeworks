#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createList(int*,int); //串列建立函數 
Node printList(Node *);  //串列列印函數 
void freeList(Node *);    //釋放串列記憶空間函數 

int main()
{

  Node *first;
  int arr[]={14,27,32,46};
  first=createList(arr,4);
  printList(first);
  freeList(first);
  
  system("PAUSE");	 
  return 0;
}

//串列建立函數 
Node *createList(int *arr,int len){
	int i;
	Node *first,*current,*previous;
	for(i=0;i<len;i++){
		current=(Node *) malloc(sizeof(Node));//建立新節點
		current->data=arr[i];  //設定節點的資料成員
		if(i==0){
		first=current;  //如果是第一個成員把指標frist指向目前的節點 
		}else{
			previous->next=current;//把前一個的next指向目前的節點 
		}
		current->next=NULL; //把目前的節點的next指向NULL
		previous=current; //把前一個節點設成目前的節點 
	}
	return first;
}

//串列列印函數
Node printList(Node *first){
	Node *node=first; //將node指向第一個節點
	if(first==NULL){
		printf("List is empty!\n");
	}else{
		while(node!=NULL){
			printf("%3d",node->data);
			node=node->next;
		}
		printf("\n");
	}
} 

//釋放串列記憶空間函數
void freeList(Node *first){
	Node *current,*tmp;
	current=first;
	while(current!=NULL){
		tmp=current;
		current=current->next;
		free(tmp);
	}
}