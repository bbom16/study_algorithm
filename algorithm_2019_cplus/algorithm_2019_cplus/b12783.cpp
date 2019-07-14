// 2019.07.14
// boj 12783
// °ö¼À °ÔÀÓ
// Àç±Í,, µµÀü 

#define INF 999999
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> cards;
vector<int> dp;
int findMinCard(int num) {
	//°ö¼À Ä«µå ¾È¾²´Â °æ¿ì
	int tmp_num = num;
	
	while (1) {
		for (int i = 0; i < N; i++) {
			if (tmp_num % 10 == cards[i]) {
				tmp_num /= 10;
				if (tmp_num == 0) return 0;
				break;
			}
			if (i == N - 1) tmp_num = -1;
		}
		if (tmp_num < 0) break;
	}

	//°ö¼À Ä«µå ¾²´Â °æ¿ì 
	int min_val = INF;
	for (int i = 2; i <=sqrt(num) ; i++) {
		if (dp[i] != 0) continue;
		if (num%i == 0 && dp[num / i] != -1)
			min_val = min(min_val, dp[i] + dp[num/i] + 1);	
	}
	if (min_val == INF) min_val = -1;
	return min_val;
}

int main(int argc, char * argv[]) {
	int T;
	scanf("%d", &T);

	int card;
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &card);
			cards.push_back(card);
		}

		int M;
		scanf("%d", &M);
		vector<int> query(M);
	
		int max_query = 0;
		for(int i=0; i<M; i++) {
			scanf("%d", &query[i]);
			if (query[i] > max_query) max_query = query[i];
		}

		dp.resize(max_query+1, -1);

		for (int i = 0; i < N; i++)
			dp[cards[i]] = 0;
		
		for (int i = 4; i <= max_query; i++) {
			if (dp[i] != -1) continue;
			dp[i] = findMinCard(i);
		}
		for (int i = 0; i < M; i++) {
			printf("%d\n", dp[query[i]]);
		}
		cards.clear(); dp.clear();
	}

	return 0;
}