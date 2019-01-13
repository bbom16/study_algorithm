//
//  2675.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  단어 당 알파벳을 R번 반복해서 출력하기 

#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[])
{
    int T;
    scanf("%d", &T);
    
    int R;
    char word[20] = " ";
    
    while(T--)
    {
        scanf("%d %s",&R,word);
        
        for(int i=0; i<strlen(word); i++){
            for(int j=0; j<R; j++)
                printf("%c",word[i]);
        }
        printf("\n");
        word[0] = '\0';
    }
    
    return 0;
}
