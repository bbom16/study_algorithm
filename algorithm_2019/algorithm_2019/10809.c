//
//  10809.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  단어에 포함된 알파벳 처음 위치 찾기, 없으면 -1

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char S[100] = " ";
    int alphabet[26];
    for(int i=0; i<26; i++)
        alphabet[i] = -1;
    
    scanf("%s", S);
    
    for(int i=0; i<strlen(S); i++)
        if(alphabet[S[i]-'a'] == -1)
            alphabet[S[i]-'a'] = i;

    for(int i=0; i<26; i++)
        printf("%d ", alphabet[i]);
    printf("\n");
    
    return 0;
}
