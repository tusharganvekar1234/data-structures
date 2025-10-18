// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#include <string.h>
struct stack{
    char data[SIZE];
    int top;
};
typedef struct stack STACK;
void push(STACK *s,char item){
    if(s->top==SIZE-1){
    printf("\n stack overflow");}
    else{
    s->top=s->top+1;
    s->data[s->top]=item;}
}
char pop(STACK *s){
    if(s->top==-1){
        printf("\n stack underflow");
    }
    return s->data[(s->top)--];
}
int main(){
    STACK s;
    s.top=-1;
    int i;
    char data[100],rev[200];
    printf("\n enter a sequence:");
    fgets(data,100,stdin);
    for(i=0;data[i]!='\0';i++){
        if(data[i]=='\n'){
        data[i]='\0';
        break;}
    }
    for(i=0;i<strlen(data);i++){
        push(&s,data[i]);
    }
    for(i=0;i<strlen(data);i++){
        rev[i]=pop(&s);
    }
    rev[i]='\0';
    
    if(strcmp(rev,data)==0)
    printf("\n given str is palindrome");
    else
    printf("\n given str is not a palindrome");
    
    return 0;
}
