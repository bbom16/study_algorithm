//
//  1924.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//
// 2007년, 전부 1월로 바꿔준 다음 요일 계산

#include <stdio.h>

int main(int argc, char * argv[])
{
    int month, day;
    scanf("%d %d", &month, &day);
    
    int month_arr[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30}; //11월까지 일수 저장 배열
    char * week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; //요일 저장
    int convert_day = day; //1월로 변경한 날짜 저장.
    int week_val = 0;
    
    for(int i = 1; i<month; i++)
        convert_day += month_arr[i-1];
    if(convert_day-1 == 0)
        week_val = 0;
    else week_val = (convert_day-1) % 7;
    printf("%s\n",week[week_val]);
        
    return 0;
}
