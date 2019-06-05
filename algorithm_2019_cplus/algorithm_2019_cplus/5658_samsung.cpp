//
//  5658_samsung.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 9..
//  Copyright © 2019년 bomin jung. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(int argc, char * argv[]){
    
    //freopen("input.txt", "r", stdin);
    
    int test_case;
    int T,N,K;
    
    cin >> T;
    
    string input;
    set<int> s;
    
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> K;
        cin >> input;
        
        /*char a;
         string test;*/
        int i,j,k,num=0,cnt=0, cycle_num = N/4;
        for(k=0; k<cycle_num; k++){
            for(i=(N-k)%N; cnt<4; i+=cycle_num){
                for(j=0; j<cycle_num; j++){
                    //a = input[(i+j)%N];
                    //test += a;
                    if(input[(i+j)%N] >= 48 && input[(i+j)%N] <= 57){
                        num += (input[(i+j)%N] - '0')*pow(16,cycle_num-1-j);
                        // int t1 = input[(i+j)%N] - '0';
                    }
                    else
                    num += (input[(i+j)%N] - 55)*pow(16,cycle_num-1-j);
                    // int t2 = input[(i+j)%N] - 55;
                }
                s.insert(num);
                num = 0;
                //test = " ";
                cnt++;
            }
            cnt = 0;
        }
        set<int>::iterator it = s.begin();
        for(i=0; i<s.size()-K; i++) it++;
        cout << '#' << test_case << " " << *it << endl;
        s.clear();
    }
    cout << endl;
    return 0;
}
