//
//  8393.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    
    /* 1~n까지 더하기 */
    for(int i=1; i<n+1; i++)
        ans += i;
    
    printf("%d\n", ans);
    
    return 0;
}
