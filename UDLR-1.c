// 2025004261 ±èÀ±ÁÖ
// [±¸Çö] »óÇÏÁÂ¿ì

#include <stdio.h>

int main(void) {
    int n;
    int x = 1, y = 1;
    int ch;

    scanf_s("%d", &n);

    while ((ch = getchar()) != '\n' && ch != EOF);

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == 'L' && y > 1) y--;
        else if (ch == 'R' && y < n) y++;
        else if (ch == 'U' && x > 1) x--;
        else if (ch == 'D' && x < n) x++;
    }

    printf("%d %d\n", x, y);
    return 0;
}