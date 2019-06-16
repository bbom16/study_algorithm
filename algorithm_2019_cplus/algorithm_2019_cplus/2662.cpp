//
//  2662.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 6. 11..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  기업투자 dp 
#define ARRAY_SIZE 300+1
#include <stdio.h>
#include <iostream>
using namespace std;

/* 각 기업 투자 상황을 저장한 구조체 */
typedef struct company{
    int money[20+1];
}COMP;

/* company : 각 기업 당 투자금액, dp : j 기업까지 i 금액을 투자했을 때 얻을 수 있는 최대 금액 */
int company[ARRAY_SIZE][20+1], dp[ARRAY_SIZE][20+1];
COMP invest[ARRAY_SIZE][20+1];
int main(int argc, const char * argv[]){
    
    int N,M,i,j; // i : 돈 , j : 기업
    scanf("%d %d", &N, &M);
    
    for(i=1; i<=N; i++){
        for(j=0; j<=M; j++){
            scanf("%d", &company[i][j]);
            dp[i][j] = company[i][j];
            invest[i][j].money[j] = i;
        }
    }
    
    // dp[i][j] = max(dp[i][j], max(dp[i-k][j-1]+company[k][j], dp[i][j-1]))
    for(i=1; i<=N; i++){
        for(j=1; j<=M; j++){
            for(int k=1; k<=i; k++){
                if(dp[i][j] < dp[i-k][j-1] + company[k][j]){
                    dp[i][j] = dp[i-k][j-1] + company[k][j];
                    for(int l=1; l<=j-1; l++){
                        invest[i][j].money[l] = invest[i-k][j-1].money[l];
                    }
                    invest[i][j].money[j] = k;
                }
                if(dp[i][j] < dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                    for(int l=1; l<=j; l++){
                        invest[i][j].money[l] = invest[i][j-1].money[l];
                    }
                }
            }
        }
    }
    
    printf("%d\n", dp[N][M]);
    for(i=1; i<=M; i++){
        printf("%d ", invest[N][M].money[i]);
    }
    printf("\n");
    
    return 0;
}
