//
//  1193.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 10..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  분수찾기 -> n일 때 n개의 분수를 가지고 있음. n이면 분모 분자 더했을 때 n+1, 주어진 X가 어떤 n 위에 있는지 구해서 규칙 이용해서 해결.

#include <stdio.h>

int main(int argc, char * argv[])
{
    int X;
    scanf("%d", &X);
    
    int n = 2;
    int start = 2;  //n에 시작 숫자.
    int way = 0;    //0:세로 , 1: 가로
    int mom = 2, son = 1; //분모 분자
    
    /* X == 1 */
    if(X == 1){
        printf("%d\n",1/1);
        return 0;
    }
        
    while(1){
        if(X<=start){
            if(X==start) n++;
            else {
                start -= (n-1);
                /* 방향 바뀌주기 */
                if(way == 0) way = 1;
                else way = 0;
            }
            break;
        }
        start += n++;
        
        /* 방향 바뀌주기 */
        if(way == 0) way = 1;
        else way = 0;
    }
    
    if(way == 0){
        mom = n-1;
        son = 1;
        mom -= (X-start);
        son += (X-start);
    }
    else{
        son = n-1;
        mom = 1;
        son -= (X-start);
        mom += (X-start);
    }
    
    printf("%d/%d\n", son,mom);
    return 0;
}
