// [BFS] πÃ∑Œ ≈ª√‚

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N, M;
int maze[201][201];
int visited[201][201];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

typedef struct {
    int x;
    int y;
} Node;

Node queue[40001];
int front = 0, rear = 0;

void bfs() {
    queue[rear++] = (Node){ 0, 0 };
    visited[0][0] = 1;

    while (front < rear) {
        Node cur = queue[front++];
        int x = cur.x;
        int y = cur.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (maze[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    queue[rear++] = (Node){ nx, ny };
                }
            }
        }
    }
}

int main() {
    scanf_s("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf_s("%1d", &maze[i][j]);
        }
    }

    bfs();

    printf("%d\n", visited[N - 1][M - 1]);

    return 0;
}