//
//  2920.c
//  algorithm_2019
//
//  Created by bomin jung on 2019. 1. 7..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  음계 1~8, 8~1, 둘다 아닌지 판별

#include <stdio.h>

int main(int argc, char * argv[]){
    
    int sing[8];
    int state = 2;  //0:ascending, 1:descending, 2:mixed
    for(int i=0; i<8; i++)
        scanf("%d",&sing[i]);
    
    if(sing[0] == 1)
        state = 0;
    else if(sing[0] == 8)
        state = 1;
    
    int before = sing[0];

    for(int i=1; i<8; i++){
        
       if(state == 0 && sing[i]-before == 1)
           state = 0;
        else if(state == 1 && sing[i]-before == -1)
            state = 1;
        else {
            state = 2;
            break;
        }
        
        before = sing[i];
    }
    
    switch (state) {
        case 0:
            printf("ascending\n");
            break;
        case 1:
            printf("descending\n");
            break;
        case 2:
            printf("mixed\n");
        default:
            break;
    }
    
    return 0;
}
