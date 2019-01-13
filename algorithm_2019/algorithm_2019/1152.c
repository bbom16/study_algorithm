//
//  1152.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  단어 개수 

#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[])
{
    char sentence[1000001];
    int num = 1;
    fgets(sentence, sizeof(sentence), stdin);
    
    for(int i=1; i<strlen(sentence); i++){
        if(sentence[0] == '\n' || (sentence[0] == ' ' && sentence[1] == '\n')){
            num = 0;
            break;
        }
        if(sentence[i] == ' ' && sentence[i-1] != ' ' && sentence[i+1] != '\n')
            num++;
    }
    
    
    printf("%d\n", num);
    
    
    return 0;
}
