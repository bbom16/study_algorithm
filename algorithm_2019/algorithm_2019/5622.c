//
//  5622.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 8..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  다이얼, 단어를 숫자로 변환하여 그 전화번호를 거는데 걸리는 시간 계산

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char word[16];
    scanf("%s", word);
    
    int num = 0;
    int time = 0;
    for(int i=0; i<strlen(word); i++){
        switch (word[i]) {
            case 'A':
            case 'B':
            case 'C':
                num = 2;
                break;
            case 'D':
            case 'E':
            case 'F':
                num = 3;
                break;
            case 'G':
            case 'H':
            case 'I':
                num = 4;
                break;
            case 'J':
            case 'K':
            case 'L':
                num = 5;
                break;
            case 'M':
            case 'N':
            case 'O':
                num = 6;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                num = 7;
                break;
            case 'T':
            case 'U':
            case 'V':
                num = 8;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                num = 9;
                break;
            default:
                break;
        }
        time += num+1;
    }
    
    printf("%d\n", time);
    
    return 0;
}
