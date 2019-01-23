//
//  2581.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 23..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  소수, M과 N사이의 소수들의 합과 최솟값을 구한다.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int M,N,i,sum,min_val = 0;
    double sqrt_val;
    bool is_prime[10000];
    bool find_min = false;
    
    scanf("%d %d", &M,&N);
    
    sqrt_val = sqrt(N);
    
    /* 소수 찾기 */
    for(i=2; i<=N; i++)
        is_prime[i] = true;
    
    for(i=2; i<sqrt_val; i++){
        if(!is_prime[i]) continue;
        for(int j=i*i; j<=N; j+=i){
            if(is_prime[j]) is_prime[j] = false;
        }
    }
    
    /* 소수들의 합과 최솟값 구하기 */
    sum = 0;
    for(i=M; i<=N; i++){
        if(is_prime[i]){
            if(!find_min){
                min_val = i;
                find_min = true;
            }
            sum += i;
        }
    }
    
    if(sum == 0) printf("-1\n");
    else printf("%d\n%d\n", sum, min_val);
    
    return 0;
}
