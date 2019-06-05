//
//  1003.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 26..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

/* 시간 초과,,
 int cnt_zero, int cnt_one;
void fibo(int N){
    if(N == 0){
        cnt_zero++;
        return;
    }
    else if(N == 1){
        cnt_one++;
        return;
    }
    else{
        fibo(N-1);
        fibo(N-2);
    }
}
*/
int main(int argc, char * argv[]){
    
    std::ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    int z_dp[41] = {1,0, };
    int o_dp[41] = {0,1, };
    
    while(T--){
        int N;
        cin >> N;
        
        for(int i=2; i<=N; i++){
            z_dp[i] = z_dp[i-1] + z_dp[i-2];
            o_dp[i] = o_dp[i-1] + o_dp[i-2];
        }
        
        cout << z_dp[N] << " " << o_dp[N] << endl;
    
    }
    
    return 0;
}
