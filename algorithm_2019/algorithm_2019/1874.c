//
//  1874.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 25..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  스택 수열, 스택으로 주어진 수열을 만들 수 있는가. (수열은 오름차순으로 push된다.) -> 직접해보고 안되면 no 

#include <stdio.h>

typedef struct stack{
    int num[100001];
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


STC stack1;
int sequence[100001];   //input 수열
char answer[200001];    //숫자 하나당 +,- 가 나옴

int main(int argc, char * argv[])
{
    int n, i, j = 0, push_num = 1; //push_num : 현재까지 push 되어야 할 숫자
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
        scanf("%d" , &sequence[i]);
    
    for(i=0; i<n; i++){
        while(sequence[i] >= push_num){
            push(&stack1, push_num++);
            answer[j++] = '+';
        }
        if(sequence[i] < push_num){
            if(pop(&stack1) != sequence[i]){
                printf("NO\n");
                return 0;
            }
            answer[j++] = '-';
        }
    }
    
    for(i=0; i<j; i++)
        printf("%c\n", answer[i]);
    return 0;
}
