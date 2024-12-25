#include<stdlib.h>
#include<stdio.h>


void reverse(int C[],int start,int end,int n){//逆置顺序表C[start-end],表长为n
    if(start>end||end>=n){
        printf("error!");
        return;
    }
    int sublen=end-start+1;
    int temp=INT_MIN;
    for(int i=0;i<sublen/2;i++){
        temp=C[start+i];
        C[start+i]=C[end-i];
        C[end-i]=temp;
    }
}

int main(){
    int a[8]={1,2,3,4,5,6,7,8};
    reverse(a,0,3,8);
    reverse(a,4,7,8);
    reverse(a,0,7,8);
    for(int i=0;i<8;i++){
        printf("%d ",a[i]);
    }
    return 0;
}