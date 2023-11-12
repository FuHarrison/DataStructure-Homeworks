#include <stdio.h>
#include <stdlib.h>


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

void printtree_pre(treePtr root){
    if(root == NULL){
        return;
    }
    //preorder

    printf("%d ",root->value);
    printtree_pre(root->left);
    printtree_pre(root->right);

}

void printtree_in(treePtr root){
    if(root == NULL){
        return;
    }
    //preorder

    
    printtree_in(root->left);
    printf("%d ",root->value);
    printtree_in(root->right);

}

void printtree_post(treePtr root){
    if(root == NULL){
        return;
    }
    //preorder

    
    printtree_post(root->left);
    printtree_post(root->right);
    printf("%d ",root->value);

}



int main(){
    treePtr n1 =createnode(10);
    treePtr n2 =createnode(11);
    treePtr n3 =createnode(12);
    treePtr n4 =createnode(13);
    treePtr n5 =createnode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printtree_in(n1);
    printf("\n");
    printtree_pre(n1);
    printf("\n");
    printtree_post(n1);


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}