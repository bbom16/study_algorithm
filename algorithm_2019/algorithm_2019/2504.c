//
//  2504.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 25..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  괄호의 값, () = 2, [] = 3 - > 스택을 이용하여 문제를 해결한다.

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
    char input[31];
    int input_len,i,cal_num=1, case_num=0, answer=0;
    scanf("%s", input);
    
    input_len = strlen(input);
    
    for(i=0; i<input_len; i++){
        switch (input[i]) {
            case '(':
                case_num = 2;
            case '[':
                if(case_num != 2)
                    case_num = 3;
                cal_num *= case_num;
                push(&stack1, input[i]);
                case_num = 0;
                break;
            case ')':
                case_num = 2;
            case ']':
                if(case_num !=2)
                    case_num = 3;
                /* 잘못된 괄호 처리 */
                if(empty(&stack1)){
                    printf("0\n");
                    return 0;
                }
                if((case_num == 2 && pop(&stack1) != '(') ||
                   (case_num == 3 && pop(&stack1) != '[')){
                    printf("0\n");
                    return 0;
                }
                
                /* 바깥쪽 괄호, 더해지는 숫자를 나눠줌 */
                if((input[i-1] == ']' || input[i-1] == ')'))
                    cal_num /= case_num;
                
                /* 가장 안에 괄호로 숫자를 더해줌 */
                else{
                    answer += cal_num; 
                    cal_num /= case_num;
                }
                case_num = 0;
                break;
            default:
                break;
        }
    }
    /* 잘못된 괄호 처리 : 괄호가 다 닫히지 않은경우 */
    if(cal_num != 1)
        answer = 0;
    printf("%d\n", answer);
    
    
    return 0;
}


