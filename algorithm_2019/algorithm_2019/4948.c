//
//  4948.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 23..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  베르트랑 공준 n~2n사이에 소수의 개수를 구하기

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
    int n, i, sqrt_val , answer = 0;
    bool is_prime[246913];
    
    while(1){
        scanf("%d", &n);
        
        if(n == 0) break;
        sqrt_val = sqrt(2*n);
        
        for(i=2; i<=2*n; i++)
            is_prime[i] = true;
        
        /* 2n의 제곱근까지 배수들을 체크 */
        for(i=2; i<=sqrt_val; i++){
            if(!is_prime[i]) continue;
            for(int j=i*i; j<=2*n; j+=i){
                if(is_prime[j]) is_prime[j] = false;
            }
        }
        
        for(i=n+1; i<2*n+1; i++){
            if(is_prime[i]) answer++;
        }
        
        printf("%d\n", answer);
        answer = 0;
    }
    return 0;
}
