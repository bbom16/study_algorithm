//2020.02.04
//boj 14501
//��� 
//dp
//dp�� ���� ������ �� �𸣰ڴ�. ���ΰ� �� �ʿ���.(��α� �����ؼ� ���� �ذ�)


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
		dp[i + 1] = max(dp[i + 1], dp[i]); //i�Ͽ� �ٹ��� �������� ���
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]); //i�Ͽ� �ٹ��� �� ��� (dp[i+t[i]]�� i�� �ٹ��� ���� �� ����)
	}
	
	printf("%d\n", dp[N]);
	return 0;
}