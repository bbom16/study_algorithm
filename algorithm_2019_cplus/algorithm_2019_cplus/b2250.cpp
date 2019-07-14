// 2019.07.11
// boj 2250
// 트리의 높이와 너비
// tree 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef struct node_info {
	int parent;
	int left_child;
	int right_child;
	int level;
	int x;
}NODE;

NODE node[100001];
bool child[100001];	//내가 누군가에 자식인지 확인(누구에 자식도 아니면 root)
vector<pair<int,int> > level; //first : 최소, second : 최대
int current_x = 1;

/* dfs를 이용해 열번호 찾기 -> 제일 왼쪽 자식부터 차례대로 1씩 증가시키면서 열변호 줌 */
void find_x(int node_num) {
	int left_child = node[node_num].left_child;
	int right_child = node[node_num].right_child;

	if (left_child == -1)
		node[node_num].x = current_x++;
		
	else {
		node[left_child].level = node[node_num].level + 1;
		find_x(left_child);
		node[node_num].x = current_x++;
	}

	// level 별 최대 최소 찾기
	if (level[node[node_num].level].first > node[node_num].x || level[node[node_num].level].first == 0)
		level[node[node_num].level].first = node[node_num].x;
	if (level[node[node_num].level].second < node[node_num].x)
		level[node[node_num].level].second = node[node_num].x;

	if (right_child == -1) return;
	node[right_child].level = node[node_num].level + 1;
	find_x(right_child);
}

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);

	level.resize(N + 1);
	int node_num, left, right;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &node_num, &left, &right);
		node[node_num].left_child = left;
		node[node_num].right_child = right;
		if (left != -1) {
			node[left].parent = node_num;
			child[left] = true;
		}
		if (right != -1) {
			node[right].parent = node_num;
			child[right] = true;
		}
	}

	/* root 찾기 */
	int root;
	for (int i = 1; i <= N; i++) {
		if (child[i] == false) {
			root = i;
			node[root].level = 1;
			break;
		}
	}

	find_x(root);

	int max_width = 0, max_level = 0;
	for (int i = 1; i < N + 1; i++) {
		if (level[i].first == 0) break;
		if (max_width < level[i].second - level[i].first + 1) {
			max_width = level[i].second - level[i].first + 1;
			max_level = i;
		}
	}

	printf("%d %d\n", max_level, max_width);
	return 0;
}