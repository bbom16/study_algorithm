// 2019.07.09
// samsung 1824
// 혁진이의 프로그램 검증
// 구현 , dfs 이용, 재귀 돌리면서 무한루프 돌지않게 체크!!(스택오버플로우 힘들었다ㅜㅜ)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char hackssem[21][21];
vector<vector<vector<vector<bool> > > > memory_check_arr; //[y][x][direct][num_memory] = true/false;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int num_memory;
int R, C;
bool exit_function; 

bool processing(int x, int y, int direct) {
	if (exit_function) return false;
	char order = hackssem[y][x];
	
	int next_x = x, next_y = y;
	switch (order)
	{
	case '<':
		direct = 3;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '>':
		direct = 2;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '^':
		direct = 1;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case 'v':
		direct = 0;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '_':
		if (num_memory == 0) direct = 2;
		else direct = 3;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '|':
		if (num_memory == 0) direct = 0;
		else direct = 1;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '?':
		direct = 4;
		break;
	case '.':
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '@':
		return true;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		num_memory = order - '0';
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '+':
		if (num_memory == 15)
			num_memory = -1;
		num_memory++;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	case '-':
		if (num_memory == 0)
			num_memory = 16;
		num_memory--;
		next_x = x + dx[direct];
		next_y = y + dy[direct];
		break;
	default:
		break;
	}
	if (memory_check_arr[y][x][direct][num_memory]) {
		exit_function = true;
		return false;
	}
	memory_check_arr[y][x][direct][num_memory] = true;

	/* ?인 경우 swith문 안에서 확인할 경우 중복 체크가 제대로 되지않아 밖에서 처리 */
	if (direct == 4) {
		for (int i = 0; i < 4; i++) {
			next_x = x + dx[i];
			next_y = y + dy[i];

			/* 범위 체크 */
			if (next_x < 0) next_x = C - 1;
			if (next_x >= C) next_x = 0;
			if (next_y < 0) next_y = R - 1;
			if (next_y >= R) next_y = 0;

			if(processing(next_x, next_y, i)) return true;
			exit_function = false;
		}
		exit_function = false;
		return false;
	}

	/* 범위 체크 */
	if (next_x < 0) next_x = C - 1;
	if (next_x >= C) next_x = 0;
	if (next_y < 0) next_y = R - 1;
	if (next_y >= R) next_y = 0;

	return processing(next_x, next_y, direct);
}

int main(int argc, char * argv[]) {
	int T;
	scanf("%d", &T);

	
	for (int t = 1; t <= T; t++) {
		bool check_a = false;

		scanf("%d %d", &R, &C);
		getchar();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf("%c", &hackssem[i][j]);
				if (hackssem[i][j] == '@') check_a = true;
			}
			getchar();
		}

		if (!check_a) {
			cout << '#' << t << " " << "NO" << endl;
			continue;
		}
		/* vector 공간 할당 */
		memory_check_arr.reserve(R);
		for (int i = 0; i < R; i++) {
			memory_check_arr[i].reserve(C);
			for (int j = 0; j < C; j++) {
				memory_check_arr[i][j].reserve(5);
				for (int k = 0; k < 5; k++)
					memory_check_arr[i][j][k].resize(16, false);
			}
		}
		string answer;

		if (processing(0, 0, 2)) answer = "YES";
		else answer = "NO";

		cout << '#' << t << " " << answer << endl;
		memory_check_arr.clear();
		num_memory = 0; exit_function = false;

	}
	return 0;
}