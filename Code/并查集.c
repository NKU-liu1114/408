#include<stdio.h>
#define MAXSIZE 100


//S[i]=A
// A>0,则S与A属于同一集合
// A<0,则A为该集合的根节点，且-A为集合元素数目

void Initial(int S[]){
    for(int i=0;i<MAXSIZE;i++){
        S[i]=-1;//不属于任何集合
    }
}

// 返回k号节点所属集合的根节点编号
int Find(int k,int S[]){
    int root=k;
    while(S[root]>=0){
        root=S[root];
    }
    int temp;
    // 压缩路径
    while(S[k]>=0){
        temp=S[k];
        S[k]=root;
        k=temp;
    }
    return root;
}

// 把a和b所属的集合合并，且小集合合并到大集合
void Union(int* S,int a,int b){
    int root1=Find(a,S);
    int root2=Find(b,S);
    if(root1==root2)return;
    if(S[root1]<S[root2]){
        S[root1]+=S[root2];
        S[root2]=root1;
    }
    else{
        S[root2]+=S[root1];
        S[root1]=root2;
    }
}

int main(){
    int S[MAXSIZE];
    Initial(S);
    Union(S,1,3);
    printf("%d",Find(1,S));
    return 0;
}