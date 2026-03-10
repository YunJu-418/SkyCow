// [¿Ã¡¯≈Ωªˆ] ∂±∫∫¿Ã ∂± ∏∏µÈ±‚

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    long long M;

    scanf("%d %lld", &N, &M);

    long long* arr = (long long*)malloc(sizeof(long long) * N);
    if (arr == NULL) {
        return 1;
    }

    long long max = 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    long long left = 0;
    long long right = max;
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] > mid)
                sum += arr[i] - mid;
        }

        if (sum >= M) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%lld\n", answer);

    free(arr);
    return 0;
}