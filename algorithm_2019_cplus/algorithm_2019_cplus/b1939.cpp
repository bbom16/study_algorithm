// 2019.07.14
// boj 1939
// 중량제한
// bfs, binary search -> binary search로 구한 중량값이 다리를 지나갈 수 있는지 bfs로 확인한다!!  

#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int> > > bridge; //first: 연결된 섬, second : 중량제한
vector<bool> visit;
vector<int> weights;

int start, destination, N, M;

bool bfs(int weight) {
	queue<int> que;
	visit[start] = true;
	que.push(start);

	while (!que.empty()) {
		int current = que.front();
		que.pop();
	
		if (destination == current) 
			return true;
		
		for (int i = 0; i < bridge[current].size(); i++) {
			if (visit[bridge[current][i].first] || bridge[current][i].second < weight) continue;
			que.push(bridge[current][i].first);
			visit[bridge[current][i].first] = true;
		}
	}
	return false;
}

int binary_search() {
	int mid, low = 0, high = weights.size() - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		visit.resize(N + 1, false);
		if (bfs(weights[mid])) low = mid + 1;
		else high = mid - 1;
		visit.clear();
	}
	return high;
}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &M);

	bridge.resize(N + 1);

	int i1, i2, w;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &i1, &i2, &w);
		bridge[i1].push_back(make_pair(i2, w));
		bridge[i2].push_back(make_pair(i1, w));
		weights.push_back(w);
	}
	
	scanf("%d %d", &start, &destination);
	sort(weights.begin(), weights.end());
	int max_index = binary_search();
	printf("%d\n", weights[max_index]);

	return 0;
}