//
//  4673.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  실제로 d(n) 수 구해보고 셀프넘버 찾기

#include <stdio.h>
int num_arr[10001];
/* d(n) 숫자 계산하는 함수 */
void find_number()
{
    int cal_num = 0;    //d(n)계산 값
    int num = 0;        //생산자
    for(int i=1; i<10001; i++){
        cal_num = i;
        num = i;
        while(num !=0){
            cal_num += num % 10;
            num /= 10;
        }
        num_arr[cal_num] = 1;
    }
}

int main(int argc, char * argv[])
{
    find_number();
    
    /* 0이면 셀프넘버 */
    for(int i=1; i<10001; i++){
        if(num_arr[i] == 0)
            printf("%d\n", i);
    }
    
    return 0;
}
