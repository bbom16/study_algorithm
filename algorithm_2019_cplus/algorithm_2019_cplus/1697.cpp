//
//  1697.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 6. 15..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  bfs 구현, N > K 경우까지 생각

#define ARRAY_SIZE 20 + 1
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int point[ARRAY_SIZE];
int N,K;
int dx[] = {-1,1};
void bfs(){
    queue<int> que;
    que.push(N);
    
    int current_x, next_x;
    while(!que.empty()){
        current_x = que.front();
        que.pop();
        
        if(current_x == K) return;

        /* x-1, x+1 */
        for(int i=0; i<2; i++){
            next_x = current_x + dx[i];
            if(next_x > 2*K || next_x < 0 || point[next_x] > 0) continue;
            que.push(next_x);
            point[next_x] = point[current_x] + 1;
        }
        
        /* 2 * x */
        next_x = 2 * current_x;
        if(next_x > 2*K || point[next_x] > 0) continue;
        que.push(next_x);
        point[next_x] = point[current_x] + 1;
    }
}
int main(int argc, char * argv[]){

    scanf("%d %d", &N, &K);
    point[N] = 1;
    
    if(N > K) point[K] = N - K + 1;
    else bfs();
  
    printf("%d\n", point[K]-1);
    return 0;
}
