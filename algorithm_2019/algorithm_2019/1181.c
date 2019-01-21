//
//  1181.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 21..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  단어정렬, 주어진 단어를 길이가 짧은 순으로 정렬, 길이가 같으면 사전 순으로 정렬한다.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct word_LENGTH{
    int index;
    unsigned long int length;
}LENGTH;

LENGTH sorted[20000];
char words[20000][51];  //단어 저장 배열

/* swap 함수 */
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* conquer & merge */
void merge(LENGTH * arr, int left, int mid, int right)
{
    int i,j,k;
    i = left;   //첫번째 리스트 0
    j = mid+1;  //2번째 리스트 0
    k = left;  //sorted 배열 index
    
    /* sorted 배열로 저장 */
    while(1){
        if(arr[i].length < arr[j].length) sorted[k++] = arr[i++];
        /* 길이가 같으면 사전순으로 배열 */
        else if(arr[i].length == arr[j].length){
            for(int s=0; s<arr[i].length; s++){
                if(words[arr[i].index][s] < words[arr[j].index][s]){
                    sorted[k++] = arr[i++];
                    break;
                }
                else if(words[arr[i].index][s] > words[arr[j].index][s]){
                    sorted[k++] = arr[j++];
                    break;
                }
            }
        }
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
void Merge_sort(LENGTH * arr, int left, int right)
{
    int mid;
    if(left<right){
        mid = (left + right)/2;
        Merge_sort(arr, left, mid);
        Merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}


int main(int argc, char * argv[])
{
    int N,w_index=0;
    LENGTH word_len[20000];
    bool chk = false;
    scanf("%d", &N);
    
    /* 입력받을 때 중복 값 제거 */
    for(int i=0; i<N; i++){
        scanf("%s", words[w_index]);
        for(int j=0; j<w_index; j++){
            if(w_index != j && !strcmp(words[w_index], words[j])){
                w_index--;
                chk = true;
                break;
            }
        }
        if(!chk)
            word_len[w_index] = (LENGTH){w_index,strlen(words[w_index])};
        chk = false;
        w_index++;
    }
    Merge_sort(word_len, 0, w_index-1); //단어 길이 순으로 정렬.
    
    for(int i=0; i<w_index; i++)
        printf("%s\n", words[word_len[i].index]);
    
    return 0;
}
