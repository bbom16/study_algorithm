//
//  2439.c
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
    
    for(int i=1; i<N+1; i++){
        for(int j=0; j<N; j++){
            if(j < N-i) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}
