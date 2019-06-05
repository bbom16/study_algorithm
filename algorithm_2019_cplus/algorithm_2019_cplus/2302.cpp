//
//  2302.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 28..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N >> M;
    
    int vip, dp[41] = {1,1};
    int i, answer = 1;
    
    /*vip이면 -1로 만들기 */
    for(i=0; i<M; i++){
        cin >> vip;
        dp[vip] = -1;
    }
    if(M == N) answer = 1;
    
    else{
        /* dp로 i번째 자리까지 오면 경우의 수 구하기 dp[i] = dp[i-1] + dp[i-2] */
        for(i=2; i<N+1; i++){
            if(dp[i] == -1) continue;
            
            if(dp[i-1] == -1) dp[i] = 1;
            else if(dp[i-2] == -1) dp[i] = dp[i-1]*2;
            else dp[i] = dp[i-1] + dp[i-2];
            
            if(i==N) answer *= dp[N];
            else if(dp[i+1] == -1)  answer *= dp[i];
            
        }
    }
    cout << answer << endl;
    return 0;
}
