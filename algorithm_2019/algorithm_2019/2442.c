//
//  2442.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  공백과 별의 개수로 접근

#include <stdio.h>

int main(int argc, char * argv[])
{
    int N;
    scanf("%d", &N);
    
    int j = 0;
    for(int i=1; i<N+1; i++)
    {
        for(j=0; j<N-i; j++)
            printf(" ");
        for(j=0;j<2*i-1;j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}
