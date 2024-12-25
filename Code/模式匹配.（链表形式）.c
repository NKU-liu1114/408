#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

// 判断链表B是否是链表A的连续子序列
int Judge(Node* p,Node* q){
    //p,q分别指向A、B
    Node* r=p->next,*s=q->next,* prev=r;
    while(r!=NULL){
        if(r->data==s->data){
            prev=r;
            while(r!=NULL&&r->data==s->data){
                r=r->next;s=s->next;
                if(s==NULL)return 1;
            }
            //该趟匹配失败
            r=prev->next;//回溯
            s=q->next;//重置模式串指针
        }
        else r=r->next;
    }
    return 0;
}