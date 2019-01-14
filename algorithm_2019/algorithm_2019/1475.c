//
//  1475.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 14..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  방 번호, 필요한 숫자 세트 구하기. 6하고 9는 혼용 가능.

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char room_num[7];   //입력받을 방번호
    int chk_num[9] = {1,1,1,1,1,1,2,1,1};    //숫자들 개수 저장 배열
    int ans = 1;       //답, 필요한 세트 수
    
    scanf("%s", room_num);
    
    int room_num_digit = strlen(room_num);  //방 자리수
    
    for(int i=0; i<room_num_digit; i++){
        int now_num = room_num[i] - '0';
        if(now_num == 9) now_num = 6;
        
        while(1){
            if(chk_num[now_num] > 0){
                chk_num[now_num]--;
                break;
            }
            else{                   //카드 없으면 세트 추가
                for(int j=0; j<9; j++){
                    if(j==6) chk_num[j]++;
                    chk_num[j]++;
                }
                ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
