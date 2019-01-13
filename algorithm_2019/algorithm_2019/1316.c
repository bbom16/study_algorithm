//
//  1316.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 8..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  그룹 단어 체크, 연속된 단어들로만 이루어져야 그룹 단어, abcd, aaabbb -> 그룹단어, aaba -> 그룹단어x

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char word[100] = " ";
    int repeat[26] = {0,};
    int N, chk_end;
    int group_word = 0;
    
    scanf("%d", &N);
    
    char before;
    
    while(N--){
        scanf("%s", word);
        before = word[0];
        repeat[word[0]-'a'] = 1;

        chk_end = 0;
        /* 중복 체크 */
        for(int i=1; i<strlen(word); i++){
            if(repeat[word[i]-'a'] == 0)
                repeat[word[i]-'a'] = 1;
    
            else if(before != word[i] && repeat[word[i]-'a'] > 0)
                break;
            
            before = word[i];
            chk_end = i;
        }
        
        if(chk_end == strlen(word)-1) group_word++;
        
        word[0] = '\0';
        for(int i=0; i<26; i++)
            repeat[i] = 0;
    }
    
    printf("%d\n", group_word);
    
    return 0;
}
