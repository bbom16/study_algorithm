//2019.10.04
//boj 10974
//��� ����
//���� next_permutation �̿�

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(int agrc, char * argv[]) {
	int N;
	scanf("%d", &N);

	vector<int> num;
	for (int i = 0; i < N; i++) 
		num.push_back(i+1);

	while (1) {
		for (int i = 0; i < N; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		if (!next_permutation(num.begin(), num.end()))
			break;
	}
	
	return 0;
}