//
//  9020.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 23..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  골드바흐의 추측, 짝수는 두 소수의 합으로 나타낼 수 있다. 짝수 N이 들어오면 두 소수의 합으로 출력해라(여러개이면 두 수의 차이가 작은 것으로)

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

typedef struct goldbah{
    int prime1;
    int prime2;
    int diff;
}GB;

bool is_prime[10001];
bool is_visit[10001];
GB gbs[10001];

int main(int argc, char * argv[])
{
    int T,n,i,j,k,sqrt_val,min_diff,min_index;
    
    scanf("%d", &T);
    
    while(T--){
        scanf("%d", &n);
        sqrt_val = sqrt(n);
        
        /* 소수 구하기 */
        for(i=2; i<=n; i++)
            is_prime[i] = true;
        
        for(i=2; i<=sqrt_val; i++){
            if(!is_prime[i]) continue;
            for(j=i*i; j<=n; j+=i){
                if(is_prime[j]) is_prime[j] = false;
            }
        }
        
        /* 골드바흐 파티션 구하기 */
        k = 0;
        for(i=2; i<=n; i++){
            if(!is_visit[i] && is_prime[i]){
                if(!is_visit[n-i] && is_prime[n-i]){
                    gbs[k++] = (GB){i,n-i,abs(n-2*i)};    //둘 다 소수이면 두 수와 그 차이값 저장.
                    is_visit[i] = true; is_visit[n-i] = true;
                }
            }
        }
        
        min_index = 0; min_diff = 10000;
        
        if(k == 1)
            printf("%d %d\n", gbs[0].prime1, gbs[0].prime2);
        else{
            for(i=0; i<k; i++){
                if(min_diff > gbs[i].diff) {
                    min_diff = gbs[i].diff;
                    min_index = i;
                }
            }
            printf("%d %d\n", gbs[min_index].prime1, gbs[min_index].prime2);
            
        }
        /* 초기화 */
        for(i=0; i<k; i++){
            is_visit[gbs[i].prime1] = false; is_visit[gbs[i].prime2] = false;
            gbs[i] = (GB){0,0,0};
        }
        
    }
    return 0;
}

