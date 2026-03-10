// [동적계획법] 메모이제이션을 사용한 피보나치 수열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long d[91];

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;

    d[1] = 0;
    d[2] = 1;

    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    if (n >= 1 && n <= 90) {
        printf("%lld\n", d[n]);
    }

    return 0;
}
