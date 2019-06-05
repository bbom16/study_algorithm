//
//  1244_samsung.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 23..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> max_value;
bool zero_chk;

/* 최댓값 찾기 */
void find_max_value(int cnt, string pan, int i){
    int s = 0;
    vector<int> max_indexs;
    
    if(cnt <= 0 || i >= pan.length()) return;
    int max_val = 0;
    for(int j=i+1; j<pan.length(); j++){
        if(max_val < pan[j] - '0'){
            max_val = pan[j] - '0';
        }
    }
    
    for(int j=i+1; j<pan.length(); j++){
        if(max_val == pan[j] - '0'){
            max_indexs.push_back(j);
        }
    }
    
    for(int k=0; k<max_indexs.size(); k++){
        if(k > 0){
            char tmp = pan[i];
            pan[i] = pan[max_indexs[k-1]];
            pan[max_indexs[k-1]] = tmp;
            cnt++;
        }
        char tmp = pan[i];
        pan[i] = pan[max_indexs[k]];
        pan[max_indexs[k]] = tmp;
        cnt--;
        if(cnt == 0) {
            max_value.push_back(atoi(pan.c_str()));
            zero_chk = true;
        }
        else if(cnt > 0){
            for(s=i+1; s<pan.length(); s++){
                find_max_value(cnt, pan, s);
            }
    }

        /* 경우를 다해도 주어진 cnt만큼 안된 경우 예외처리 */
        if(!zero_chk){
            if(cnt%2 == 0) { // 짝수이면 그냥 지금 값 넣기(어차피 더 바꿀값 없어서 했던거 다시 반복할 거라서)
                max_value.push_back(atoi(pan.c_str()));
                cnt = 0;
                return;
            }
            else{ //홀수이면 마지막 값만 바꿔서 넣기(적어도 한번은 더해야 하므로)
                int tmp = pan[s-1];
                pan[s-1] = pan[s-2];
                pan[s-2] = tmp;
                max_value.push_back(atoi(pan.c_str()));
                cnt = 0;
                return;
            }
        }
    }
}

int main(int argc, char * argv[]){
    
    int T;
    
  //  freopen("sample_input_1244.txt", "r", stdin);
    
    cin >> T;
    
    string numpan;
    int change_cnt,i,max_num = 0;
    
    for(int test_case=1; test_case<=T; test_case++){
        cin >> numpan >> change_cnt;
        
        /* 길이가 1이면 어차피 바껴도 자기 자신이라서 */
        if(numpan.length() == 1) max_num = atoi(numpan.c_str());
        
        else{
            for(i=0; i<numpan.length()-1; i++){
                find_max_value(change_cnt, numpan,i);
                zero_chk = false;
            }
            
            for(i=0; i<max_value.size(); i++){
                if(max_num < max_value[i]) max_num = max_value[i];
            }
        }
        
        cout << '#' << test_case << " " << max_num << endl;
        max_value.clear();
        max_num = 0;
        
    }
    return 0;
}
