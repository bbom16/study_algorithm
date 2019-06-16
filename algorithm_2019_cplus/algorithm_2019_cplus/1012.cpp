//
//  1012.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 6. 16..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  유기농 배추 dfs, bfs 구현

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int cabbage[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int M,N;

typedef struct location{
    int x;
    int y;
}LOCATE;

queue<LOCATE> que;
void bfs(){
    while(!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        que.pop();
        
        int next_x, next_y;
        for(int i=0;i<4; i++){
            next_x = x + dx[i];
            next_y = y + dy[i];
            
            if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
                continue;
            
            if(cabbage[next_x][next_y] == 0){
                cabbage[next_x][next_y] = cabbage[x][y];
                que.push({next_x, next_y});
            }
        }
    }
}
void dfs(int x, int y){
    int next_x, next_y;
    for(int i=0; i<4; i++){
        next_x = x + dx[i];
        next_y = y + dy[i];
        
        if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
            continue;
        
        if(cabbage[next_x][next_y] == 0){
            cabbage[next_x][next_y] = cabbage[x][y];
            dfs(next_x, next_y);
        }
    }
}

int main(int argc, char * argv[]){
    
    int T,K;
    scanf("%d", &T);
    
    int x, y;
    while(T--){
        scanf("%d %d %d", &M, &N, &K);
        /* 배열 초기화 */
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++)
                cabbage[i][j] = -1;
        }
        
        for(int i=0; i<K; i++){
            scanf("%d %d", &y, &x);
            cabbage[x][y] = 0;
        }
        
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(cabbage[i][j] == 0){
                    cabbage[i][j] = ++cnt;
                    //dfs(i,j);
                    que.push({i,j});
                    bfs();
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
