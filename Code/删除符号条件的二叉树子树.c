#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> 

typedef struct TreeNode{
    int val;
    struct TreeNode* left,* right;
}TreeNode;

void delete(TreeNode* p){
    if(!p)return;
    delete(p->left);
    delete(p->right);
    free(p);
}

int traversal(TreeNode* q,int x){
    if(!q)return -1;
    if(q->val==x){
        delete(q);
        return 1;
    }
    else{
        if(traversal(q->left,x)==1){
            q->left=NULL;
        }
        if(traversal(q->right,x)==1){
            q->right=NULL;
        }
        return 0;
    }
}

void func(TreeNode* root,int x){
    if(root->val==x){
        delete(root);
    }
    else{
        traversal(root,x);
    }
}
int main(){

    return 0;
}
