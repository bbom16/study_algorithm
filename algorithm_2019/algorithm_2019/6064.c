//
//  6064.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 14..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  카잉 달력, <M:N>과 <x:y>가 주어질 때, <x:y>가 몇번째 해인지 맞혀라. 천간과 12지간 같은 윈리인듯. 그냥 1씩 증가시키면 시간초과.
//  x에 해당하는 해가 몇 번째로 반복되는지 찾고 그다음 y를 비교한다.

#include <stdio.h>

int main(int argc, char * argv[])
{
    int T, M, N, x, y;
    scanf("%d",&T);
    
    int answer = 1; //답, 몇번째 해
    while(T--){
        scanf("%d %d %d %d", &M, &N, &x, &y);
        
        int cpr_y = x%N; //y값 찾기
        if(cpr_y == 0) cpr_y = N;
        int i=0;
        

        while(1){
            answer = M*(i++)+x;
            if(cpr_y == y) break;
            else if(i != 1 && (cpr_y == x || answer >= M*N)) {  //유효하지않은 경우
                answer = -1;
                break;
            }
            
            cpr_y = (cpr_y+M)%N;
            if(cpr_y == 0) cpr_y = N;
            
        }
        
        printf("%d\n", answer);
        
    }
    
    return 0;
}
