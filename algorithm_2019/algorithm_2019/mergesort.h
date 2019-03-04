//
//  mergesort.h
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 28..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#ifndef mergesort_h
#define mergesort_h


#include <stdio.h>
#include <stdlib.h>

int num[1000001];
int sorted[1000001];

/* 내림차순 으로 정렬 */

/* swap 함수 */
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* conquer & merge */
void merge(int * arr, int left, int mid, int right)
{
    int i,j,k;
    i = left;   //첫번째 리스트 0
    j = mid+1;  //2번째 리스트 0
    k = left;  //sorted 배열 index
    
    /* sorted 배열로 저장 */
    while(1){
        if(arr[i]>= arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
        if(i == mid + 1){
            for(int s=j; s<right+1; s++)
                sorted[k++] = arr[s];
            break;
        }
        else if(j == right + 1){
            for(int s=i; s<mid+1; s++)
                sorted[k++] = arr[s];
            break;
        }
    }
    
    /* sorted 배열에 저장한 값 다시 num 배열로 저장 */
    for(i=left; i<right+1; i++)
        arr[i] = sorted[i];
}

/* divide 과정 */
void Merge_sort(int * arr, int left, int right)
{
    int mid;
    if(left<right){
        mid = (left + right)/2;
        Merge_sort(arr, left, mid);
        Merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

/* heap 삭제 연산 */
int delete_heap(int n)
{
    int min_val = num[1];
    num[1] = num[n];    //마지막을 제일 상위노드에 위치
    int i = 1;
    int * min_child;    //두 자식 중 더 작은 자식
    
    /* heap 재배열 */
    while(1){
        if(2*i > n) break;
        if(2*i == n || (num[2*i] <= num[2*i+1])) min_child = &num[2*i];
        else min_child = &num[2*i+1];
        
        if(num[i] > *min_child) {
            swap(&num[i], min_child);
            i = (int)(min_child - &num[0]); //현재 index값 계산
        }
        else break;
    }
    return min_val;
}


#endif /* mergesort_h */

