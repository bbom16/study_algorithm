//
//  1157.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  제일 많이 사용된 단어 출력하기

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char word[1000001] = " ";
    int alphabet[26] = {0,};
    
    scanf("%s", word);
    
    unsigned long int word_len = strlen(word);
    
    for(int i=0; i<word_len; i++){
        if(word[i] >= 65 && word[i] <= 90) alphabet[word[i]-'A']++;
        else if(word[i] >= 97 && word[i] <= 122) alphabet[word[i]-'a']++;
    }
    int max = 0, max_index = 0;
    
    for(int i=0; i<26; i++){
        if(max < alphabet[i]) {
            max = alphabet[i];
            max_index = i;
        }
        else if(max !=0 && max == alphabet[i]) {
            max_index = -2;
        }
    }
    
    printf("%c\n", 'A'+ max_index);
    return 0;
}
