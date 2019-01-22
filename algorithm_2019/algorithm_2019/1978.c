//
//  1978.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 22..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  소수 찾기, 에라토스테네스의 체를 사용한다. (끝까지 비교할 필요없고, N까지의 소수이면 N의 제곱근까지만 구하면 된다.)

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 1001
#define MAX_INDEX 101

bool is_prime[MAX_NUM];
int num_arr[MAX_INDEX];

int main(int argc, char * argv[])
{
    int N, i, j;
    int answer = 0;
    double sqrt_val = sqrt(MAX_NUM);
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++)
        scanf("%d", &num_arr[i]);
    
    for(i=2; i<MAX_NUM; i++)
        is_prime[i] = true;
    
    /* 에라토스테네스의 체 */
    for(i=2; i<sqrt_val; i++){
        if(!is_prime[i]) continue;
        for(j=i*i; j<MAX_NUM; j+=i){
            if(is_prime[j]) is_prime[j] = false;
        }
    }
    for(int i=0; i<N; i++)
        if(is_prime[num_arr[i]]) answer++;
    
    printf("%d\n", answer);
    
    return 0;
}
