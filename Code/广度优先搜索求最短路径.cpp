#include<iostream>
#include<deque>
using namespace std;
#define MAXVEX 10

// 有向图
// 采用邻接表来存储图
typedef struct ArcNode{
    int val;
    ArcNode* next;
}ArcNode;

typedef struct VexNode{
    ArcNode* first;
}VexNode;

typedef struct{
    VexNode v[MAXVEX];
    int vexnum,edgenum;
}Graph;

void Insert(Graph& g,int i,int j){
    ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
    p->val=j;
    p->next=nullptr;
    if(!g.v[i].first){
        g.v[i].first=p;
        return;
    }
    ArcNode* curr=g.v[i].first;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=p;

    g.edgenum++;
}

void bfs(Graph g,int src){
    int n=g.vexnum;
    int *dist=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    int curr;
    deque<int> dq;
    dq.push_back(src);
    while(!dq.empty()){
        curr=dq.front();
        dq.pop_front();
        ArcNode* p=g.v[curr].first;
        while(p){
            if(dist[p->val]==INT_MAX){
                dist[p->val]=dist[curr]+1;
                dq.push_back(p->val);
            }
            p=p->next;
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<"Infinity"<<" ";
        }
        else cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Graph g;
    g.edgenum=0;
    g.vexnum=8;
    int n=g.vexnum;
    for(int i=0;i<n;i++){
        g.v[i].first=nullptr;
    }
    Insert(g,0,1);
    Insert(g,0,2);
    Insert(g,0,3);
    Insert(g,0,5);
    Insert(g,2,7);
    Insert(g,3,1);
    Insert(g,4,3);
    Insert(g,5,2);
    Insert(g,6,4);
    Insert(g,7,4);
    Insert(g,7,6);
    bfs(g,0);
    return 0;
}
