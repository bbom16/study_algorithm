//
//  11721.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
int main(int argc, char * argv[])
{
    char word[100];
    scanf("%s", word);
    
    int i = 0;
    bool chk = false;
    while(1)
    {
        for(int j = i; j<i+10; j++){
            if(word[j] == '\0'){ //단어가 종료되면 break
                chk = true;
                break;
            }
            printf("%c", word[j]);
        }
        printf("\n");
        if(chk) break;
        i += 10;
        
    }
    return 0;
}
