//
//  7576.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 6. 5..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  bfs

#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define ARRAY_SIZE 1001
int M,N;
int tomato[ARRAY_SIZE][ARRAY_SIZE];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<pair<int,int> > bfs_que;

int bfs(){
    int next_x,next_y,x=0,y=0;
    
    while(!bfs_que.empty()){
        x = bfs_que.front().first;
        y = bfs_que.front().second;
        bfs_que.pop();
        
        if(tomato[y][x] <= 0) continue;
        
        for(int i=0; i<4; i++){
            next_x = x + dx[i];
            next_y = y + dy[i];
            
            /* 배열 크기 넘어가거나 토마토 없는 경우 제외 */
            if(next_x >= M || next_x < 0 || next_y >=N || next_y < 0 || tomato[next_y][next_x] == -1)
                continue;
            
            /* 토마토 방문 */
            if(tomato[next_y][next_x] == 0){
                tomato[next_y][next_x] = tomato[y][x] + 1;
                bfs_que.push(make_pair(next_x, next_y));
            }
        }
    }
    return tomato[y][x];
}

int main(int argc, char * argv[]){
    
    
    scanf("%d %d", &M,&N);
    
    int no_tomato = 0;
    
    /* 처음 토마토가 있는 거 부터 큐에 넣어서 bfs 돌리자! */
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == -1) no_tomato++;
            else if(tomato[i][j] == 1){
                bfs_que.push(make_pair(j, i));
                no_tomato++;
            }
            
        }
    }
    
    
    bfs();
    
    int answer = 0;
    
    for(int i=0; i<N; i++){
        if(answer == -1) break;
        for(int j=0; j<M; j++){
            if(tomato[i][j] == 0){
                answer = -1;
                break;
            }
            if(answer < tomato[i][j]) answer = tomato[i][j]-1;
        }
    }
    
    printf("%d\n" , answer);
    
    return 0;
}
