// [최단경로, 플로이드워셜] 미래도시

#include <stdio.h>

#define INF 1000000000
#define MAX 101

int graph[MAX][MAX];

int main() {
    int n, m;
    scanf_s ("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf_s("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int x, k;
    scanf_s("%d %d", &x, &k);

    for (int via = 1; via <= n; via++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                if (graph[start][end] > graph[start][via] + graph[via][end]) {
                    graph[start][end] = graph[start][via] + graph[via][end];
                }
            }
        }
    }

    int distance = graph[1][k] + graph[k][x];

    if (graph[1][k] >= INF || graph[k][x] >= INF) {
        printf("-1\n");
    }
    else {
        printf("%d\n", distance);
    }

    return 0;
}