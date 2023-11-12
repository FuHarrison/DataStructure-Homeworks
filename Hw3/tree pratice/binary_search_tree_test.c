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

bool insertnumber(treePtr *rootptr,int value){
    treePtr root = *rootptr;
    if(root == NULL){
        //tree empty
        (*rootptr) = createnode(value);
        return true;
    }
    if(value == root->value){
        //do nothing
        return false;
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
    treePtr root = NULL;

    insertnumber(&root,15);
    insertnumber(&root,11);
    insertnumber(&root,24);
    insertnumber(&root,5);
    insertnumber(&root,19);
    insertnumber(&root,19);
    insertnumber(&root,16);

    printtree_in(root);
    printf("\n");
    printtree_pre(root);
    printf("\n");
    printtree_post(root);


}