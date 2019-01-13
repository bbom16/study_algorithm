//
//  2577.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  세 수의 곱을 이루고 있는 0~9까지의 숫자 개수 구하기

#include <stdio.h>

int main(int argc, char * argv[])
{
    int A,B,C, multi;
    int natural[10] ={0,};
    scanf("%d %d %d", &A,&B,&C);
    
    multi = A*B*C;
    
    while(multi > 0)
    {
        natural[multi%10]++;
        multi /= 10;
    }
    
    for(int i=0; i<10; i++)
        printf("%d\n", natural[i]);
    
    return 0;
}
