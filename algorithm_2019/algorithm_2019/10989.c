//
//  10989.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 22..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  counting sort 구현해보기, 전부 저장하면 메모리초과!! 저장하지않고 문제 해결.(누적합을 구하지않고 문제해결했다.

#include <stdio.h>

#define NUMOFNUM 10001

int num_arr[NUMOFNUM];        //숫자의 개수 배열

int N;

void Counting_Sort()
{
    int i;
    
    /* 정렬하기, 숫자가 나온적이 있으면 true */
    for(i=0; i<NUMOFNUM; i++){
        while(num_arr[i]--)
            printf("%d\n",i);
    }
}
void counting(int num)
{
    /* 숫자의 개수를 counting */
    num_arr[num]++;
    
    /* 누적합 구하기
     int i;
     for(i=0; i<NUMOFNUM; i++)
     num_arr[i] += num_arr[i-1];
     */
}

int main(int argc, char * argv[])
{
    int input_num;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d", &input_num);
        counting(input_num);
    }
    
    Counting_Sort();
    
    return 0;
}
