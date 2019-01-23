//
//  1928.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 23..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  소수 구하기

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int M,N,i,j;
    double sqrt_val;
    bool is_prime[1000001];
    
    scanf("%d %d", &M,&N);
    
    /* 소수 구하기 */
    for(i=2; i<=N; i++)
        is_prime[i] = true;
    
    sqrt_val = sqrt(N);
    
    for(i=2; i<sqrt_val; i++){
        if(!is_prime[i]) continue;
        for(j=i*i; j<=N; j+=i){
            if(is_prime[j]) is_prime[j] = false;
        }
    }
    
    for(i=M; i<=N; i++){
        if(is_prime[i]) printf("%d\n", i);
    }
    
    return 0;
}
