#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

// a,b为两个链表表头，均为递增链表，a链表中最终保留a,b的公共元素
void func(Node* a,Node* b){
    Node* p=a->next,*q=b->next,*temp=b;
    while(p!=NULL&&q!=NULL){
        while(q!=NULL&&q->data<p->data)q=q->next;
        if(p->data==q->data){
            //保留A中该节点
            temp=p;
            p=p->next;
        }
        else{
            temp->next=p->next;
            free(p);
            p=temp->next;
        }
    }
    if(q==NULL){
        temp->next=NULL;
    }
}