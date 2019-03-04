//
//  1966.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 28..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  시간초과, 내일 마저 이유 찾기 + priority queue heap으로 구현해보기

#include <stdio.h>
#include <stdlib.h>
/*------ merge sort---------- */

int sorted[101];

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

/* ------------------------- */
typedef struct note{
    int index;
    int importance;
}NOTE;

typedef struct queue{
    NOTE num[101];
    int front;
    int back;
    int size;
}Queue;

void push(Queue * que, NOTE note)
{
    que->num[que->back++] = note;
    que->size++;
    /* 범위 유지 */
    if(que->back > 100)
        que->back %= 100;
}
int empty(Queue * que)
{
    if(que->size == 0)
        return 1;
    else
        return 0;
}

NOTE pop(Queue * que)
{
    NOTE front = que->num[que->front];
    if(empty(que))
        return (NOTE){-1,-1};
    else{
        que->front++;
        /* 범위 유지 */
        if(que->front > 100)
            que->front %= 100;
        que->size--;

        /* que가 비면 index 다시 0부터 시작하도록 */
        if(empty(que)){
            que->front = 0;
            que->back = 0;
        }
        return front;
    }
}

Queue que;

int main(int argc, char * argv[])
{
    int T,N,M,i,now_import,j=0,answer=0;  //N : 문서의 개수, M : 몇번째로 출력되는지 궁금한 문서의 현재 위치
    int import_arr[101];
    NOTE now_note;
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(i=0; i<N; i++){
            scanf("%d", &import_arr[i]);
            push(&que,(NOTE){i,import_arr[i]});
        }
        
        Merge_sort(import_arr, 0, N-1);
        now_import = import_arr[j++];
        while(1){
            now_note = pop(&que);
            if(now_note.importance < now_import)
                push(&que, now_note);
            else{
                answer++;
                if(now_note.index == M){
                    printf("%d\n", answer);
                    break;
                }
                now_import = import_arr[j++];
            }
            /* 무한루프 방지 */
            if(j > N)
                break;
            
        }
        /* 초기화 */
        for(i=0; i<101; i++){
            import_arr[i] = 0;
            sorted[i] = 0;
        }
        j=0; answer=0;
        while(!empty(&que))
            pop(&que);
    }
    
    return 0;
}
