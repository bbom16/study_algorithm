//
//  2108.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 19..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  통계학, 산술평균/중앙값/최빈값/범위 를 구하는 문제

#include <stdio.h>
#include <math.h>

int N;
int num[500001];        //입력값 저장
int sorted[500001];     //merge sort 시 사용
int mode_arr[500001];   //최빈값들 저장
typedef struct pair{
    int cnt;
    int num;
}PAIR;

PAIR repeat[8001];
/*swap 함수*/
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*conquer & merge*/
void merge(int * arr, int left, int mid, int right)
{
    int i,j,k;
    i = left;   //첫번째 리스트 0
    j = mid+1;  //2번째 리스트 0
    k = left;  //sorted 배열 index
    
    /*sorted 배열로 저장*/
    while(1){
        if(arr[i]<= arr[j]) sorted[k++] = arr[i++];
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
    
    /*sorted 배열에 저장한 값 다시 num 배열로 저장*/
    for(i=left; i<right+1; i++)
        arr[i] = sorted[i];
}

/*divide 과정*/
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


int main(int argc, char * argv[])
{
    /*산술평균*/
    double average = 0;
    /*최빈값*/
    int cnt, cnt_num, max_cnt; //중복된 숫자 개수와 중복된 숫자.
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
        average += num[i];
    }
    
    /*산술평균*/
    average /= N;
    average = round(average);
    printf("%d\n",(int)average);
    
    /*중앙값*/
    Merge_sort(num, 0, N-1);
    printf("%d\n", num[N/2]);
    
    /*숫자 나타나는 횟수 저장 & 최대 횟수 구하기*/
    int i = 1 , j = 0;
    cnt_num = num[0]; cnt = 1; max_cnt = 1;
    while(1){
        if(i == N) break;
        if(cnt_num == num[i]) cnt++;
        else{
            repeat[j++] = (PAIR){cnt, cnt_num};
            if(cnt > max_cnt) max_cnt = cnt;
            cnt = 1;
            cnt_num = num[i];
        }
        i++;
    }
    repeat[j++] = (PAIR){cnt, cnt_num};
    
    /*최빈값들 찾기*/
    int k = 0, mode = 0;
    for(i=0; i<j; i++){
        if(repeat[i].cnt == max_cnt)
            mode_arr[k++] = repeat[i].num;
    }
    if(k > 1){
        Merge_sort(mode_arr, 0, k-1);
        mode = mode_arr[1];
    }
    else mode = mode_arr[0];
    
    printf("%d\n", mode);
    
    /*범위*/
    int diff = num[N-1] - num[0];
    printf("%d\n", diff);
    
    return 0;
}
