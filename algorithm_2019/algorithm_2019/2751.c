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

/* merge sort */
void Merge_sort(int left, int right);
void merge(int left, int mid, int right);

/* heap sort */
void insert_heap(int n);
int delete_heap(int n);

void swap(int* a, int* b);

int main(int argc, char * argv[])
{
    scanf("%d", &N);
    
    /* merge sort
     for(int i=0; i<N; i++){
     scanf("%d", &num[i]);
     }
     Merge_sort(0, N-1);
     for(int i=0; i<N; i++){
     printf("%d\n", num[i]);
     }
     */
    
    /* heap sort */
    for(int i=1; i<N+1; i++){
        scanf("%d", &num[i]);
        insert_heap(i);
    }
    
    int ans;
    for(int i=0; i<N; i++){
        ans = delete_heap(N-i);
        printf("%d\n", ans);
    }
    
    return 0;
}

/* swap 함수 */
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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

/* heap 삽입 연산 */
void insert_heap(int n)
{
    int i = n;
    while(1){
        if(i == 1) break;
        /* 부모랑 비교해서 부모보다 내가 더 작으면 swap */
        else if(num[i/2] > num[i]) {
            swap(&num[i/2], &num[i]);
            i /= 2;
        }
        else break;
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
