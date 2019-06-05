//
//  15954_kakao_B.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 3. 11..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  카카오 예선

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char * argv[])
{
    int N,K,i;
    long double dolls[501];
    
    cin >> N >> K;
    for(i=1; i<N+1; i++)
        cin >> dolls[i];
    
    /* 최댓값을 더 키웠어야 햇음 */
    long double min_diff = 999999999999;
    long double averge = 0, vunsan = 0;
    while(K<=N){
        for(i=1; i<=N-K+1; i++){
            for(int j=0; j<K; j++){
                averge += dolls[i+j];
            }
            averge /= K;
            for(int j=0; j<K; j++){
                vunsan += pow(dolls[i+j]-averge,2);
            }
            vunsan /= K;
            
            if(min_diff > vunsan)
                min_diff = vunsan;
            averge = 0; vunsan = 0;
        }
        K++;
    }
    /* 자릿수 소수점 아래 8까지 설정 */
    cout << fixed;
    cout.precision(11);
    cout << sqrt(min_diff) << endl;
    return 0;
}
