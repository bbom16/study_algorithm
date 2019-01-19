//
//  1427.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 18..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  소트인사이드

#include <stdio.h>

int N, num_ind;
int num[10];
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Insert_Sort()
{
    int i,j;
    for(i=0; i<num_ind; i++){
        int key = num[i];
        for(j=i-1; j>=0; j--){
            if(key > num[j]){
                num[j+1] = num[j];
            }
            else break;
        }
        num[j+1] = key;
    }
}

int main(int argc, char * argv[])
{
    scanf("%d", &N);
    while(N > 0){
        num[num_ind++] = N % 10;
        N /= 10;
    }
    
    Insert_Sort();
    
    for(int i=0; i<num_ind; i++)
        printf("%d", num[i]);
    printf("\n");
    
    return 0;
}
