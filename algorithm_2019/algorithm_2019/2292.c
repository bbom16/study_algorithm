//
//  2292.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 10..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  벌집, N번 방을 주면 1번 방부터 시작해서 그 방에 도착할 수 있는 최소 개수 -> 내가 몇번째 바퀴에 위치하는 지 구하면 됨.

#include <stdio.h>

int main(int argc, char * argv[])
{
    int N;
    scanf("%d", &N);
    
    int room = 2;
    int cnt = 0;    //바퀴수 - 1
    
    /* 몇번째 바퀴인지 구함. */
    
    while(1){
        cnt++;
        if(N<=room) {
            if(N==room) cnt++;
            break;
        }
        room += cnt*6;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
