//
//  1546.c
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

    int max_score = 0;
    double score = 0;
    double average = 0;
    
    for(int i=0; i<N; i++){
        scanf("%lf",&score);
        average += score;
        if(max_score < score)
            max_score = score;
    }
    
    average /= max_score * N;
    average *= 100;
    
    printf("%lf\n", average);
    return 0;
}
