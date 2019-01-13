//
//  10250.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 12..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  ACM 호텔, 먼저 온 사람한테 낮은 층수부터 1,2,3,... 이런식으로 방을 배정하여 N번째 들어오는 사람의 방번호를 찾자

#include <stdio.h>

int main(int argc, char * argv[])
{
    int T, W, H, N; // 테스트 수, 방개수, 층 수, 손님의 순서
    
    scanf("%d", &T);
    
    int one_digit = 0; // 방번호 뒤의 두자리
    int height = 0; // 층 수
    int room_num = 0;   // 총 방번호

    while(T--){
        scanf("%d %d %d", &H, &W, &N);
        
        one_digit = N/H;
        height = N - one_digit*H;
        one_digit++;
        
        if(N%H == 0)    // 나머지 없이 떨어질 때 예외처리
        {
            one_digit--;
            height = H;
        }
        room_num += height*100 + one_digit;
        
        printf("%d\n", room_num);
        one_digit = 0;
        height = 0;
        room_num = 0;

    }
    return 0;
}
