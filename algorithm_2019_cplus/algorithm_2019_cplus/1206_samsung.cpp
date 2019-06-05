//
//  1206_samsung.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 21..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char * argv[]){
    
    int T = 10;
   
   // freopen("sample_input_1206.txt", "r", stdin);

    int i, H, answer = 0;
    int input[1001];
    
    for(int test_case=1; test_case <= T; test_case++){
        cin >> H;
        for(i=0; i<H; i++){
            cin >> input[i];
        }
        
        int view_ok[4];
        int s = 0, min_ok = 256;
        
        for(i=2; i<H-2; i++){
            for(int j=1; j<=2; j++){
                if(input[i] > input[i-j]){
                    view_ok[s++] = input[i] - input[i-j];
                }
                else view_ok[s++] = 0;
                
                if(input[i] > input[i+j]){
                    view_ok[s++] = input[i] - input[i+j];
                }
                else view_ok[s++] = 0;
                
                
            }
            for(int j=0; j<4; j++){
                if(view_ok[j] == 0) {
                    min_ok = 0;
                    break;
                }
                else{
                    if(view_ok[j] < min_ok) min_ok = view_ok[j];
                }
            }
            answer += min_ok;
            s = 0;
            min_ok = 256;
            
        }
        
        cout << '#' << test_case << " " << answer << endl;
        answer = 0;
        
    }
    return 0;
}
