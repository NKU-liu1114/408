#include<stdlib.h>
#include<stdio.h>


void delete(int A[],int n){
    for(int i=1;i<n;i++){
        if(A[i]==A[i-1]){
            for(int j=i+1;j<n;j++){
                A[j-1]=A[j];
            }
            n--;i--;
        }
    }
    for(int k=0;k<n;k++){
        printf("%d ",A[k]);
    }
}
int main(){
    int A[10]={1,3,3,3,5,5,7,8,9,9};
    delete(A,10);
    return 0;

}