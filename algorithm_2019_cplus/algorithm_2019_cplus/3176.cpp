// 2019.07.06
// baeckjoon 3176
// ���γ�Ʈ��ũ
// LCA, ���� �ϳ��� ���ؼ� �����ָ� �ð��ʰ�,,,,�̤̤̤̤̤̤̤̤� 
// 2^k��° ���� ������ �����ؼ� ���������� ���� �����ִ°� ���̰� ���� �� ���� 

#define INF 9999999
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int> > >load_info;
vector<vector<int > > parents; //parents[node][i] -> node���� i��° ���� 
vector < vector<int > > min_distances, max_distances; //min_distances[node][i] -> node���� i��° ������� �Ÿ� �� �ּڰ�
vector<int> depths;
bool visit[100001];
int max_dis = 0, min_dis = INF;

/* 2^n��° ���� ���� ���� -> ������ n��° ������ ����!!(���) */
void find_ancestor(int node, int parent, int n) {
	if (n >= parents[parent].size()) return;
	int next_parent = parents[parent][n];
	parents[node].push_back(parents[parent][n]);
	max_distances[node].push_back(max(max_distances[node][n], max_distances[parent][n]));
	min_distances[node].push_back(min(min_distances[node][n], min_distances[parent][n]));
	find_ancestor(node, next_parent, n + 1);
}

/* dfs ���鼭 tree ���� */
void dfs(int node, int depth) {
	visit[node] = true;
	depths[node] = depth;

	for (int i = 0; i < load_info[node].size(); i++) {
		int child = load_info[node][i].first;
		int distance = load_info[node][i].second;
		if (visit[child]) continue;
		parents[child].push_back(node);
		max_distances[child].push_back(distance);
		min_distances[child].push_back(distance);
		find_ancestor(child, node, 0);
		dfs(child, depth + 1);
	}
}

/* ���� �θ� ã�� & �ִ�, �ּ� ���� ã�� */
void LCA(int n1, int n2) {
	if (depths[n1] < depths[n2]) swap(n1, n2);
	int max_depth = parents[n1].size() - 1;

	// ���� �����ֱ� 
	for (int i = max_depth; i >= 0; i--) {
		if (i >= parents[n1].size()) continue;
		if (depths[n2] <= depths[parents[n1][i]]) {
			max_dis = max(max_dis, max_distances[n1][i]);
			min_dis = min(min_dis, min_distances[n1][i]);
			n1 = parents[n1][i];
		}
	}

	if (n1 == n2) return;
	
	for(int i=max_depth; i>=0; i--){
		if (i >= parents[n1].size() || i >= parents[n2].size()) continue;
		if (parents[n1][i] != parents[n2][i]) {
			max_dis = max(max_dis, max(max_distances[n1][i], max_distances[n2][i]));
			min_dis = min(min_dis, min(min_distances[n1][i], min_distances[n2][i]));
			n1 = parents[n1][i];
			n2 = parents[n2][i];
		}
	}

	max_dis = max(max_dis, max(max_distances[n1][0], max_distances[n2][0]));
	min_dis = min(min_dis, min(min_distances[n1][0], min_distances[n2][0]));
}

int main(int argc, char * argv[]) {
	int N, A, B, C;
	scanf("%d", &N);

	load_info.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &A, &B, &C);
		load_info[A].push_back(make_pair(B, C));
		load_info[B].push_back(make_pair(A, C));
	}

	parents.resize(N + 1); depths.resize(N + 1);
	max_distances.resize(N + 1); min_distances.resize(N + 1);

	dfs(1, 1);

	int K, D, E;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &D, &E);
		LCA(D, E);
		printf("%d %d\n", min_dis, max_dis);
		min_dis = INF; max_dis = 0;
	}

	return 0;
}