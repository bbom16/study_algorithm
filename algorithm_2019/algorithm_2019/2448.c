
//  2448.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  별찍기,,, 화려하다 -> 결국 혼자서는 못하고 검색함
//  삼각형을 원래 삼각형, 새로 추가되는 왼쪽과 오른쪽 삼각형으로 나누어 생각한 후 그 삼각형들의 꼭짓점 위치를 재귀적으로 넘겨줌.
//  새로웠던 부분은 배열을 이용한다는 점이었다. 전혀 생각하지 못했던 부분이었음.

#include <stdio.h>

void star_top(int n, int x, int y);

char star[3072][6144];


int main(int argc, char * argv[])
{
    int N;
    scanf("%d", &N);
    
    /* 배열 초기화, 각 높이와 행을 공백으로 초기화하고 행의 끝부분만 널처리한다. */
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++)
            star[i][j] = ' ';
        
    }
    star_top(N, N-1, 0);
    
    /* 삼각형 출력 */
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            printf("%c",star[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void star_top(int n, int x, int y)
{
    if(n == 3){
        /* 가장 작은 삼각형 */
        star[y][x] = '*';
        star[y+1][x-1] = '*';
        star[y+1][x+1] = '*';
        star[y+2][x-2] = '*';
        star[y+2][x-1] = '*';
        star[y+2][x] = '*';
        star[y+2][x+1] = '*';
        star[y+2][x+2] = '*';
        return;
    }
    star_top(n/2, x, y); //가장 위 삼각형
    star_top(n/2, x-(n/2), y+(n/2));    //왼쪽 하단 삼각형
    star_top(n/2, x+(n/2), y+(n/2));    //오른쪽 하단 삼각형
    
}

