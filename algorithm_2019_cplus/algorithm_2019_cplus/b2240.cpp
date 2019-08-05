//2019.08.04
//boj 2240
//�ڵ� ����
//���̳��� ���α׷�

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][31][3]; // dp[��][�̵�Ƚ��][����]

int main(int argc, char * argv[]) {
	int T, W;
	scanf("%d %d", &T, &W);

	int plumTree, maxPlums = 0;
	for (int i = 1; i <= T; i++) {
		scanf("%d", &plumTree);
		int otherTree = plumTree % 2  + 1; 
		for (int j = 0; j <= i; j++) {
			/* �ѹ��� �������� ������ ������ 1�� ����*/
			if (j == 0){
				if(plumTree == 1)
					dp[i][j][plumTree] = dp[i - 1][j][plumTree] + 1;
				maxPlums = max(maxPlums, dp[i][j][plumTree]);
				continue;
			}
			if (j > W) continue;
			if ((plumTree == 1 && j % 2 == 0) || (plumTree == 2 && j % 2 == 1)) {
				dp[i][j][plumTree] = max(dp[i - 1][j - 1][otherTree], dp[i - 1][j][plumTree]) + 1;
				maxPlums = max(maxPlums, dp[i][j][plumTree]);
				dp[i][j][otherTree] = dp[i-1][j][otherTree];
			}
			else 
				dp[i][j][otherTree] = dp[i-1][j][otherTree];
		}
	}

	printf("%d\n", maxPlums);
	return 0;
}

