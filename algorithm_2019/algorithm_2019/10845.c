//
//  10845.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 28..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  큐, FIFO

#include <stdio.h>
#include <string.h>

typedef struct queue
{
    int num[10001];
    int front;
    int back;
    int size;
    
}Queue;

void push(Queue * que, int X)
{
    que->num[que->back++] = X;
    que->size++;
    /* 범위 유지 */
    if(que->back > 10000)
        que->back %= 10000;
}
int empty(Queue * que)
{
    if(que->size == 0)
        return 1;
    else
        return 0;
}

int pop(Queue * que)
{
    int front = que->num[que->front];
    if(empty(que))
        return -1;
    else{
        que->front++;
        /* 범위 유지 */
        if(que->front > 10000)
            que->front %= 10000;
        que->size--;
        
        /* que가 비면 index 다시 0부터 시작하도록 */
        if(empty(que)){
            que->front = 0;
            que->back = 0;
        }
        return front;
    }
}


Queue que;
int main(int argc, char * argv[])
{
    int N,push_num,answer=0;
    char input[10];
    
    scanf("%d", &N);
    
    while(N--){
        scanf("%s", input);
        if(!strcmp(input, "push")){
            scanf("%d", &push_num);
            push(&que, push_num);
        }
        else if(!strcmp(input, "pop")){
            answer = pop(&que);
            printf("%d\n", answer);
        }
        else if(!strcmp(input, "size")){
            answer = que.size;
            printf("%d\n", answer);
            
        }
        else if(!strcmp(input, "empty")){
            answer = empty(&que);
            printf("%d\n", answer);
        }
        else if(!strcmp(input, "front")){
            if(empty(&que)) answer = -1;
            else answer = que.num[que.front];
            printf("%d\n", answer);
        }
        
        else if(!strcmp(input, "back")){
            if(empty(&que)) answer = -1;
            else answer = que.num[que.back-1];
            printf("%d\n", answer);
        }
        
    }
    
    return 0;
}
