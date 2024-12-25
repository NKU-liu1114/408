#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> // 引入布尔类型的定义
// 带头结点的单链表操作实现

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList L){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    return true;
}

int Length(LinkList L){
    LNode *p=L->next;
    int j=0;
    while(p!=NULL){
        p=p->next;
        j++;
    }
    return j;
}

void PrintList(LinkList L){
    LNode *p=L->next;
    printf("The Elements:");
    while(p!=NULL){
        printf("%d",(int)p->data);
        printf(" ");
        p=p->next;
    }
    printf("\n");
}

bool Empty(LinkList L){
    return L->next==NULL;
}

void DestroyList(LinkList L){
    LNode *p=L->next;
    while(p!=NULL){
        free(L);
        L=p;
        p=p->next;
    }
    free(L);
}

ElemType GetElem(LinkList L,int i){// 按位查找位序为i的节点值
    if(i<0)
        return -1;
    int j=0;
    LNode* p=L;
    while(p!=NULL&& j<i){
        p=p->next;
        j++;
    }
    if(!p)
        return -1;
    // 此时j=i
    else return p->data;
}

int LocateElem(LinkList L,ElemType e){// 返回位序
    int j=1; 
    LNode* p=L->next;
    while(p!=NULL){
        if(p->data==e){
            return j;
        }
        j++;
        p=p->next;
    }
    if(!p) return -1;//未找到则返回-1
}

bool ListInsert(LinkList L,int i,ElemType e){
    if(i<0) return false;
    int j=0;
    LNode *p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    LNode* s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

bool ListDelete(LinkList L,int i,ElemType* e){
    if(i<0) return false;
    int j=0;
    LNode *p=L;
    while(p!=NULL&&j<i-1){//找到要删节点的前一个
        p=p->next;
        j++;
    }
    if(p==NULL||p->next==NULL) return false;
    LNode* q=p->next;
    *e=(q->data);
    p->next=q->next;
    free(q);
    return true;
}

int main(){
    LinkList L;
    InitList(L);
    for(int i=1;i<=5;i++){
        ListInsert(L,i,2*i);
    }
    int e=-1;
    ListDelete(L,1,&e);
    printf("%d\n",e);
    PrintList(L);
    printf("length:%d\n",Length(L));
    printf("%dth Element:%d\n",3,GetElem(L,3));
    printf("The index of Element %d:%d\n",6,LocateElem(L,6));
    return 0;
}