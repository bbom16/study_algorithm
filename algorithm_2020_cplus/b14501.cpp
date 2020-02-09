//2020.02.04
//boj 14501
//퇴사 
//dp
//dp는 정말 아직도 잘 모르겠다. 공부가 더 필요함.(블로그 참조해서 문제 해결)


#define MAX_DAY	16
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int t[MAX_DAY]; //t[i]
int p[MAX_DAY]; //p[i]
int dp[MAX_DAY]; 

int main(int argc, char * argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
	
	for (int i = 0; i < N; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]); //i일에 근무를 하지않은 경우
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]); //i일에 근무를 한 경우 (dp[i+t[i]]에 i일 근무한 경우로 값 저장)
	}
	
	printf("%d\n", dp[N]);
	return 0;
}