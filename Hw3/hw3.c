#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treenode{
    int value;
    struct treenode *left;
    struct treenode *right;
};

typedef struct treenode *treePtr;

treePtr createnode(int value){
    treePtr result = malloc(sizeof(treePtr));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void insertnumber(treePtr *rootptr,int value){
    treePtr root = *rootptr;
    if(root == NULL){
        //tree empty
        (*rootptr) = createnode(value);
        return;
    }
    if(value == root->value){
        //do nothing
        return;
    }
    if(value < root->value){
        return insertnumber(&(root->left),value);
    }else{
        return insertnumber(&(root->right),value);
    }
}


void printtree_pre(treePtr root){
    if(root == NULL){
        return;
    }

    printf("%d ",root->value);
    printtree_pre(root->left);
    printtree_pre(root->right);

}

void printtree_in(treePtr root){
    if(root == NULL){
        return;
    }
    
    printtree_in(root->left);
    printf("%d ",root->value);
    printtree_in(root->right);

}

void printtree_post(treePtr root){
    if(root == NULL){
        return;
    }

    printtree_post(root->left);
    printtree_post(root->right);
    printf("%d ",root->value);

}


int main(){
    int n;
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){
            break;
        }
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        
        treePtr root = NULL;
        for(int i=0;i<n;i++){
            insertnumber(&root,arr[i]);    
        }

        printf("Preorder: ");
        printtree_pre(root);
        printf("\n");
        printf("Inorder: ");
        printtree_in(root);
        printf("\n");
        printf("Postorder: ");
        printtree_post(root);

    }

}