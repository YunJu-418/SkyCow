// [정렬] 두 배열의 원소 교체

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, K;
    scanf_s("%d %d", &N, &K);

    int A[100000];
    int B[100000];

    for (int i = 0; i < N; i++) {
        scanf_s("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf_s("%d", &B[i]);
    }

    qsort(A, N, sizeof(int), asc);
    qsort(B, N, sizeof(int), desc);

    for (int i = 0; i < K; i++) {
        if (A[i] < B[i]) {
            int temp = A[i];
            A[i] = B[i];
            B[i] = temp;
        }
        else {
            break;
        }
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    printf("%lld\n", sum);

    return 0;
}