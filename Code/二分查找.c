#include<stdio.h>

// 找到返回索引，没找到返回-1
int Binary_Search(int* a,int len,int key){
    int low=0;
    int high=len-1;
    int mid;
    // 含义：在 [low,high]下标索引的闭区间内进行查找
    while(low<=high){
        mid=(low+high)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            high=mid-1;
        }
        else low=mid+1;
    }
    return -1;
}

int main(){
    int a[10]={1,4,9,14,16,23,27,30,38,41};
    printf("%d",Binary_Search(a,10,1));
    return 0;
}