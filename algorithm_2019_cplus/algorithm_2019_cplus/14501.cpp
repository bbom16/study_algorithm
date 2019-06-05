//
//  14501.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 30..
//  Copyright © 2019년 bomin jung. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char * argv[]){
    std::ios_base::sync_with_stdio(false);
    
    int n, time, money;
    cin >> n;
    
    vector<pair<int, int> > schedule;
    for(int i=0; i<n; i++){
        cin >> time >> money;
        
        schedule.push_back(make_pair(time, money));
    }
    
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(schedule[i].first + i > n) continue;
        int max_val = schedule[i].second;
        for(int j=1; j<=i; j++){
            if(schedule[i-j].first + (i-j) <= i){
                int val = schedule[i-j].second + schedule[i].second;
                if(val > max_val) max_val = val;
            }
        }
        schedule[i].second = max_val;
        if(answer < schedule[i].second) answer = schedule[i].second;
    }
    
    cout << answer << endl;
    return 0;
}
