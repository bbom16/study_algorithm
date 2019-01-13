//
//  11720.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  문자열로 받아서 계산

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int N, ans = 0; //더할 숫자의 개수와 숫자 모음, 답
    char num[100];
    scanf("%d", &N);
    scanf("%s", num);
    
    for(int i=0; i<N; i++){
        ans += num[i] - '0'; // 아스키코드를 이용한 형변환 
    }
    printf("%d\n", ans);
    
    return 0;
}
