#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 50


typedef struct{
    char* ch;
    int length;
}String;

void Initial(String* s){
    s->ch=(char*)malloc(sizeof(MAXSIZE+1));
    s->length=0;
}

void GetVal(String* s,char* m){
    int i=0;
    while(m[i]!='\0'){
        s->ch[i+1]=m[i];
        i++;
    }
    s->length=i;
}

void Output(String* s){
    for(int i=1;i<=s->length;i++){
        printf("%c",s->ch[i]);
    }
    printf("\n");
}

int KMP(String s,String t,int* next){
    int i=1,j=1;
    while(i<=s.length&&j<=t.length){
        if(j==0||s.ch[i]==t.ch[j]){
            i++;j++;
        }
        else{
            j=next[j];
        }
    }
    if(j>t.length){//匹配成功
        return i-t.length;
    }
    else return 0;//模式匹配失败
}

int* GetNext(String t){
    int* next=(int*)malloc(sizeof(int)*(t.length+1));
    // next[0]废弃
    next[1]=0;
    if(t.length==1){
        return next;
    }
    next[2]=1;
    int i=2,j=next[i-1];
    while(i<=t.length){
        if(j==0||t.ch[i-1]==t.ch[j]){
            next[i]=++j;
            // 即j位的前后缀相同，++j即为匹配失败时应跳转的位置
            i++;
            // i++后，开始求next[i+1]的值，而此时的j指针刚好留在了next[i]上
        }
        else{
            j=next[j];
        }
    }
    return next;
}
int main(){
    String str1,str2;
    Initial(&str1);
    Initial(&str2);
    GetVal(&str1,"abaabcccbaa");
    GetVal(&str2,"ccbaa");
    int* p=GetNext(str2);
    printf("%d",KMP(str1,str2,p));
    return 0;
}


