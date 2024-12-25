#include<iostream>
#include<deque>
using namespace std;
#define MAXVEX 10
typedef struct Graph{
    int vexnum;
    int edgenum;
    int Arr[MAXVEX][MAXVEX]={0};
}Graph;


//判断是否有唯一的拓扑排序
bool TopologicalSort(Graph G){
    deque<int> dq;
    int n=G.vexnum;
    int Indegree[n];
    for(int i=0;i<n;i++){
        Indegree[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(G.Arr[i][j]){
                Indegree[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!Indegree[i]){
            dq.push_back(i);
        }
    }
    int cnt=0;
    while(!dq.empty()){
        int p=dq.front();
        dq.pop_front();
        cout<<p<<" ";
        for(int i=0;i<n;i++){
            if(G.Arr[p][i]){
                Indegree[i]--;
                if(!Indegree[i]){
                    dq.push_back(i);
                }
            }
        }
        cnt++;
        // 当前有多个候选节点
        if(dq.size()!=1){
            return false;
        }
    }
    if(cnt==n)return true;
    return false;
}
void Insert(Graph& G,int i,int j){
    G.Arr[i][j]=1;
    G.edgenum++;
}
int main(){
    Graph g;
    g.vexnum=6;
    g.edgenum = 0;
    Insert(g,0,3);
    Insert(g,0,1);
    Insert(g,1,4);
    Insert(g,3,1);
    Insert(g,2,0);
    Insert(g,2,5);
    Insert(g,3,5);
    Insert(g,5,4);
    bool f=TopologicalSort(g);
    cout<<endl<<f<<endl;
    return 0;
}
