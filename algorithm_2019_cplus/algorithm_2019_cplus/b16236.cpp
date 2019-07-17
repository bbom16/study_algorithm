// 2019.07.16
// boj 16236
// 아기 상어
// bfs 문제 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct fish {
	int distance;
	int y;
	int x;

	bool operator < (const fish &f) const {
		if (distance == f.distance) {
			if (y == f.y) return x > f.x;
			else return y > f.y;
		}
		else return distance > f.distance;
	}
};


int dx[] = { 0,-1,0,1 }; //좌우
int dy[] = { -1,0,1,0 }; //상하
int ocean[21][21];
int N, weight, eating_fish;

int bfs (int x, int y) {
	priority_queue<fish> pq;
	fish f = { 0,y,x };
	pq.push(f);
	ocean[y][x] = 0;

	vector<vector<bool> > visited;
	visited.resize(N + 1);
	for (int i = 0; i <= N; i++)
		visited[i].resize(N + 1);

	visited[y][x] = true;

	int total_time = 0;
	while(!pq.empty()){
		int y = pq.top().y;
		int x = pq.top().x;
		int d = pq.top().distance;
		pq.pop();

		// 물고기 찾은 경우
		if (ocean[y][x] > 0 && ocean[y][x] < weight) {
			eating_fish++;
			ocean[y][x] = 0;
			total_time += d;
			d = 0;
			if (eating_fish == weight) {
				eating_fish = 0;
				weight++;
			}
			visited.clear();
			visited.resize(N + 1);
			for (int i = 0; i <= N; i++)
				visited[i].resize(N + 1);

			visited[y][x] = true;
			while (!pq.empty())
				pq.pop();
		}
		
		int next_x, next_y;
		for (int i = 0; i < 4; i++) {
			next_x = x + dx[i];
			next_y = y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
			if (visited[next_y][next_x] || weight < ocean[next_y][next_x]) continue;
			f = { d + 1, next_y, next_x };
			pq.push(f);
			visited[next_y][next_x] = true;
		}
	}
	return total_time;
}


int main(int argc, char * argv[]) {
	scanf("%d", &N);

	int start_x, start_y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &ocean[i][j]);
			if (ocean[i][j] == 9) {
				start_x = j;
				start_y = i;
			}
		}
	}

	weight = 2;
	printf("%d\n", bfs(start_x, start_y));

	return 0;
}