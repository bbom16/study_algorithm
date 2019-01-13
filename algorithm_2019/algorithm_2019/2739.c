//
//  2739.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    int N;
    scanf("%d", &N);
    
    for(int i=1; i<10; i++)
        printf("%d * %d = %d\n",N,i,N*i);
    
    
    return 0;
}
