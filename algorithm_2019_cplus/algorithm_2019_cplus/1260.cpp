//
//  1260.cpp
//  algorithm_2019_cplus
//
//  Created by bomin jung on 2019. 3. 4..
//  Copyright © 2019년 bomin jung. All rights reserved.
//  1260 dfs & bfs

#include <iostream>
#include <queue>
using namespace std;

queue<int> answer;
queue<int> bfs_path;

int N,M,V;
int edge[1001][1001];
bool visit[1001];

void DFS(int v)
{
    answer.push(v);
    for(int i=1; i<=N; i++){
        if(edge[v][i] && !visit[i]){
            visit[i] = true;
            DFS(i);
        }
    }
}

void BFS(int v)
{
    answer.push(v);
    for(int i=1; i<=N; i++){
        if(edge[v][i] && !visit[i]){
            bfs_path.push(i);
            visit[i] = true;
        }
    }
    if(!bfs_path.empty()){
        int next = bfs_path.front();
        bfs_path.pop();
        BFS(next);
    }
}

int main(int argc, char * argv[])
{
    int i,v1,v2;
    cin >> N >> M >> V;
    
    for(i=0; i<M; i++){
        cin >> v1 >> v2;
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }
    /*--------- dfs ---------------*/
    visit[V] = true;
    DFS(V);
    while(!answer.empty()) {
        cout << answer.front() << " ";
        answer.pop();
    }
    cout << endl;
    /*--------- dfs ---------------*/
    /*--------- bfs ---------------*/
    for(i=0; i<=N; i++)
        visit[i] = false;
    visit[V] = true;
    BFS(V);
    while(!answer.empty()) {
        cout << answer.front() << " ";
        answer.pop();
    }
    cout << endl;
    
    return 0;
}
