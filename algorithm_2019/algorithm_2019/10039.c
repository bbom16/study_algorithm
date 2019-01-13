//
//  10039.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  평균점수 구하기

#include <stdio.h>

int main(int argc, char * argv[])
{
    int score[5];
    int average = 0;
    
    for(int i=0; i<5; i++){
        scanf("%d", &score[i]);
        if(score[i] < 40) score[i] = 40;
    }

    for(int i=0; i<5; i++)
        average += score[i];
    
    printf("%d\n", average/5);
    
    return 0;
}
