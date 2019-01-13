//
//  11718.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 3..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    char input[101] = " ";
   
    while(fgets(input,sizeof(input), stdin)){

        fputs(input, stdout);
    }
    
    return 0;
}
