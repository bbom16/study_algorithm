//
//  1520.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 6. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  dp + dfs로 해결

#include <iostream>

using namespace std;

int map[501][501], dp[501][501];
int dx[] = {0,0,1,-1}, dy[] = {-1,1,0,0};
int M,N;

int find_load(int x, int y){
    
    /* 전에 이미 왔었으면 그냥 리턴 */
    if(dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0; //방문하면 0
    for(int k=0; k<4; k++){
        int next_x = x+dx[k];
        int next_y = y+dy[k];
        
        /* 벽인 경우 제외 */
        if(next_x >= N || next_x < 0 || next_y >= M || next_y < 0) continue;
        
        /* 내려갈 수 있는 경우 */
        if(map[next_y][next_x] < map[y][x]){
            dp[y][x] += find_load(next_x, next_y);
        }
    }
    return dp[y][x];
}

int main(int argc, char * argv[]){
    /* -1로 dp 초기화 해주기 (0으로 하면 경로가 없는 경우와 구별되지 않아 무한루프에 빠짐) */
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    }
    
    dp[M-1][N-1] = 1;
    printf("%d\n", find_load(0, 0));
    
    return 0;
}
