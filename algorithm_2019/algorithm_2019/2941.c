//
//  2941.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 8..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  크로아티아 알파벳

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char word[101] = " ";
    scanf("%s",word);
    
    int cro_num = 0;
    int word_len = strlen(word);
    
    for(int i=0; i<word_len; i++){
        if(word[i] == '=' || word[i] == '-')
            continue;
        if(i>0 && i < word_len && word[i] == 'z' && word[i-1] == 'd' && word[i+1] == '=')
            continue;
        if(i>0 && i < word_len && word[i] == 'j' && (word[i-1] == 'n' || word[i-1] == 'l'))
           continue;
        else cro_num++;
    }
    
    printf("%d\n", cro_num);
    
    return 0;
}
