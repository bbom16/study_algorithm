//
//  5656_samsung.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 5. 14..
//  Copyright © 2019년 bomin jung. All rights reserved
//
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

int N,W,H, whole_brick;
vector<int> max_cnt;

void arrange(vector<vector<int> > &brick){
    int first_zero = -1;
    
    for(int j=0; j<W; j++){
        for(int i=H; i>0; i--){
            if(first_zero == -1 && brick[i][j] == 0) first_zero = i;
            else if(first_zero != -1 && brick[i][j]){
                int tmp = brick[first_zero][j];
                brick[first_zero][j] = brick[i][j];
                brick[i][j] = tmp;
                first_zero--;
            }
        }
        first_zero = -1;
    }
}

int smash(vector<vector<int> > &brick, int i, int j){
    int val = brick[i][j];
    int break_cnt = 1;
    brick[i][j] = 0;
    for(int k=1; k<val; k++){
        if(i+k <= H) {
            if(brick[i+k][j]) {
                break_cnt += smash(brick, i+k, j);
            }
        }
        if(i-k >= 0){
            if(brick[i-k][j]) {
                break_cnt += smash(brick, i-k, j);
            }
        }
        if(j+k < W){
            if(brick[i][j+k]){
                break_cnt += smash(brick, i, j+k);
            }
        }
        
        if(j-k >=0) {
            if(brick[i][j-k]) {
                break_cnt += smash(brick, i, j-k);
            }
        }
    }
    return break_cnt;
}

void break_brick(vector<vector<int> > brick, int cnt, int break_cnt, int pj){
    int i;
    if(pj == W) return;
    for(i=0; i<H+1; i++){
        if(brick[i][pj]){
            break_cnt += smash(brick, i, pj);
            arrange(brick);
            cnt--;
            if(!cnt) max_cnt.push_back(break_cnt);
            break;
        }
        if(i == H) return;    //j줄에 벽돌이 없는 경우
    }
    /* 전체 삭제된 경우 */
    if(break_cnt == whole_brick){
        max_cnt.push_back(break_cnt);
        return;
    }
    
    for(int j=0; j<W; j++){
        if(cnt != 0) break_brick(brick,cnt,break_cnt,j);
        else break;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
     아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
     //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
     freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
     따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
     freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
     단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
     */
     freopen("sample_input_5656.txt", "r", stdin);
    cin >> T;
    /*
     여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
     */
    vector<vector<int> > input;  // int input[16][12]; //W = 12, H = 15, input[H][W]
    int i,j;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> W >> H;
        
        input.resize(H+1);
        for(i=0; i<=H; i++){
            input[i].resize(W);
        }
        
        for(i=1; i<H+1; i++){
            for(j=0; j<W; j++){
                cin >> input[i][j];
                if(input[i][j] > 0) whole_brick++;
            }
        }
        int max_value = 0;
        for(j=0; j<W; j++){
            break_brick(input,N,0,j);
            for(i=0; i<max_cnt.size(); i++){
                if(max_value < max_cnt[i]) max_value = max_cnt[i];
            }
            max_cnt.clear();
        }
        
        cout << '#' << test_case << " " << whole_brick - max_value << endl;
        
        max_cnt.clear();
        whole_brick = 0;
        max_value = 0;
        input.clear();
    }
    
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
