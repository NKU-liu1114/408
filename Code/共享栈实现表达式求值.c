#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h> 
#define MaxSize 100

typedef struct{
    int data[MaxSize];
    int top1;
    int top2;
} ShareStack;

void InitStack(ShareStack *S){
    S->top1 = -1;
    S->top2 = MaxSize;
}

bool Full(ShareStack S){
    return S.top1 == S.top2 - 1;
}

bool Push(ShareStack *S, int op, int e){
    if(S->top1 == S->top2 - 1){ //栈满
        return false;
    }
    if(op){
        S->data[--S->top2] = e;
    }
    else{
        S->data[++S->top1] = e;
    }
    return true;
}

bool Pop(ShareStack *S, int op, int* e){
    if(op){
        if(S->top2 == MaxSize){
            return false;
        }
        else{
            *e = S->data[S->top2++]; 
            return true;
        }
    }
    else{
        if(S->top1 == -1){
            return false;
        }
        else{
            *e = S->data[S->top1--];
            return true;
        }
    }
}

bool GetTop(ShareStack *S, int op, int* e){
    if(op){
        if(S->top2 == MaxSize){
            return false;
        }
        else{
            *e = S->data[S->top2]; 
            return true;
        }
    }
    else{
        if(S->top1 == -1){
            return false;
        }
        else{
            *e = S->data[S->top1];
            return true;
        }
    }
}

void GetValue(ShareStack* S,int opcode){
    int a=0,b=0;
    Pop(S,1,&b);
    Pop(S,1,&a);
    int res;
    if(opcode=='+'){
        res=a+b;
    }
    if(opcode=='-'){
        res=a-b;
    }
    if(opcode=='*'){
        res=a*b;
    }
    if(opcode=='/'){
        res=a/b;
    }
    Push(S,1,res);
}

int main(){
    ShareStack S;
    InitStack(&S);
    char buffer[50]; 
    scanf("%s",buffer);
    for(int i=0;buffer[i]!='\0';i++){
        if(buffer[i]>='0'&&buffer[i]<='9'){
            int number=buffer[i]-'0';
            i++;
            while(buffer[i]>='0'&&buffer[i]<='9'){
                number=number*10+buffer[i]-'0';
                i++;
            }
            i--;//退回预读的一位
            Push(&S,1,number);
        }
        else if(buffer[i]=='('){
            Push(&S,0,buffer[i]);
        }
        else if(buffer[i]==')'){
            int a=0;
            while(GetTop(&S,0,&a)&&a!='('){ 
                Pop(&S,0,&a);
                GetValue(&S,a);
            }
            Pop(&S,0,&a);//让'('出栈
        }
        else if(buffer[i]=='*'||buffer[i]=='/'){
            int a=0;
            while(GetTop(&S,0,&a)&&(a=='*'||a=='/')){
                Pop(&S,0,&a);
                GetValue(&S,a);
            }
            Push(&S,0,buffer[i]);
        }
        else if(buffer[i]=='+'||buffer[i]=='-'){
            int a=0;
            while(GetTop(&S,0,&a)&&a!='('){
                Pop(&S,0,&a);
                GetValue(&S,a);
            }
            Push(&S,0,buffer[i]);
            int k;
            GetTop(&S,1,&k);
        }
        else{
            printf("Error!\n");
            break;
        }
    }
    int e=0;
    // 让符号栈中剩余的符号出栈
    while(Pop(&S,0,&e)){
        GetValue(&S,e);
    }
    // 最后留在数值栈里的即为最终结果
    Pop(&S,1,&e);
    printf("The result is:%d",e);
    return 0;
}
