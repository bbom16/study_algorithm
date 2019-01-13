//
//  2839.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 3..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    int N, sugar = 0; //필요한 킬로그램, 설탕 봉지 수
    scanf("%d", &N);
    
    /* 5로 전부 나눈 다음에 3의 배수가 아니면 5씩 더해주면서 답 구하기 */
    int origin_N = N;
    sugar += N/5;
    N %= 5;

    while(1)
    {
        if(N%3 == 0)
        {
            sugar += N/3;
            break;
        }
    
        if(N >= origin_N)
        {
            sugar = -1;
            break;
        }
        N += 5;
        sugar--;
    }

    printf("%d\n", sugar);
    return 0;
}
