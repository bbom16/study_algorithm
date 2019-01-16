//
//  2750.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 15..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  수 정렬하기, insert sort, bubble sort 구현하자

#include <stdio.h>

void swap(int* a, int* b);
void Insert_Sort();
void Bubble_Sort();

int N;
int num[1001] = {0,};

int main(int argc, char * argv[])
{
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &num[i]);
    
    Insert_Sort();
    //Bubble_Sort();
    
    for(int i=0; i<N; i++){
        printf("%d\n", num[i]);
    }
    
    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Bubble_Sort()
{
    for(int i=1; i<N; i++){
        for(int j=i-1; j>=0; j--){
            if(num[i] < num[j]) {
                swap(&num[i], &num[j]);
                i = j;
            }
            else break;
        }
    }
}

void Insert_Sort()
{
    int i,j;
    for(i=1; i<N; i++){
        int key = num[i];
        for(j=i-1; j>=0; j--){
            if(key < num[j]){
                num[j+1] = num[j];
            }
            else break;
        }
        num[j+1] = key;
    }
}
