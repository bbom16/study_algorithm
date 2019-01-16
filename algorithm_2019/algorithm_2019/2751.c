//
//  2751.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 15..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  정렬, merge와 heap sort 구현

#include <stdio.h>
#include <stdlib.h>

int N;
int num[1000001];
int sorted[1000001];

void Merge_sort(int left, int right);
void merge(int left, int mid, int right);

int main(int argc, char * argv[])
{
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &num[i]);
    
    Merge_sort(0, N-1);
    
    for(int i=0; i<N; i++){
        printf("%d\n", num[i]);
    }
    
    return 0;
}
/* conquer & merge */
void merge(int left, int mid, int right)
{
    int i,j,k;
    i = left;   //첫번째 리스트 0
    j = mid+1;  //2번째 리스트 0
    k = left;  //sorted 배열 index
    
    /* sorted 배열로 저장 */
    while(1){
        if(num[i]<= num[j]) sorted[k++] = num[i++];
        else sorted[k++] = num[j++];
        if(i == mid + 1){
            for(int s=j; s<right+1; s++)
                sorted[k++] = num[s];
            break;
        }
        else if(j == right + 1){
            for(int s=i; s<mid+1; s++)
                sorted[k++] = num[s];
            break;
        }
    }
    
    /* sorted 배열에 저장한 값 다시 num 배열로 저장 */
    for(i=left; i<right+1; i++)
        num[i] = sorted[i];
}

/* divide 과정 */
void Merge_sort(int left, int right)
{
    int mid;
    if(left<right){
        mid = (left + right)/2;
        Merge_sort(left, mid);
        Merge_sort(mid+1, right);
        merge(left, mid, right);
    }
}
