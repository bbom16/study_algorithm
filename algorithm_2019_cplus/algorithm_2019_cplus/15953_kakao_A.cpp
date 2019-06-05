//
//  15953_kakao_A.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 3. 11..
//  Copyright © 2019년 bomin jung. All rights reserved.
// 카카오2018 예선

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int T,a,b;
    int reward_2017[6] = {500, 300, 200, 50, 30, 10};
    int reward_2018[5] = {512, 256, 128, 64, 32};
    cin >> T;
    
    int level = 1, answer = 0, i = 1;
    while(T--){
        cin >> a >> b;
        while(a > level){
            if(a > 21) break;
            level += ++i;
        }
        if(a == 0 || a > 21) answer = 0;
        else answer = reward_2017[i-1];
        i = 1; level = 1;
        int index = 0;
        while(b > level){
            if(b > 31) break;
            i *= 2;
            level += i;
            index++;
        }
        if(b == 0 || b > 31) answer += 0;
        else answer += reward_2018[index];
        cout << answer*10000 << endl;
        answer = 0; i=1; level=1;
    }
    
    
    
    return 0;
}
