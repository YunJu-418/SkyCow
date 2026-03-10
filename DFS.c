// [DFS] 음료수 얼려 먹기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000

int n, m;
char graph[MAX][MAX + 1];
int visited[MAX][MAX];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y)
{
    int i;
    int nx, ny;

    visited[x][y] = 1;

    for (i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (graph[nx][ny] == '0' && visited[nx][ny] == 0)
            {
                dfs(nx, ny);
            }
        }
    }
}

int main(void)
{
    int i, j;
    int count = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%s", graph[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (graph[i][j] == '0' && visited[i][j] == 0)
            {
                dfs(i, j);
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}