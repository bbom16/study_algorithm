//
//  1463.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 30..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

#define INFINITE_VALUE 999999

int main(int argc, char * argv[]){
    std::ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    int * number = new int[N+1]; //배열 동적할당
    
    number[0] = 0; number[1] = 0;
    int min_val;
    int val[3];
    for(int i=2; i<N+1; i++){
        /* 값 초기화 */
        for(int j=0; j<3; j++) val[j] = INFINITE_VALUE;
        min_val = INFINITE_VALUE;
        
        if(i%3 == 0) val[0] =  number[i/3] + 1;
        if(i%2 == 0) val[1] = number[i/2] + 1;
        val[2] = number[i-1] + 1;
        /* 최솟값 구하기 */
        for(int j=0; j<3; j++){
            if(min_val > val[j]) min_val = val[j];
        }
        number[i] = min_val;
    }
    cout << number[N] << endl;
    
    return 0;
}
