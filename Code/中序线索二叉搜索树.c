#include<stdlib.h>
#include<stdio.h>

// 中序
typedef struct TreeNode{
    int val;
    struct TreeNode* left,*right;
    int ltag,rtag;
}TreeNode;

TreeNode* Initial(int val){
    TreeNode* p=(TreeNode*)malloc(sizeof(TreeNode));
    p->val=val;
    p->left=p->right=NULL;
    p->ltag=p->rtag=0;
    return p;
}

TreeNode* GetLeft(TreeNode* root){
    TreeNode* p=root;
    while(!p->ltag){
        p=p->left;
    }
    return p;
}

void Insert(TreeNode* root,int k){
    TreeNode* p=(TreeNode*)malloc(sizeof(TreeNode));
    p->left=p->right=NULL;
    p->rtag=p->ltag=0;
    p->val=k;
    TreeNode* curr=root;
    while(1){
        if(curr->val<k){
            if(curr->right){
                curr=curr->right;
            }
            else{
                curr->right=p;
                break;
            }
        }
        else{
            if(curr->left){
                curr=curr->left;
            }
            else{
                curr->left=p;
                break;
            }
        }
    }
}

// 不考虑删除根节点的情况，插入删除在线索化之前完成，不需要考虑rtag和ltag
void Delete(TreeNode* root,int k){
    TreeNode* p=root;
    TreeNode* prev=p;
    int op;
    // op=0 代表p是prev的左孩子，1代表p是prev的右孩子
    while(p){
        if(p->val==k){
            break;
        }
        prev=p;
        if(p->val>k){
            op=0; 
            p=p->left;
        }
        else{
            op=1;
            p=p->right;
        }
    }
    if(!p){
        printf("The node is not existed!\n");
        return;
    }
    // 已找到待删除的节点
    if(!p->left&&!p->right){//叶子节点，这里采用寻找后继的方法来补充
        if(!op) prev->left=NULL;
        else prev->right=NULL;
        free(p);
    }
    //右空左不空
    else if(p->left&&!p->right){
        if(!op)prev->left=p->left;
        else prev->right=p->left;
        free(p);
    }
    // 左空右不空
    else if(!p->left&&p->right){
        if(!op)prev->left=p->right;
        else prev->right=p->right;
        free(p);
    }
    // 度为2，这里采用找后继的方法
    else{
        TreeNode* next=p->right;
        while(next->left){
            next=next->left;
        }
        int v=next->val;
        Delete(p,v);//此时转换为度为1或者0的情况
        p->val=v;
    } 
}

TreeNode* prev=0;//该死的全局变量，啊米诺斯！

void Inthread(TreeNode* root){
    if(!root) return;
    Inthread(root->left);
    if(!root->left){
        root->ltag=1;
        root->left=prev;//prev要么定义为函数的引用参数，要么全局
    }
    if(prev&&!prev->right){
        prev->rtag=1;
        prev->right=root;
    }
    prev=root;
    Inthread(root->right);
}

void CreateInthread(TreeNode* root){
    TreeNode* curr=root;
    if(curr){
        Inthread(curr);
        prev->right=NULL;
        prev->rtag=1;
    }
}


void GetInorderSequsence(TreeNode* root){
    TreeNode* p=GetLeft(root);
    while(p){
        printf("%d ",p->val);
        if(p->rtag){//已经线索化，直接通过right指针找到后继
            p=p->right;
        }
        else{//未线索化，需要找到右子树的最左下的节点
            p=GetLeft(p->right);
        }
    }
}

int main(){
    TreeNode* root=Initial(10);
    // 构造搜索二叉树
    // for(int i=0;i<6;i++){
    //     Insert(root,3*i);
    // }
    Insert(root,3);
    Insert(root,12);
    Insert(root,11);
    Insert(root,13);

    Delete(root,12);

    // 二叉树中序线索化
    CreateInthread(root);
    //遍历中序线索二叉树
    GetInorderSequsence(root);
    return 0;
}
