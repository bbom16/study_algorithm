//2019.08.26
//baekjoon 17136
//색종이 붙이기 
//백트래킹. 틀렸던 이유는 size구해주는 부분에서 초기화가 안됐다. 초기화 필수,,

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int paper[11][11];
int colorPaper[6]; //각각 5장씩 0은 전체 종이 수 
int minColorPaper = 25;

vector<pair<int, int> > paperLocation;


int findPaperSize(int x, int y) {
	int cnt = 0;
	bool chk = false;
	for (int s = 5; s > 0; s--) {
		cnt = 0;
		chk = false;
		for (int i = x; i < x + s; i++) {
			if (i >= 10) break;
			for (int j = y; j < y + s; j++) {
				if (j >= 10) break;
				if (paper[i][j] != 1) {
					chk = true;
					break;
				}
				cnt++;
			}
			if (chk) {
				break;
			}
		}
		if (cnt == s*s) {
			return s;
		}
	}
}

void putColorPaper(int x, int y, int s, int idx) {
	colorPaper[s]++;
	colorPaper[0]++;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (paper[i][j] == 1) {
				paper[i][j] = idx + 2;
			}
		}
	}
}

void takeColorPaper(int x, int y, int s, int idx) {
	colorPaper[s]--;
	colorPaper[0]--;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (paper[i][j] == idx + 2) {
				paper[i][j] = 1;
			}
		}
	}
}

void findPaper(int idx) {
	if (idx >= paperLocation.size())
		return;

	if (colorPaper[0] >= minColorPaper)
		return;

	int x = paperLocation[idx].first;
	int y = paperLocation[idx].second;

	if (paper[x][y] != 1) {
		findPaper(idx + 1);
		if (idx == paperLocation.size() - 1) {
			minColorPaper = min(minColorPaper, colorPaper[0]);
		}
	}

	else {
		int paperSize = findPaperSize(x, y);

		for (int s = paperSize; s > 0; s--) {
			if (colorPaper[s] >= 5) {
				continue;
			}
			putColorPaper(x, y, s, idx);
			findPaper(idx + 1);
			if (idx == paperLocation.size() - 1) {
				minColorPaper = min(minColorPaper, colorPaper[0]);
			}
			takeColorPaper(x, y, s, idx);
		}
	}
}

int main(int argc, char * argv[]) {

	int idx = -1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &paper[i][j]);
			if (paper[i][j]) {
				paperLocation.push_back(make_pair(i, j));
				idx++;
			}
		}
	}

	if (idx == -1) {
		minColorPaper = 0;
	}
	else {
		findPaper(0);
		if (minColorPaper == 25) {
			minColorPaper = -1;
		}
	}

	printf("%d\n", minColorPaper);

	return 0;
}