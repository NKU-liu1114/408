#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

// 王道课后题2.3.7 第六题
// 把一个（a1,b1,a2,b2……,an-1,bn-1,an,bn）的链表分裂成一个（a1,a2,a3……）和一个（bn,bn-1,……）的链表
void func(Node* head){
    Node* head1=(Node*)malloc(sizeof(Node));
    Node* head2=(Node*)malloc(sizeof(Node)); 
    head1->next=NULL;
    head2->next=NULL;
    int turn=0;
    Node* p=head->next,*q=head1;
    while(p!=NULL){
        head->next=p->next;
        if(turn%2==0){
            p->next=NULL;
            q->next=p;
            q=p;
        }
        else{
            p->next=head2->next;
            head2->next=p;
        }
        p=head->next;
        turn++;
    }
    free(head);
}