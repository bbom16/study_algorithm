//
//  1011.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 12..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  fly me to the alpha centauri, k번 이동했을 때 그 다음은 k-1, k, k+1 만큼만 이동가능. 중요한 건 현재위치와 목표위치의 차이!!
//  이동 횟수 2개 당 개수가 하나씩 증가함 예) 2개, 이동횟수 1일 때 1개, 2일 때 1개, 3일 때 2개, 4일 때 2개 이런식으로 증가함. 이 규칙 이용해서 문제 해결

#include <stdio.h>

int main(int argc, char * argv[])
{
    int T, x, y; // 테스트케이스, 현재위치, 목표위치
    scanf("%d", &T);  // long long int 서식문자 %lld
    
    long long int diff = 0, sum = 0;       //diff는 목표위치 - 현재위치, sum은 diff와 같은 값을 찾아내기 위한 비교 변수
    int answer = 1;    //답
    
    while(T--){
        scanf("%d %d", &x, &y);
        diff = y - x;
        while(1){
            sum += (answer+1)/2;
            if(diff <= sum) break;
            answer++;
        }
        printf("%d\n", answer);
        /* 변수 초기화 */
        diff = 0; sum = 0; answer = 1;
    }
    return 0;
}
