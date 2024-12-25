#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> 

typedef struct TreeNode{
    int val;
    struct TreeNode* left,* right;
}TreeNode;

bool traversal(TreeNode* root1,TreeNode* root2){
    if(!root1&&!root2)return 1;
    if((root1&&!root2)||(!root1&&root2))return 0;
    return traversal(root1->left,root2->left)&&traversal(root1->right,root2->right);
}

int main() {
    // 示例测试代码
    TreeNode* root1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* root2 = (TreeNode*)malloc(sizeof(TreeNode));
    root1->val = 1;
    root2->val = 2;
    root1->left = root1->right = NULL;
    root2->left = root2->right = NULL;

    if (traversal(root1, root2)) {
        printf("The two trees have the same shape.\n");
    } else {
        printf("The two trees do not have the same shape.\n");
    }

    free(root1);
    free(root2);

    return 0;
}