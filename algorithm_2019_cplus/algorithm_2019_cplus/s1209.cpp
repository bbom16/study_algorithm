// 2019.08.24
// samsung 1209
// sum
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[101][101];

int max_sum() {
	int max_row = 0;
	int max_col = 0;
	int row_sum = 0, col_sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			col_sum += arr[i][j];
			row_sum += arr[j][i];
		}
		max_row = max(max_row, row_sum);
		max_col = max(max_col, col_sum);
		row_sum = 0; col_sum = 0;
	}

	int x = 0, y = 0, z = 99;
	int sum_dia_left = 0, sum_dia_right = 0, max_dia = 0;
	while (1) {
		sum_dia_left += arr[x][y++];
		sum_dia_right += arr[x++][z--];
		if (x == 100) {
			max_dia = (sum_dia_left, sum_dia_right);
			break;
		}
	}
	return max(max(max_col, max_row), max_dia);
}
int main(int argc, char * argv[]) {
	
	while (1) {
		int T;
		scanf("%d", &T);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
	
		printf("#%d %d", T, max_sum());
		if (T == 10) break;
	}
	return 0;
}