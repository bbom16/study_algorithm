//
//  2775.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 13..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  부녀회장이 될테야 a층의 b호에 살려면 (a-1)층의 1호~b호까지의 입주민 수의 합만큼 같이 살아야함. dp 이용해서 문제 해결
/*
 for(int i=1; i<=n; i++)
 dp[k][n] += dp[k-1][i];
 */

#include <stdio.h>

int main(int argc, char * argv[])
{
    int T, k, n;    //k층 n호
    int dp[15][15] = {0,};
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &k, &n);
        
        /* 0층의 i호는 i명 거주 */
        for(int i=1; i<=n; i++)
            dp[0][i] = i;

        for (int i=1; i<=k; i++) {
            for(int j=1; j<=n; j++){
                for(int s=1; s<=j; s++)
                    dp[i][j] += dp[i-1][s];
            }
        }
        
        printf("%d\n", dp[k][n]);
        
        /* 이차원 배열 초기화 */
        for(int i=0; i<=k; i++){
            for(int j=0; j<=n; j++)
                dp[i][j] = 0;
        }
        
    }
    
    
    return 0;
}
