//
//  10430.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 3..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    int A,B,C;
    
    scanf("%d %d %d", &A,&B,&C);
    printf("%d\n", (A+B)%C);
    printf("%d\n", (A%C + B%C)%C);
    printf("%d\n", (A*B)%C);
    printf("%d\n", (A%C*B%C)%C);
    
    return 0;
}
