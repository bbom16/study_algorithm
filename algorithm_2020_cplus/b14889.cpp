//2020.02.07
//boj 14889
//스타트와 링크
//브루트포스 
//재귀를 이용한 완전탐색 

#define INFINITE_VALUE 999999
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ability[21][21];
bool belong_start[21];
int start_abili, link_abili;
int min_val = INFINITE_VALUE;
vector<int> start_team, link_team;

/* 능력치 더해서 두 팀의 최소 능력치 구하기 */
void sum_abliity() {
	/* 팀의 능력치 더하기 */
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			start_abili += (ability[start_team[i]][start_team[j]] + ability[start_team[j]][start_team[i]]);
			link_abili += (ability[link_team[i]][link_team[j]] + ability[link_team[j]][link_team[i]]);
		}
	}
	/* 최솟값 구하기 */
	min_val = min(min_val, abs(start_abili - link_abili));
	start_abili = 0, link_abili = 0;
}

/* 팀 나누기 */
void solve(int x) {
	start_team.push_back(x);
	belong_start[x] = true;

	/* start 팀이 다 나눠진 경우 */
	if (start_team.size() == N / 2) {
		/* link 팀 구하기 */
		for (int i = 0; i < N; i++) {
			if (!belong_start[i])
				link_team.push_back(i);
			if (link_team.size() == N / 2)
				break;
		}
		/* 최소값 구하고 return */
		sum_abliity();
		start_team.pop_back();
		belong_start[x] = false;
		link_team.clear();
		return;
	}
	/* 아직 팀이 나눠지지 않아 팀을 더 나눔 */
	for (int i = x + 1; i < N; i++)
		solve(i);
	start_team.pop_back();
	belong_start[x] = false;
}

int main(int argc, char * argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &ability[i][j]);
	}

	solve(0);
	printf("%d\n", min_val);

	return 0;
}