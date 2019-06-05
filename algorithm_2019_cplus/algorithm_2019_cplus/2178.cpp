//
//  2178.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 31..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int maze[101][101];
queue<pair<int,int> > bfs_que;
int N,M;

void bfs(){
    
    while(!bfs_que.empty()){
        /* 현재 위치 */
        pair<int,int> current = bfs_que.front();
        bfs_que.pop();
        
        int x = current.first;
        int y = current.second;
        
        /* 갈 수 있는 방향 확인 */
        for(int k=0; k<4; k++){
            int next_x = x+dx[k];
            int next_y = y+dy[k];
            
            /* 벽인 경우 제거 */
            if(next_x > N || next_x < 1 || next_y > M || next_y < 0) continue;
            
            /* 도착!*/
            if(next_x == N && next_y == M){
                maze[next_x][next_y] = maze[x][y]+1;
                return;
            }
            
            /* 처음 방문인지 방문할 수 있는지 확인 */
            if(maze[next_x][next_y] == 1)
            {
                maze[next_x][next_y] = maze[x][y]+1; //다음에 갈 곳을 지금 값 +1로 거리 계산해주기
                bfs_que.push(make_pair(next_x, next_y));
            }
        }
    }
    return;
}

int main(int argc, char * argv[]){
    
    scanf("%d %d", &N, &M);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++)
            scanf("%1d", &maze[i][j]);
    }
    bfs_que.push(make_pair(1,1));
    bfs();
    
    printf("%d\n", maze[N][M]);
    return 0;
}
