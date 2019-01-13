//
//  9498.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>

int main(int argc, char * argv[])
{
    int score;
    scanf("%d", &score);
    
    score /= 10;
    switch (score) {
        case 10:
        case 9 :
            printf("A\n");
            break;
        case 8 :
            printf("B\n");
            break;
        case 7 :
            printf("C\n");
            break;
        case 6 :
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
    }
    return 0;
}
