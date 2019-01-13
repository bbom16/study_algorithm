//
//  4344.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int C;
    scanf("%d", &C);
    
    int N;
    double average, correct;
    while(C--)
    {
        average = 0;
        correct = 0;
        scanf("%d", &N);
        int * stu_arr = malloc(sizeof(int) * N);
        
        for(int i=0; i<N; i++){
            scanf("%d", &stu_arr[i]);
            average += stu_arr[i];
        }
        average /= N;
        
        for(int i=0; i<N; i++){
            if(average < stu_arr[i])
                correct++;
        }
        
        printf("%.3lf%%\n", correct/N*100);
            
            
    }
    return 0;
}
