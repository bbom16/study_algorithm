//
//  2908.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 8..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  상수, 상수는 단어를 이상하게 읽음. 734 -> 437로 읽음. 이렇게 바뀐 세자리 숫자 2개를 비교

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char num[10];
    
    fgets(num, sizeof(num), stdin);
    
    char * ptr = strtok(num, " ");  //" " 기준으로 문자열 자르기
    char tmp;
    int change_num[2];
    int i = 0;
    while(ptr != NULL){
        tmp = ptr[0];
        ptr[0] = ptr[2];
        ptr[2] = tmp;
        change_num[i] = atoi(ptr);
        i++;
        ptr = strtok(NULL, " ");
    }
    if(change_num[0] > change_num[1]) printf("%d\n", change_num[0]);
    else printf("%d\n", change_num[1]);
    return 0;
}
