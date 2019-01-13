//
//  15552.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    int T,A,B;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }
    return 0;
}
