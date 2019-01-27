//
//  9012.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 25..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  괄호, vps 여부 확인. stack으로 '('이면 push, ')'이면 pop해서 stack이 비면 YES

#include <stdio.h>
#include <string.h>

typedef struct stack{
    int num[100];
    int top;
    int size;
}STC;

int top(STC * stc)
{
    int top;
    if(stc->size == 0) top = -1;
    else top = stc->num[stc->top];
    return top;
}

void push(STC * stc, int n)
{
    int k = stc->size;
    stc->num[k] = n;
    stc->top = k;
    stc->size++;
}

int pop(STC * stc)
{
    int top1 = top(stc);
    if(top1 != -1){
        stc->top--;
        if(stc->top == -1) stc->top = 0;
        stc->size--;
    }
    
    return top1;
}

int size(STC * stc)
{
    return stc->size;
}

int empty(STC * stc)
{
    if(stc->size == 0) return 1;
    else return 0;
}

STC stack1;

int main(int argc, char * argv[])
{
    int T,i, len_val;
    scanf("%d", &T);
    
    char input[51];
    
    while(T--){
        scanf("%s" , input);
        len_val = strlen(input);
        
        for(i=0; i<len_val; i++){
            if(input[i] == '(')
                push(&stack1, '(');
            else if(input[i] == ')')
            {
                if(empty(&stack1)) break;
                pop(&stack1);
            }
        }
        if(i == len_val && empty(&stack1)) printf("YES\n");
        else printf("NO\n");
        
        stack1.size = 0;
        stack1.top =0;

    }
    return 0;
}
