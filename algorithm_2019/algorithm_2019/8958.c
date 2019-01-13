//
//  8958.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  OX퀴즈 점수 구하기, 연속으로 맞히면 연속된 O의 개수만큼의 점수를 획득함.

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int T,score = 0, continuity = 0;
    scanf("%d", &T);
    
    char str[80] = " ";
    while(T--){
        scanf("%s", str);      //공백까지 포함하여 문자열 받기
        
        for(int i=0; i<strlen(str); i++){
            if(str[i] == 'O'){
                continuity++;
                score += continuity;
            }
            else continuity = 0;
        }
        printf("%d\n", score);
        score = 0; continuity = 0; str[0] = '\0';      //모든 값 초기화
    }
    
    
    return 0;
}
