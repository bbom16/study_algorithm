//2020.01.16 -> 2020.02.01
//boj 3190
//��
//linked list�� ������ �ذ� 
//�տ� ����� ��ġ�� �״�� �̵��ϴ� ������� ���� �ذ� 

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//direction ����, ��/����
typedef struct direction_info {
	int second;
	char direction;
}DI;

//x,y ��ǥ 
typedef struct location {
	int x;
	int y;
}LC;

//����, ����, ���� ��ǥ
struct SB {
	SB *previous_body;
	SB *next_body;
	LC current;
};

//��ü �� ���� 
typedef struct snake_info {
	int len;
	SB* head;
	SB* tail;
}SI;

int N,K,L;
vector<vector<int> > map;
vector<DI> direction_vector;

int answer = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

//���� ��ȯ ����(0:L, 1:R)�� �̵�
int changing_direction[4][2] = {
	{3,2}, {2,3}, {0,1}, {1,0}
};

bool chk_range(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > N)
		return false;
	return true;
}

void play_game(int t, int d, SI s) {
	
	int next_x = s.head->current.x + dx[d];
	int next_y = s.head->current.y + dy[d];

	/* ���� ���� */
	if (!chk_range(next_x, next_y)) {
		answer = t;
		return;
	}
	
	/* ��� ���� ��� */
	if (map[next_x][next_y] == 1) {
		map[next_x][next_y] = 2;
		s.len++;
		SB *new_head = new SB;
		new_head->previous_body = NULL;
		new_head->current = { next_x, next_y };
		s.head->previous_body = new_head;
		new_head->next_body = s.head;
		s.head = new_head;
	}
	/* ���� �ε��� ��� */
	else if (map[next_x][next_y] == 2) {
		answer = t;
		return;
	}
	/* �ƹ� �̺�Ʈ�� �Ͼ�� ���� ��� */
	else {
		/* �Ӹ� �� ������ �̵� */
		map[s.tail->previous_body->current.x][s.tail->previous_body->current.y] = 0;
		SB* current_body = s.tail;
		while (current_body != s.head) {
			current_body->current = current_body->previous_body->current;
			current_body = current_body->previous_body;
		}
		/* �Ӹ� �̵� */
		s.head->current = { next_x, next_y };
		map[next_x][next_y] = 2;
	}
	/* ���� ��ȯ */
	int next_d = d;
	if (!direction_vector.empty() && direction_vector[0].second == t) {
		char changed_d = direction_vector[0].direction;
		if (changed_d == 'L')
			next_d = changing_direction[d][0];
		else
			next_d = changing_direction[d][1];

		direction_vector.erase(direction_vector.begin());
	}

	play_game(t + 1, next_d, s);
}

int main(int argc, char * argv[]) {
	scanf("%d %d", &N, &K);

	map.resize(N + 2);
	for (int i = 0; i < N + 1; i++)
		map[i].resize(N + 2);

	int apple_x, apple_y;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &apple_x, &apple_y);
		map[apple_x][apple_y] = 1;
	}

	scanf("%d", &L);

	DI input_di;
	SB* head = new SB;
	SB* tail = new SB;

	head->current = { 1,1 };
	tail->current = { 1,1 };
	tail->previous_body = head;
	head->next_body = tail;
	head->previous_body = NULL;
	tail->next_body = NULL;

	SI snake = { 1, head, tail };

	for (int i = 0; i < L; i++) {
		scanf("%d %c", &input_di.second, &input_di.direction);
		direction_vector.push_back(input_di);
	}
	
	map[1][1] = 2;
	play_game(1, 0, snake);

	printf("%d\n", answer);

	return 0;
}