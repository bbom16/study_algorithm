//
//  10828.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 24..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  스택, 스택 구현하기

#include <stdio.h>
#include <string.h>

typedef struct stack{
    int num[10000];
    int top;
    int size;
}STC;

void push(STC * stc, int n)
{
    int k = stc->size;
    stc->num[k] = n;
    stc->top = k;
    stc->size++;
}

int pop(STC * stc)
{
    int top;
    if(stc->size == 0) top = -1;
    else {
        top = stc->num[stc->top];
        stc->top--;
        if(stc->top == -1) stc->top = 0;
        stc->size--;
    }
    return top;
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

int top(STC * stc)
{
    int top;
    if(stc->size == 0) top = -1;
    else top = stc->num[stc->top];
    return top;
}

int main(int argc, char * argv[])
{
    int N, answer;
    
    STC stack1;
    stack1.size = 0;
    stack1.top = 0;
    
    scanf("%d", &N);
    
    char recommand[10]; // 명령어
    int rcm_num;
    
    while(N--){
        scanf("%s", recommand);
        if(!strcmp(recommand,"push")){
            scanf("%d", &rcm_num);
            push(&stack1, rcm_num);
        }
        else if(!strcmp(recommand,"pop")){
            answer = pop(&stack1);
            printf("%d\n", answer);
        }
        else if(!strcmp(recommand,"size")){
            answer = size(&stack1);
            printf("%d\n", answer);
        }
        else if(!strcmp(recommand,"empty")){
            answer = empty(&stack1);
            printf("%d\n", answer);
        }
        else if(!strcmp(recommand,"top")){
            answer = top(&stack1);
            printf("%d\n", answer);
        }
        
        recommand[0] = '\0';
    }
    
    return 0;
}
