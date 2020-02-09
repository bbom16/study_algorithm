//2020.02.07
//boj 14889
//��ŸƮ�� ��ũ
//���Ʈ���� 
//��͸� �̿��� ����Ž�� 

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

/* �ɷ�ġ ���ؼ� �� ���� �ּ� �ɷ�ġ ���ϱ� */
void sum_abliity() {
	/* ���� �ɷ�ġ ���ϱ� */
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			start_abili += (ability[start_team[i]][start_team[j]] + ability[start_team[j]][start_team[i]]);
			link_abili += (ability[link_team[i]][link_team[j]] + ability[link_team[j]][link_team[i]]);
		}
	}
	/* �ּڰ� ���ϱ� */
	min_val = min(min_val, abs(start_abili - link_abili));
	start_abili = 0, link_abili = 0;
}

/* �� ������ */
void solve(int x) {
	start_team.push_back(x);
	belong_start[x] = true;

	/* start ���� �� ������ ��� */
	if (start_team.size() == N / 2) {
		/* link �� ���ϱ� */
		for (int i = 0; i < N; i++) {
			if (!belong_start[i])
				link_team.push_back(i);
			if (link_team.size() == N / 2)
				break;
		}
		/* �ּҰ� ���ϰ� return */
		sum_abliity();
		start_team.pop_back();
		belong_start[x] = false;
		link_team.clear();
		return;
	}
	/* ���� ���� �������� �ʾ� ���� �� ���� */
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